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