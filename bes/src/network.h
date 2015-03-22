#pragma once

#include "includes.h"
#include "bank.h"	

/*
* Creates a new network.
* @return A pointer of a new network.
*/
Network* network_new();

/*
* Terminates a network.
* @param network Network to be terminated.
*/
void network_terminate(Network *network);

/*
* Add a new bank to a network.
* @param network   Network to add a new bank to.
* @param name      Name of the new bank.
* @param rating    Rating of the new bank.
* @param reference Reference of the new bank.
*/
void network_addBank(Network *network, char *name, char rating, unsigned int reference);

/*
* Sets the rating of the worst good bank to bad.
* @param network Network to set the worst good bank to bad.
*/
void network_killWorst(Network *network);

/*
* Prints the current amount of banks spaced with the current amount of good banks.
* @param network Network to print the status of.
*/
void network_printStatus(Network *network);

/*
* Prints the status of a bank, over a network.
* @param network Network where the bank to print the status is.
* @param bank    Bank to print the status of.
* @param type    Type of status that we want to see, 0 for a simple status print, 1 for a more detailed view.
*/
void network_printBankStatus(Network *network, Bank *bank, int type);

/*
* Lists the view of a network.
* @param network Network to list the view of.
* @param type    Type of view that we want to print. 0 for a simple bank view, 1 for a more detailed bank view,
*   2 for a histogram that contains the amount of partners each bank has.
*/
void network_listBanks(Network *network, int type);

/*
* Counts the amount of banks with a given rating of a network.
* @param network Network to count the amount of banks with a given rating.
* @param rating  Rating of the banks to count.
* @return        Amount of banks with the given rating.
*/
int network_countBanks(Network *network, int rating);

/*
* Counts the amount of partners a banks has, over a network.
* @param network Network where the bank to count the partners is.
* @param bank    Bank to count the partners it has.
* @return        Amount of partners of the given bank.
*/
int network_partners(Network *network, Bank *bank);

/*
* Amount of loaners that loan to a bank, over a network.
* @param network Network where the bank to count the loaners is.
* @param bank    Bank to count the amount of loaners that loan to it.
* @return        Amount of loaners that loan to the given bank.
*/
int network_loaners(Network *network, Bank *bank);

/*
* Total amount of money loaned to a bank, over a network.
* @param network Network where the bank to count the amount loaned is.
* @param bank    Bank to count the amount loaned to it.
* @param filter  When > 1 will filter and only return the total amount loaned from banks with bad rating.
*/
int network_totalLoaned(Network *network, Bank *bank, int filter);

/*
* Gives a pointer of a bank with a given index.
* @param network Network to get the bank from.
* @param id      Index of the bank to fetch.
* @return        Pointer of the bank with the given index within a given network.
*/
Bank* network_bank(Network *network, int id);

/*
* Gives a pointer of a bank with a given reference.
* @param network   Network to get the bank from.
* @param reference Reference of the bank to fetch.
* @return          Pointer of the bank with the given reference within a given network.
*/
Bank* network_bankByReference(Network *network, unsigned int reference);

/*
* Gives the number of banks of a network.
* @param network Network to get the number of banks from.
* @return        Number of banks of the given network.
*/
int network_banksNum(Network *network);


void network_addToCache(RefCache *refsCache, unsigned int reference, Bank *bank);

void network_repositionInCache(RefCache *refsCache, int index);