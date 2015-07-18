/* =====================
 * Grupo 5, IAED, LEIC-T
 * 81900 - Nuno Anselmo
 * 81943 - Gonçalo Matos
 * 82047 - André Mendes
   ===================== */

#pragma once

#include "includes.h"
#include "bank.h"

/*
* Creates a new loan.
* @param loaner Bank who is going to loan money.
* @param loanee Bank who is going to receive the money (the loanee).
* @param amount Amount of money that the loaner is going to loan to the loanee.
*/
void loan_new(Bank *loaner, Bank *loanee, int amount);

/*
* Updates the amount of a loan.
* @param loan  Loan to update the amount of money.
* @param delta Amount to sum to the current loan amount.
* @return      Returns 1 if the amount after the update is lesser or equal than 0. Otherwise returns 0.
*/
int loan_updateAmount(Loan *loan, int delta);

/*
* Sets the amount of a loan.
* @param loan   Loan to set the amount of money.
* @param amount Amount of money of the loan.
* @return       Returns 1 if the amount after the update is lesser or equal than 0. Otherwise returns 0.
*/
int loan_setAmount(Loan *loan, int amount);

/*
* Gives the current money of a loan.
* @param loan Loan to get the money from.
* @return     Amount of money of a loan.
*/
int loan_amount(Loan *loan);

/*
* Gives the loanee of a loan.
* @param loan Loan to get the loanee from.
* @return     Pointer of the loanee.
*/
Bank* loan_loanee(Loan *loan);
