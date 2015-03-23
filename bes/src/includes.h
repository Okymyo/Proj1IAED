/* =====================
 * Grupo 5, IAED, LEIC-T
 * 81900 - Nuno Anselmo
 * 81943 - Gonçalo Matos
 * 82047 - André Mendes
   ===================== */

#pragma once

#define NAMESIZE 41 /* 40 + 1 for '\0' */
#define BAD_RATING 0
#define GOOD_RATING 1

/* Standard includes */
#include <stdio.h>		/* Required for standard input/output */
#include <stdlib.h>		/* Required for malloc(), calloc(), realloc(), free() */
#include <string.h>		/* Required for memcpy() and strcpy() */

/* General structures */
typedef struct Network Network;
typedef struct Bank Bank;
typedef struct Loan Loan;

/* Specific Structures */
typedef struct RefCache RefCache;

struct Network
{
	int banksNum;				/* Number of banks in the network. */
	Bank **banks;				/* Pointer to the array of bank pointers. */
	unsigned int *bankRefs;		/* Our vector with every reference.
								As noted below, we will be storing the reference twice for the sake
								of performance during the reference lookup process. */
	RefCache *refsCache;		/* Our small cache of references. */
};	/* Size: 4 + 8 + 8 + 8 = 28 */

struct Bank
{
	char name[NAMESIZE];		/* Array of NAMESIZE char, to contain name. */
	char rating;				/* Rating, either 1 or 0, of the bank. */
	unsigned int reference;		/* Reference of the bank.
								Rather than hurting performance, we decided to hurt our memory allocation.
								We effectively waste 4 bytes by redundantly storing the references twice.
								However, since this speeds up our lookup process, it's a worthy sacrifice. */
	int loansNum;				/* Number of loans made by this bank. */
	Loan *loans;				/* Pointer to the array of loans. */
};	/* Size: 41 + 1 + 4 + 4 + 8 = 58 */

struct Loan
{
	Bank *loanee;				/* Pointer to the bank receiving the loan. */
	int amount;					/* Amount lent in this specific loan. */
};	/* Size: 8 + 4 = 12 */

struct RefCache
{
	unsigned int reference;		/* Reference to a single bank. */
	Bank *bank;					/* Pointer to a single bank. */
};	/* Size: 4 + 8 = 12 */