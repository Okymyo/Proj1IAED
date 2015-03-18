#include "includes.h"
#include "loan.h"

Loan* loan_new(Loan *loans, int *loansNum, Bank *loanee, int amount){
	/* We should definitely check whether we receive a NULL pointer or not.
	However, we can't really handle this. If it throws OOM, nothing we can do.
	Might as well let it throw a segmentation fault, at least it's meaningful */
	loans = realloc(loans, sizeof(Loan)*(*loansNum+1));
	loans[*loansNum].loanee = loanee;
	loans[*loansNum].amount = amount;
	*loansNum += 1;
	return loans;
}

int loan_updateAmount(Loan *loan, int delta){
	return loan_setAmount(loan, loan_amount(loan)+delta);
}

int loan_setAmount(Loan *loan, int amount){
	if (amount > 0){
		loan->amount = amount;
		return 0;
	}
	return 1;
}

int loan_amount(Loan *loan){
	return loan->amount;
}

Bank* loan_loanee(Loan *loan){
	return loan->loanee;
}