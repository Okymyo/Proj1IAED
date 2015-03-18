#include "includes.h"
#include "main.h"

#define QUIT 11
#define CONTINUE 17
#define NAMESIZE 41 /* 40 + 1 for '\0' */

/* COMMENT TO DELETE...
IMPLEMENTTED INPUT COMMANDS (ACCORDING TO PROJECT'S GUIDE):
	√ a: add new bank
	√ k: rate bank as trash
	√ r: rate bank as healthy
	√ e: add new loan
	√ p: add amortization
	√ l: list banks
	√ K: demote worst bank
	√ x: QUIT
*/

int requestInput(Network *network)
{
	switch(getchar())
	{
		case 'a':
		{
			/* STATUS: Can be implemented with existing functions */
			char *name;
			int rating;
			int reference;
			name = malloc(NAMESIZE*sizeof(char));
			scanf("%s %d %d", name, &rating, &reference);
			network_addBank(network, name, rating, reference);
			break;
		}
		case 'k':
		{
			/* STATUS: Can be implemented with existing functions */
			int reference;
			scanf("%d", &reference);
			bank_setRating(
				network_bankByReference(network, reference),
				0
			);
			break;
		}
		case 'r':
		{
			/* STATUS: Can be implemented with existing functions */
			int reference;
			scanf("%d", &reference);
			bank_setRating(
				network_bankByReference(network, reference), 
				1
			);
			break;
		}
		case 'e':
		{
			/* STATUS: Can be implemented with existing functions */
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
			/* STATUS: Unknown */
			/*
			scanf("%d", &type);
			printf("Temos %d bancos.\n", network->banksNum);
			for (i = 0; i < network->banksNum; i++){
				Bank *currentBank = network->banks[i];
				printf("Banco -> Nome: %s, Ranking: %d, Referencia: %d\n", currentBank->name, currentBank->rating, currentBank->reference);
				printf("Emprestou dinheiro a %d bancos.\n", currentBank->loansNum);
				for (j = 0; j < currentBank->loansNum; j++){
					Loan *currentLoan = bank_loan(currentBank, j);		
					printf("\tLoan -> Referencia: %d, Montante: %d\n", currentLoan->loanee->reference, currentLoan->amount);
				}
			}
			*/
			int type;
			scanf("%d", &type);
			network_listBanks(network, type);
			break;
		}
		case 'K':
		{
			/* STATUS: Requires new function to be implemented */
			break;
		}
		case 'x':
		{
			/* STATUS: Can be implemented 
			Command "x": Quit program */
			return QUIT;
		}
		default:
		{
			printf("ERROR! Unhandled user input!\n");
			/* There's no need to quit everytime we "mis-enter" a command.
			As said on the project guide: wrong command -> back to start.
			return QUIT; */
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
	
	printf("Banco: %lu, Emprestimo: %lu, Network: %lu\n", sizeof(Bank), sizeof(Loan), sizeof(Network));
	while (requestInput(network) != QUIT);

	network_terminate(network);
	return 0;
}
