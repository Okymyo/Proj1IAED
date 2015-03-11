#include "main.h"

Bank** banks = NULL; 
int banksNum = 0;

void addBank(char *nome, char rating, int reference){
	Bank bank;
	bank_init(&bank, nome, rating, reference);
	banks = realloc(banks, sizeof(Bank*)*(banksNum + 1));
	banks[banksNum] = &bank;
	banksNum++;
}

int main(int argc, char const *argv[]){
	int i, j, n;
	Loan loan;
	Bank* tmp;
	addBank("ola", 1, 10228);
	addBank("cenas", 1, 927391);
	addBank("stuff", 0, 910291);	
	
	bank_addLoan(banks[0], bank_reference(banks[1]), 1500);
	bank_addLoan(banks[1], bank_reference(banks[0]), 3000);
	bank_addLoan(banks[1], bank_reference(banks[0]), 3000);
	bank_addLoan(banks[1], bank_reference(banks[0]), 3000);
	bank_addLoan(banks[2], bank_reference(banks[0]), 2000);

	n = bank_loansNum(banks[0]);
	printf("O banco com referencia %d e nome %s fez %d emprestimos:\n", bank_reference(banks[0]),
	 bank_name(banks[0]), n);
	for (i = 0; i < n; i++){
		loan = bank_loan(banks[0], i);
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
	}
	printf("%lu\n", sizeof(banks));
	return 0;
}
