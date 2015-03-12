#pragma once

#include "includes.h"
#include "bank.h"

typedef struct 
{
	int banksNum;
	Bank **banks;
} Network;	

void network_init(Network *network);

void network_addBank(Network *network, char *name, char rating, int reference);


Bank* network_bank(Network *network, int id);

Bank* network_bankByReference(Network *network, int reference);

int network_partners(Network *network, Bank *bank);

int network_banksNum(Network *network);

void network_terminate(Network *network);
