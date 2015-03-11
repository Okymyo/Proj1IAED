#include "includes.h"
#include "main.h"

/*
Bank** banks = NULL; 
int banksNum = 0;


void addBank(char *nome, char rating, int reference){
	banks = realloc(banks, sizeof(Bank*)*(banksNum + 1));
	banks[banksNum] = calloc(1, sizeof(Bank));
	bank_init(banks[banksNum], nome, rating, reference);
	banksNum++;
}

Bank* bankByReference(int reference){
	int i;
	for (i = 0; i < banksNum; i++){
		Bank* bank = banks[i];
		if(bank_reference(bank) == reference){
			return bank;
		}	
	}
	return NULL;
}

int partners(Bank* bank){
	int i, j, total = 0;
	for (i = 0; i < banksNum; i++){
		Bank* currentBank = banks[i];
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
*/

int main(int argc, char const *argv[]){
	Network network;
	network_init(&network);
	network_addBank(&network, "ola", 0, 18273);
	network_addBank(&network, "ola", 0, 18273);
	printf("%d\n", network.banksNum);
	return 0;
}
