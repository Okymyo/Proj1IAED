#pragma once

#include "includes.h"
#include "loan.h"

Bank* bank_new(char *name, int rating, int reference);

void bank_terminate(Bank *bank);

void bank_addLoan(Bank *bank, Bank *loanee, int amount);

void bank_removeLoan(Bank *bank, Loan *loan);

int bank_totalLoaned(Bank *bank, int filter);

Loan* bank_loan(Bank *bank, int id);

Loan* bank_loanByLoanee(Bank *bank, Bank *loanee);

char* bank_name(Bank *bank);

void bank_setRating(Bank *bank, char rating);

char bank_rating(Bank *bank);

int bank_reference(Bank *bank);

int bank_loansNum(Bank *bank);
