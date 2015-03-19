#include "includes.h"
#include "main.h"

#define QUIT 11
#define CONTINUE 17

int requestInput(Network *network)
{
	/* This serves as a general warning: we use scanf(). A LOT.
	scanf() can easily cause a buffer overflow, so we can only hope it doesn't.
	Rather than hoping input was sanitized we should code our own improved reader.
	However, since we are certain the input was previously sanitized, we won't. */
	switch(getchar())
	{
		case 'a':
		{
			char name[NAMESIZE];
			int rating;
			int reference;
			scanf("%s %d %d", (char*)&name, &rating, &reference);
			network_addBank(network, name, rating, reference);
			break;
		}
		case 'k':
		{
			int reference;
			scanf("%d", &reference);
			bank_setRating(network_bankByReference(network, reference), 0);
			break;
		}
		case 'r':
		{
			int reference;
			scanf("%d", &reference);
			bank_setRating(network_bankByReference(network, reference), 1);
			break;
		}
		case 'e':
		{
			int reference1, reference2, amount;
			scanf("%d %d %d", &reference1, &reference2, &amount);
			bank_addLoan(
				network_bankByReference(network, reference1),
				network_bankByReference(network, reference2), 
				amount
			);
			break;
		}
		case 'p':
		{
			int reference1, reference2, amount;
			Loan *loan;
			Bank *bank;
			scanf("%d %d %d", &reference1, &reference2, &amount);
			
			/* Since we're using it twice, store both loan and bank */
			bank = network_bankByReference(network, reference2);
			loan = bank_loanByLoanee(bank, network_bankByReference(network, reference1));
			
			/* Update loan. If it becomes 0 or negative, it'll return True, to deallocate loan */
			if(loan_updateAmount(loan, (-1)*amount))
				bank_removeLoan(bank, loan);
			
			break;
		}
		case 'l':
		{
			int type;
			scanf("%d", &type);
			network_listBanks(network, type);
			break;
		}
		case 'K':
		{
			network_killWorst(network);
			break;
		}
		case 'x':
		{
			network_printStatus(network);
			return QUIT;
		}
		default:
		{
			/* User has input an unknown command or parameter
			We'll just discard it and request the input again
			printf("ERROR! Unhandled command!\n"); */
		}
	}
	/* We never discarded chars in excess from the input buffer.
	It's a good idea to do that now or else they'll get read. */
	while ( getchar() != '\n' );
	return CONTINUE;
}

int main(int argc, char const *argv[]){
	Network *network;
	network = network_new();
	
	while (requestInput(network) != QUIT);

	network_terminate(network);
	return 0;
}
