#pragma once

#include "includes.h"
#include "bank.h"

void loan_init(Loan *loan, Bank *loanee, int amount);

void loan_setAmount(Loan *loan, int amount);

void loan_updateAmount(Loan *loan, int delta);

Bank* loan_loanee(Loan *loan);

int loan_amount(Loan *loan);