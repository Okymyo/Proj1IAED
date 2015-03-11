#include "includes.h"
#include "bank.h"

Bank** banks = NULL; 
int banksNum = 0;

void addBank(char *nome, char rating, int reference){
	Bank bank;
	bank_init(&bank, nome, rating, reference);
	banks = realloc(banks, sizeof(Bank*)*(banksNum + 1));
	banks[banksNum] = &bank;
	banksNum++;
}

Bank* bankByReference(int reference){
	int i;
	for (i = 0; i < banksNum; i++){
		Bank* bank = &banks[i];
		if(bank_reference(bank) == reference){
			return bank;
		}	
	}
	return NULL;
}

int partners(Bank* bank){
	int i, j, total = 0;
	for (i = 0; i < banksNum; i++){
		Bank* currentBank = &banks[i];
		for (j = 0; j < bank_loansNum(currentBank); j++){
			Loan* currentLoan = bank_loan(currentBank, j);
			if(loan_reference(currentLoan) == bank_reference(bank)){
				if(bank_loanByReference(bank, bank_reference(currentBank)) 
					== NULL){
					total++;
				}
			}
		}
	}
	total+=bank_loansNum(bank);
	return total;
}


int main(int argc, char const *argv[]){
	Bank* bank;
	addBank("ola", 1, 10228);
	addBank("cenas", 1, 927391);
	addBank("stuff", 0, 910291);	
	
	bank = bankByReference(10228);
	bank_addLoan(bank, bank_reference(&banks[1]), 1500);
	bank_addLoan(bank, bank_reference(&banks[2]), 1500);
	bank_addLoan(&banks[1], bank_reference(bank), 3000);
	bank_addLoan(&banks[1], bank_reference(bank), 3000);
	bank_addLoan(&banks[1], bank_reference(bank), 3000);
	bank_addLoan(&banks[2], bank_reference(bank), 2000);
	printf("%d\n", partners(bank));

	/*
	n = bank_loansNum(bank);
	printf("O banco com referencia %d e nome %s fez %d emprestimos:\n", bank_reference(bank),
	 bank_name(bank), n);
	for (i = 0; i < n; i++){
		loan = bank_loan(bank, i);
		printf("\tLoan-> Reference: %d, Amount: %d\n", loan_reference(&loan), loan_amount(&loan));
	}

	printf("Recebemos estes emprestimos:\n");
	for(i = 0; i < banksNum; i++){
		tmp = banks[i];
		for(j = 0; j < bank_loansNum(tmp); j++){
			loan = bank_loan(tmp, j);
			if(loan_reference(&loan) == bank_reference(banks[0])){
				printf("\tLoan-> Reference: %d, Amount: %d\n", bank_reference(tmp), loan_amount(&loan));
			}
		}
	}*/
	return 0;
}
