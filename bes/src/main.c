#include "includes.h"
#include "main.h"

#define QUIT 11
#define CONTINUE 17

/*
void addBank(char *nome, char rating, int reference){
	Bank bank;
	bank_init(&bank, nome, rating, reference);
	banks[banksNum] = bank;
	banksNum++;	
}

Bank* bankByReference(int reference){
	int i;
	for (i = 0; i < banksNum; i++){
		Bank *bank = &banks[i];
		if(bank_reference(bank) == reference){
			return bank;
		}	
	}
	return NULL;
}

int partners(Bank *bank){
	int i, j, total = 0;
	for (i = 0; i < banksNum; i++){
		Bank *currentBank = &banks[i];
		for (j = 0; j < bank_loansNum(currentBank); j++){
			Loan *currentLoan = bank_loan(currentBank, j);
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

int requestInput()
{
	switch(getchar())
	{
		case 'a':
		{
			char name[40];
			int rating;
			int reference;
			scanf("%s %d %d", name, &rating, &reference);
			break;
		}
		case 'k':
		{
			int reference;
			scanf("%d", &reference);
			break;
		}
		case 'r':
		{
			int reference;
			scanf("%d", &reference);
			break;
		}
		case 'e':
		{
			int reference1;
			int reference2;
			int amount;
			scanf("%d %d %d", &reference1, &reference2, &amount);
			break;
		}
		case 'p':
		{
			int reference1;
			int reference2;
			int amount;
			scanf("%d %d %d", &reference1, &reference2, &amount);
			break;
		}
		case 'l':
		{
			int type;
			scanf("%d", &type);
			break;
		}
		case 'K':
		{
			break;
		}
		case 'x':
		{
			return QUIT;
		}
		default:
		{
			printf("ERROR! Unhandled user input! Aborting!");
			return QUIT;
		}
	}
	return CONTINUE;
}

int main(int argc, char const *argv[]){
	Network *network;
	network = malloc(sizeof(Network));
	network_init(network);
	
	/*while (requestInput() != QUIT){}*/
	
	network_addBank(network, "ola", 1, 18273);
	network_addBank(network, "stuff", 1, 19281);
	network_addBank(network, "coisas", 1, 1647);
	
	bank_addLoan(network_bank(network, 1), 18273, 17363);
	bank_addLoan(network_bank(network, 2), 18273, 123);
	bank_addLoan(network_bank(network, 0), 19281, 1223);

	printf("Numero de parceiros do %s: %d\n", 
		bank_name(network_bank(network, 0)),
		network_partners(network, network_bank(network, 0)));

	network_terminate(network);
	return 0;
}
