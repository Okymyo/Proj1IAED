#pragma once

#include "includes.h"
#include "bank.h"	

void network_init(Network *network);

void network_terminate(Network *network);

void network_addBank(Network *network, char *name, char rating, int reference);

void network_listBanks(Network *network, int type);

int network_partners(Network *network, Bank *bank);

int network_loaners(Network *network, Bank *bank);

int network_totalLoaned(Network *network, Bank *bank, int filter);

Bank* network_bank(Network *network, int id);

Bank* network_bankByReference(Network *network, int reference);

int network_banksNum(Network *network);
