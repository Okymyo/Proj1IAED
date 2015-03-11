#pragma once

#include "includes.h"
#include "loan.h"

typedef struct 
{
	char *name;
	char rating;
	int reference;
	int loansNum;
	Loan *loans;
} Bank;

void bank_init(Bank* bank, char* name, int rating, int reference);

void bank_addLoan(Bank* bank, int reference, int amount);

char* bank_name(Bank* bank);

char bank_rating(Bank* bank);

int bank_reference(Bank* bank);

int bank_loansNum(Bank* bank);

Loan* bank_loan(Bank* bank, int id);

Loan* bank_loanByReference(Bank* bank, int reference);


