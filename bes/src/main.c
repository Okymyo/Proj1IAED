#include "includes.h"
#include "main.h"

#define QUIT 11
#define CONTINUE 17

/*
=======
#define QUIT 11
#define CONTINUE 17

Bank **banks = NULL; 
int banksNum = 0;

void addBank(char *name, int rating, int reference){
	banks = realloc(banks, sizeof(Bank*)*(banksNum + 1));
	banks[banksNum] = calloc(1, sizeof(Bank));
	bank_init(banks[banksNum], name, rating, reference);
	banksNum++;
}

Bank* bankByReference(int reference){
	int i;
	for (i = 0; i < banksNum; i++){
		if(bank_reference(banks[i]) == reference){
			return banks[i];
		}	
	}
	return NULL;
}

int partners(Bank *bank){
	int i, j, total = 0;
	for (i = 0; i < banksNum; i++)
	{
		Bank *currentBank = banks[i];
		for (j = 0; j < bank_loansNum(currentBank); j++)
		{
			Loan *currentLoan = bank_loan(currentBank, j);
			if(loan_reference(currentLoan) == bank_reference(bank))
				if(bank_loanByReference(bank, bank_reference(currentBank)) == NULL)
					total++;
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
			printf("ERROR! Unhandled user input! Aborting");
			return QUIT;
		}
	}
	
	return CONTINUE;
}

int main(int argc, char const *argv[]){
	Network network;
	network_init(&network);
	network_addBank(&network, "ola", 0, 18273);
	network_addBank(&network, "ola", 0, 18273);
	printf("%d\n", network.banksNum);
	return 0;
}
