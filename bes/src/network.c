#include "network.h"

#define CACHESIZE 8

Network* network_new(){
	/* We should definitely check whether we receive a NULL pointer or not.
	However, we can't really handle this. If it throws OOM, nothing we can do.
	Might as well let it throw a segmentation fault, at least it's meaningful */
	Network *network = malloc(sizeof(Network));
	network->banksNum = 0;
	network->banks = NULL;
	network->refsCache = calloc(CACHESIZE, sizeof(Cache));
	network->bankRefs = NULL;
	return network;
}

void network_terminate(Network *network) {
	int i;
	for (i = 0; i < network->banksNum; i++)
		bank_terminate(network->banks[i]);
	free(network->banks);
	free(network->refsCache);
	free(network);
}

void network_addBank(Network *network, char *name, char rating, int reference) {
	if(network_bankByReference(network, reference) == NULL){
		Bank *bank = bank_new(name, rating, reference);
		/* We should definitely check whether we receive a NULL pointer or not.
		However, we can't really handle this. If it throws OOM, nothing we can do.
		Might as well let it throw a segmentation fault, at least it's meaningful */
		network->banks = realloc(network->banks, sizeof(Bank*)*(network->banksNum + 1));
		network->banks[network->banksNum] = bank;
		network->bankRefs = realloc(network->bankRefs, sizeof(int)*(network->banksNum + 1));
		network->bankRefs[network->banksNum] = reference;
		network->banksNum++;
		network_addToCache(network, reference, bank);
        return;
	}
	/* If it ever reaches this line, someone messed up, and it wasn't us */
    printf("ERROR! Reference is already being used.\n");
}

void network_killWorst(Network *network){
	int i, worstLoaned = 0;
	Bank *worst = NULL;
	for (i = network_banksNum(network)-1; i >= 0; i--){
		Bank *currentBank = network_bank(network, i);
		if(bank_rating(currentBank) == 1){
			int totalLoanedFiltered = bank_totalLoaned(currentBank, 1);
			if(totalLoanedFiltered > 0){
				if(worstLoaned < totalLoanedFiltered){
					worst = currentBank;
					worstLoaned = totalLoanedFiltered;
				}
			}
		}	
	}
	if(worst != NULL){
		bank_setRating(worst, 0);
		printf("*");
		network_printBankStatus(network, worst, 1);
	}
	network_printStatus(network);
}

void network_printStatus(Network *network){
	printf("%d %d\n", network_banksNum(network), network_countBanks(network, 1));
}

void network_printBankStatus(Network *network, Bank *bank, int type){
	switch(type){
		case 0:{
			printf("%d %s %d\n", 
				bank_reference(bank), 
				bank_name(bank), 
				bank_rating(bank)
			);
			break;
		}
		case 1:{
			printf("%d %s %d %d %d %d %d %d %d\n", 
				bank_reference(bank), 
				bank_name(bank), 
				bank_rating(bank),
				network_loaners(network, bank),
				bank_loansNum(bank),
				bank_totalLoaned(bank, 0),
				bank_totalLoaned(bank, 1),
				network_totalLoaned(network, bank, 0),
				network_totalLoaned(network, bank, 1)
			);
			break;
		}
	}
}

void network_listBanks(Network *network, int type){
	int i;
	switch(type){
		case 0:
		case 1:{
			for (i = 0; i < network_banksNum(network); i++){
				Bank *bank = network_bank(network, i);
				network_printBankStatus(network, bank, type);
			}
			break;
		}
		case 2:{
			int i, j, *histogram;
			/* Create the histogram where the index is the number of partners
			and contains the number of banks with that number of partners */
			histogram = calloc(network_banksNum(network), sizeof(int));
			for (j = 0; j < network_banksNum(network); j++){
				histogram[network_partners(network, network_bank(network, j))]++;
			}
			for (i = 0; i < network_banksNum(network); i++){
				if(histogram[i] != 0)
					printf("%d %d\n", i, histogram[i]);
			}
			free(histogram);
			break;
		}
		default:{
			printf("ERROR! Unhandled type of listing!\n");
		}
	}
}

int network_countBanks(Network *network, int rating){
	int i, count = 0;
	for (i = 0; i < network_banksNum(network); i++){
		Bank *currentBank = network_bank(network, i);
		if(bank_rating(currentBank) == rating)
			count++;
	}
	return count;
}

int network_partners(Network *network, Bank *bank) {
	int i, j, total = 0;
	for (i = 0; i < network_banksNum(network); i++){
		Bank *currentBank = network_bank(network, i);
		for (j = 0; j < bank_loansNum(currentBank); j++){
			Loan *currentLoan = bank_loan(currentBank, j);
			if(loan_loanee(currentLoan) == bank && bank_loanByLoanee(bank, currentBank) == NULL){
				total++;
			}
		}
	}
	total+=bank->loansNum;
	return total;
}

int network_loaners(Network *network, Bank *bank){
	int i, j, total = 0;
	for (i = 0; i < network_banksNum(network); i++){
		Bank *currentBank = network_bank(network, i);
		for (j = 0; j < bank_loansNum(currentBank); j++){
			Loan *currentLoan = bank_loan(currentBank, j);
			if(loan_loanee(currentLoan) == bank){
				total++;
			}
		}
	}
	return total;
}

int network_totalLoaned(Network *network, Bank *bank, int filter){
	int i, j, total = 0, totalFiltered = 0;
	for(i = 0; i < network_banksNum(network); i++){
		Bank *currentBank = network_bank(network, i);
		for (j = 0; j < bank_loansNum(currentBank); j++){
			Loan *currentLoan = bank_loan(currentBank, j);
			if(loan_loanee(currentLoan) == bank){
				int amount = loan_amount(currentLoan);
				if(filter && bank_rating(currentBank) == 0){
					totalFiltered += amount;
				}
				total += amount;
			}
		}
	}
	return filter ? totalFiltered : total;
}

Bank* network_bank(Network *network, int id) {
	return network->banks[id];
}

Bank* network_bankByReference(Network *network, int reference) {
	int i;
	Bank *bank = NULL;
	
	/* In come the magical properties of caches! */
	for (i = 0; i < CACHESIZE; i++){
		if (network->refsCache[i].value == reference){
			network->refsCache[i].uses++;
			return network->refsCache[i].bank;
		}
	}
	
	/* Our cache failed us */
	for (i = 0; i < network_banksNum(network); i++){
		if(network->bankRefs[i] == reference){
			bank = network_bank(network, i);
			break;
		}
	}
	
	/* Lets put that hard-earned value back into our cache */
	if (bank != NULL)
		network_addToCache(network, reference, bank);
	
	return bank;
}

int network_banksNum(Network *network) {
	return network->banksNum;
}

void network_addToCache(Network *network, int reference, Bank *bank){
	/* Why did we decide to use a cache?
	Odds are, if we just used a reference, we'll use it again
	We thought the CPU would automatically cache that. But it doesn't.
	So, we cache it ourselves! */
	int i, lowestUsesID = 0, lowestUses = network->refsCache[0].uses;
	for (i = 1; i < CACHESIZE; i++){
		if (network->refsCache[i].uses < lowestUses){
			lowestUses = network->refsCache[i].uses;
			lowestUsesID = i;
		}
	}
	network->refsCache[lowestUsesID].value = reference;
	network->refsCache[lowestUsesID].bank = bank;
	network->refsCache[lowestUsesID].uses = 1;
}