#pragma once

#include "includes.h"
#include "loan.h"

void bank_init(Bank *bank, char *name, int rating, int reference);

void bank_addLoan(Bank *bank, Bank *loanee, int amount);

Loan* bank_loanByLoanee(Bank *bank, Bank *loanee);

Loan* bank_loan(Bank *bank, int id);

char* bank_name(Bank *bank);

char bank_rating(Bank *bank);

int bank_reference(Bank *bank);

int bank_loansNum(Bank *bank);
