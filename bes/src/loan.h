#pragma once

#include "includes.h"
#include "bank.h"

Loan* loan_new(Loan *loan, int *loansNum, Bank *loanee, int amount);

int loan_updateAmount(Loan *loan, int delta);

int loan_setAmount(Loan *loan, int amount);

int loan_amount(Loan *loan);

Bank* loan_loanee(Loan *loan);