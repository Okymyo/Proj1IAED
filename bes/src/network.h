#pragma once

#include "includes.h"
#include "bank.h"	

void network_init(Network *network);

void network_addBank(Network *network, char *name, char rating, int reference);

void network_list(Network *network, int type);

Bank* network_bank(Network *network, int id);

Bank* network_bankByReference(Network *network, int reference);

int network_partners(Network *network, Bank *bank);

int network_loaners(Network *network, Bank *bank);

int network_totalLoaned(Network *network, Bank *bank, int filter);

int network_banksNum(Network *network);

void network_terminate(Network *network);
