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
	for (i = 0; i < bank_loansNum(bank); i++){
		Loan *currentLoan = bank_loan(bank, i);
		if(loan_reference(currentLoan) == reference){
			loan_updateAmount(currentLoan, amount);
			return;
		}
	}
	loan_init(&loan, reference, amount);
	bank->loans[bank_loansNum(bank)] = loan;
	bank->loansNum++;
}

Loan* bank_loan(Bank* bank, int id){
	return &bank->loans[id];
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