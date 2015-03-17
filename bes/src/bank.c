#include "includes.h"
#include "bank.h"

void bank_init(Bank *bank, char *name, int rating, int reference){
	bank->name = name;
	bank->rating = rating;
	bank->reference = reference;
	bank->loansNum = 0;
	bank->loans = NULL;
}

void bank_terminate(Bank *bank){
	/* Although loans might be a NULL pointer, it's ignored by free if that is the case */
	free(bank->loans);
	free(bank);
}

void bank_addLoan(Bank *bank, Bank *loanee, int amount){
	int i;
	Loan loan;
	for (i = 0; i < bank_loansNum(bank); i++){
		Loan *currentLoan = bank_loan(bank, i);
		if(loan_loanee(currentLoan) == loanee){
			loan_updateAmount(currentLoan, amount);
			return;
		}
	}
	/* We should definitely check whether we receive a NULL pointer or not.
	However, we can't really handle this. If it throws OOM, nothing we can do.
	Might as well let it throw a segmentation fault, at least it's meaningful */
	bank->loans = realloc(bank->loans, sizeof(Loan)*(bank->loansNum + 1));
	bank->loans[bank->loansNum] = loan;
	loan_init(&bank->loans[bank->loansNum], loanee, amount);
	bank->loansNum++;
}

void bank_removeLoan(Bank *bank, Loan *loan){
	Loan *loans;
	int index;
	
	for(index = 0; index < bank->loansNum; index++)
	{
		if(loan == &bank->loans[index])
			break;
	}
	
	loans = malloc(sizeof(Loan)*(bank->loansNum -1));
	memcpy(loans, bank->loans, (index)*sizeof(Loan));
	memcpy(loans+index, bank->loans + index + 1, (bank->loansNum - index - 1)*sizeof(Loan));
    free(bank->loans);
    bank->loans = loans;
	bank->loansNum--;
}

int bank_totalLoaned(Bank *bank, int filter){
	int i, total = 0, totalFiltered = 0;
	for(i = 0; i < bank_loansNum(bank); i++){
		Loan *loan = bank_loan(bank, i);
		int amount = loan_amount(loan);
		if(filter && bank_rating(loan_loanee(loan)) == 0){
			totalFiltered += amount;
		}
		total += amount; 	
	}
	return filter ? totalFiltered : total;
}

Loan* bank_loan(Bank *bank, int id){
	return &bank->loans[id];
}

Loan* bank_loanByLoanee(Bank *bank, Bank *loanee){
	int i;
	for (i = 0; i < bank_loansNum(bank); i++){
		Loan *currentLoan = bank_loan(bank, i);
		if(loan_loanee(currentLoan) == loanee){
			return currentLoan;
		}
	}
	return NULL;
}

char* bank_name(Bank *bank){
	return bank->name;
}

void bank_setRating(Bank *bank, char rating){
	bank->rating = rating;
}

char bank_rating(Bank *bank){
	return bank->rating;
}

int bank_reference(Bank *bank){
	return bank->reference;
}

int bank_loansNum(Bank *bank){
	return bank->loansNum;
}