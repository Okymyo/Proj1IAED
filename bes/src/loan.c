#include "includes.h"
#include "loan.h"

void loan_init(Loan *loan, Bank *loanee, int amount){
	loan->loanee = loanee;
	loan->amount = amount;
}

int loan_setAmount(Loan *loan, int amount){
	if (amount > 0)
	{
		loan->amount = amount;
		return 0;
	}
	return 1;
}

int loan_updateAmount(Loan *loan, int delta){
	return loan_setAmount(loan, loan_amount(loan)+delta);
}

Bank* loan_loanee(Loan *loan){
	return loan->loanee;
}

int loan_amount(Loan *loan){
	return loan->amount;
}