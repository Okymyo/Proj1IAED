#include "network.h"

void network_init(Network *network){
	network->banksNum = 0;
}

void network_addBank(Network *network, char *name, char rating, int reference){
	Bank *bank = calloc(1, sizeof(Bank));
	bank_init(bank, name, rating, reference);
	network = realloc(network->banks, sizeof(Bank)*(network->banksNum + 1));
	network->banks[network->banksNum] = bank;
	network->banksNum++;	
}