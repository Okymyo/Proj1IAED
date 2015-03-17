#include "network.h"

void network_init(Network *network){
	network->banksNum = 0;
	network->banks = NULL;
}

void network_addBank(Network *network, char *name, char rating, int reference) {
	/* We should definitely check whether we receive a NULL pointer or not.
	However, we can't really handle this. If it throws OOM, nothing we can do.
	Might as well let it throw a segmentation fault, at least it's meaningful */
	if(network_bankByReference(network, reference) == NULL){
		Bank *bank = malloc(sizeof(Bank));
		bank_init(bank, name, rating, reference);
		/* Same thing here as was said above */
		network->banks = realloc(network->banks, sizeof(Bank*)*(network->banksNum + 1));
		network->banks[network->banksNum] = bank;
		network->banksNum++;
        return;
	}
    printf("ERROR! Reference is already being used.\n");
}

void network_list(Network *network, int type){
	int i;
	switch(type){
		case 0:{
			for (i = 0; i < network->banksNum; i++){
				Bank *bank = network->banks[i];
				printf("Bank -> Referencia:%d, Nome:%s, Rating:%d\n", 
					bank->reference, 
					bank->name, 
					bank->rating
				);
			}
			break;
		}
		case 1:{
			for (i = 0; i < network->banksNum; i++){
				Bank *bank = network->banks[i];
				printf("Bank -> Referencia:%d, Nome:%s, Rating:%d, Emprestimos recebidos:%d, Emprestimos feitos: %d, Emprestamos:%d dos quais %d sao a bancos maus, Recebemos:%d dos quais %d sao de bancos maus.\n", 
					bank->reference, 
					bank->name, 
					bank->rating,
					network_loaners(network, bank),
					bank_loansNum(bank),
					bank_totalLoaned(bank, 0),
					bank_totalLoaned(bank, 1),
					network_totalLoaned(network, bank, 0),
					network_totalLoaned(network, bank, 1)
				);
			}
			break;
		}
		case 2:{

		}
		default:{

		}
	}
}

Bank* network_bank(Network *network, int id) {
	return network->banks[id];
}

Bank* network_bankByReference(Network *network, int reference) {
	int i;
	for (i = 0; i < network->banksNum; i++){
		Bank *bank = network->banks[i];
		if(bank_reference(bank) == reference)
			return bank;
	}
	return NULL;
}

int network_partners(Network *network, Bank *bank) {
	int i, j, total = 0;
	for (i = 0; i < network->banksNum; i++){
		Bank *currentBank = network->banks[i];
		for (j = 0; j < currentBank->loansNum; j++){
			Loan *currentLoan = &currentBank->loans[j];
			if(currentLoan->loanee == bank){
				if(bank_loanByLoanee(bank, currentBank) == NULL) {
					total++;
				}
			}
		}
	}
	total+=bank->loansNum;
	return total;
}

int network_loaners(Network *network, Bank *bank){
	int i, j, total = 0;
	for (i = 0; i < network->banksNum; i++){
		Bank *currentBank = network->banks[i];
		for (j = 0; j < currentBank->loansNum; j++){
			Loan *currentLoan = &currentBank->loans[j];
			if(currentLoan->loanee == bank){
				total++;
			}
		}
	}
	return total;
}

int network_totalLoaned(Network *network, Bank *bank, int filter){
	int i, j, total = 0, totalFiltered = 0;
	for (i = 0; i < network->banksNum; i++){
		Bank *currentBank = network->banks[i];
		for (j = 0; j < currentBank->loansNum; j++){
			Loan *currentLoan = &currentBank->loans[j];
			if(currentLoan->loanee == bank){
				int amount = currentLoan->amount;
				if(filter && currentBank->rating == 0){
					totalFiltered += amount;
				}
				total += amount; 	
			}
		}
	}
	return filter ? totalFiltered : total;
}

int network_banksNum(Network *network) {
	return network->banksNum;
}

void network_terminate(Network *network) {
	int i;
	for (i = 0; i < network->banksNum; i++)
		bank_terminate(network->banks[i]);
		
	free(network->banks);
	free(network);
}