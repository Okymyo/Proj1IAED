#pragma once

#define NAMESIZE 41 /* 40 + 1 for '\0' */

/* Standard includes */
#include <stdio.h>		/* Required for standard input/output */
#include <stdlib.h>		/* Required for malloc(), calloc(), realloc(), free() */
#include <string.h>		/* Required for memcpy() and strcpy() */

/* General structures */
typedef struct Network Network;
typedef struct Bank Bank;
typedef struct Loan Loan;

struct Network
{
	int banksNum;				/* Number of banks in the network */
	Bank **banks;				/* Pointer to the array of bank pointers */
};	/* Size: 4 + 8 = 12
	   Real Size: 16 
	   Lost bytes: 4 */

struct Bank
{
	char name[NAMESIZE];		/* Array of NAMESIZE char, to contain name */
	char rating;				/* Rating, either 1 or 0, of the bank */
	unsigned int reference;		/* Reference of the bank */
	int loansNum;				/* Number of loans made by this bank */
	Loan *loans;				/* Pointer to the array of loans */
};	/* Size: 41 + 1 + 4 + 4 + 8 = 58
	   Real Size: 64 
	   Lost bytes: 6 */

struct Loan
{
	Bank *loanee;				/* Pointer to the bank receiving the loan */
	int amount;					/* Amount of money lent */
};	/* Size: 8 + 4 = 12
	   Real Size: 16
	   Lost bytes: 4 */
