#include "network.h"

void network_init(Network *network){
	network->banksNum = 0;
	network->banks = NULL;
}

void network_addBank(Network *network, char *name, char rating, int reference){
	Bank *bank = malloc(sizeof(Bank));
	bank_init(bank, name, rating, reference);
	network->banks = realloc(network->banks, sizeof(Bank*)*(network->banksNum + 1));
	network->banks[network->banksNum] = bank;
	network->banksNum++;	
}

Bank* network_bank(Network *network, int id){
	return network->banks[id];
}

Bank* network_bankByReference(Network *network, int reference){
	int i;
	for (i = 0; i < network->banksNum; i++){
		Bank *bank = network->banks[i];
		if(bank_reference(bank) == reference)
			return bank;
	}
	return NULL;
}

int network_partners(Network *network, Bank *bank){
	int i, j, total = 0;
	for (i = 0; i < network->banksNum; i++){
		Bank *currentBank = network->banks[i];
		for (j = 0; j < currentBank->loansNum; j++){
			Loan *currentLoan = &currentBank->loans[j];
			if(currentLoan->reference == bank->reference){
				if(bank_loanByReference(bank, bank_reference(currentBank)) 
					== NULL){
					total++;
				}
			}
		}
	}
	total+=bank->loansNum;
	return total;	
}

int network_banksNum(Network *network){
	return network->banksNum;
}

void network_terminate(Network *network)
{
	int i;
	for (i = 0; i < network->banksNum; i++)
	{
		/* Although loans might be a NULL pointer, it's ignored by free if that is the case */
		free(network->banks[i]->loans);
		free(network->banks[i]);
	}
	free(network->banks);
	free(network);
}