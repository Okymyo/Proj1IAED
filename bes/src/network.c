#include "network.h"

void network_init(Network *network){
	network->banksNum = 0;
}

void network_addBank(Network *network, char *name, char rating, int reference){
	Bank bank;
	bank_init(&bank, name, rating, reference);
	network->banks[network->banksNum] = bank;
	network->banksNum++;	
}