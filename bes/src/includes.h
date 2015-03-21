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

/* Specific Structures */
typedef struct Cache Cache;

struct Network
{
	int banksNum;				/* Number of banks in the network */
	Bank **banks;				/* Pointer to the array of bank pointers */
	Cache *refsCache;			/* Our small cache of references */
	int *bankRefs;
};	/* Size: 4 + 8 + 8 = 20
	   Real Size: 32
	   Lost bytes: 12 */

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

struct Cache
{
	int value;					/* Reference to a single bank */
	Bank *bank;					/* Pointer to a single bank */
	int uses;					/* Number of times cached value has been used */
};	/* Size: 4 + 8 + 4 = 16
	   Real Size: 16
	   Lost bytes: 0 */