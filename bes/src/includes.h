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
	int banksNum;				/* Number of banks in the network */
	Bank **banks;				/* Pointer to the array of bank pointers */
};

struct Bank
{
	char *name;					/* Pointer to the char[40] name */
	char rating;				/* Rating, either 1 or 0, of the bank */
	unsigned int reference;		/* Reference of the bank */
	int loansNum;				/* Number of loans made by this bank */
	Loan *loans;				/* Pointer to the array of loans */
};

struct Loan
{
	Bank *loanee;				/* Pointer to the bank receiving the loan */
	int amount;					/* Amount of money lent */
};
