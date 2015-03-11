#include "includes.h"
#include "bank.h"

void bank_init(Bank* bank, char* name, int rating, int reference){
	bank->name = name;
	bank->rating = rating;
	bank->reference = reference;
	bank->loansNum = 0;
}

void bank_addLoan(Bank* bank, int reference, int amount){
	int i;
	Loan loan;
	for (i = 0; i < bank->loansNum; i++){
		if(loan_reference(&bank->loans[i]) == reference){
			loan_updateAmount(&bank->loans[i], amount);
			return;
		}
	}
	loan_init(&loan, reference, amount);
	realloc(bank->loans, sizeof(Loan) * (bank->loansNum + 1));
	bank->loans[bank->loansNum] = loan;
	bank->loansNum++;
}

Loan* bank_loanByReference(Bank* bank, int reference){
	int i;
	for (i = 0; i < bank->loansNum; i++){
		Loan* currentLoan = bank_loan(bank, i);
		if(loan_reference(currentLoan) == reference){
			return currentLoan;
		} 
	}
	return NULL;
}

char* bank_name(Bank* bank){
	return bank->name;
}

char bank_rating(Bank* bank){
	return bank->rating;
}

int bank_reference(Bank* bank){
	return bank->reference;
}

int bank_loansNum(Bank* bank){
	return bank->loansNum;
}

Loan* bank_loan(Bank* bank, int id){
	return &bank->loans[id];
}