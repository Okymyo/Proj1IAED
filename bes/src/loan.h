#pragma once

#include "includes.h"
#include "bank.h"

void loan_new(Bank *loaner, Bank *loanee, int amount);

int loan_updateAmount(Loan *loan, int delta);

int loan_setAmount(Loan *loan, int amount);

int loan_amount(Loan *loan);

Bank* loan_loanee(Loan *loan);