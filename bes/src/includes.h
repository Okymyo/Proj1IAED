#pragma once

/* Standard includes */
#include <stdio.h>		/* Required for input/output */
#include <stdlib.h>		/* Required for malloc(), calloc(), realloc(), free */
#include <string.h>		/* Required for memcpy() */

/* General structures */
typedef struct Network Network;
typedef struct Bank Bank;
typedef struct Loan Loan;

struct Network
{
	int banksNum;
	Bank **banks;
};

struct Bank
{
	char *name;
	char rating;
	int reference;
	int loansNum;
	Loan *loans;
};

struct Loan
{
	Bank *loanee;
	int amount;
};