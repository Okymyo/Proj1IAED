#pragma once

#include "includes.h"
#include "loan.h"

/*
* Creates a new bank.
* @param name      Name of the bank.
* @param rating    Rating of the bank.
* @param reference Reference of the bank.
* @return          Returns a pointer of a bank with all the given parameters.
*/
Bank* bank_new(char name[], char rating, unsigned int reference);

/*
* Terminates a bank.
* @param bank Bank to be terminated.
*/
void bank_terminate(Bank *bank);

/*
* Adds a loan to a bank.
* @param bank   Bank to add a loan to.
* @param loanee Bank that we loan to.
* @param amount Amount loaned.
*/
void bank_addLoan(Bank *bank, Bank *loanee, int amount);

/*
* Removes a loan from a bank.
* @param bank Bank to remove a loan from.
* @param loan Loan to be removed.
*/
void bank_removeLoan(Bank *bank, Loan *loan);

/*
* Gives the total amount loaned of a bank.
* @param bank   Bank to know the total amount loaned.
* @param filter When > 1 will filter and only return the total amount loaned to banks with bad rating.
* @return       The total amount loaned of the given bank.
*/
int bank_totalLoaned(Bank *bank, int filter);

/*
* Gives a pointer of a loan with a given index.
* @param bank Bank to get the loan from.
* @param id   Index of the loan to fetch.
* @return     Pointer of the loan with the given index within a given bank.
*/
Loan* bank_loan(Bank *bank, int id);

/*
* Gives a pointer of a loan with a given loanee.
* @param bank   Bank to get the loan from.
* @param loanee Loanee of the loan to fetch.
* @return       Pointer of the loan with the given loanee within a given bank.
*/
Loan* bank_loanByLoanee(Bank *bank, Bank *loanee);

/*
* Gives the name of a bank.
* @param bank Bank to get the name from.
* @return     Name of a given bank.
*/
char* bank_name(Bank *bank);

/*
* Sets the rating of a bank.
* @param bank   Bank to set the rating from.
* @param rating Rating we want the bank to have.
*/
void bank_setRating(Bank *bank, char rating);

/*
* Gives the rating of a bank.
* @param bank Bank to get the rating from.
* @return     Rating of a given bank.
*/
char bank_rating(Bank *bank);

/*
* Gives the reference of a bank.
* @param bank Bank to get the reference from.
* @return     Reference of a given bank.
*/
int bank_reference(Bank *bank);

/*
* Gives the number of loans of a bank.
* @param bank Bank to get the number of loans from.
* @return     Number of loans of a given bank.
*/
int bank_loansNum(Bank *bank);
