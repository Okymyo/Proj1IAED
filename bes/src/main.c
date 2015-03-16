#include "includes.h"
#include "main.h"

#define QUIT 11
#define CONTINUE 17

int requestInput(Network *network)
{
	switch(getchar())
	{
		case 'a':
		{
			/* STATUS: Can be implemented with existing functions */
			char name[40];
			int rating;
			int reference;
			scanf("%s %d %d", name, &rating, &reference);
			printf("Li nome: %s, rating: %d, e referencia: %d\n", name, rating, reference);
			break;
		}
		case 'k':
		{
			/* STATUS: Can be implemented with existing functions */
			int reference;
			scanf("%d", &reference);
			break;
		}
		case 'r':
		{
			/* STATUS: Can be implemented with existing functions */
			int reference;
			scanf("%d", &reference);
			break;
		}
		case 'e':
		{
			/* STATUS: Can be implemented with existing functions */
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
			Loan *loan;
			Bank *bank;
			scanf("%d %d %d", &reference1, &reference2, &amount);
			
			/* Since we're using it twice, store both loan and bank */
			bank = network_bankByReference(network, reference2);
			loan = bank_loanByLoanee(bank, network_bankByReference(network, reference1));
			
			/* Update loan. If it becomes 0 or negative, it'll return True, to deallocate loan */
			if(loan_updateAmount(loan, (-1)*amount))
				bank_deleteLoan(bank, loan);
			
			break;
		}
		case 'l':
		{
			/* STATUS: Unknown */
			int type;
			scanf("%d", &type);
			break;
		}
		case 'K':
		{
			/* STATUS: Requires new function to be implemented */
			break;
		}
		case 'x':
		{
			/* STATUS: Can be implemented */
			return QUIT;
		}
		default:
		{
			printf("ERROR! Unhandled user input! Aborting!");
			return QUIT;
		}
	}
	/* We never discarded chars in excess from the input buffer.
	It's a good idea to do that now or else they'll get read. */
	while ( getchar() != '\n' );
	return CONTINUE;
}

int main(int argc, char const *argv[]){
	Network *network;
	network = malloc(sizeof(Network));
	network_init(network);
	
	while (requestInput(network) != QUIT);

	network_terminate(network);
	return 0;
}
