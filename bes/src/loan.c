#include "includes.h"
#include "loan.h"

void loan_init(Loan *loan, Bank *loanee, int amount){
	loan->loanee = loanee;
	loan->amount = amount;
}

void loan_setAmount(Loan *loan, int amount){
	loan->amount = amount;
}

void loan_updateAmount(Loan *loan, int delta){
	loan_setAmount(loan, loan_amount(loan)+delta);
}

Bank* loan_loanee(Loan *loan){
	return loan->loanee;
}

int loan_amount(Loan *loan){
	return loan->amount;
}