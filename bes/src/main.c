#include "includes.h"
#include "main.h"

#define QUIT 11
#define CONTINUE 17

int requestInput()
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
			/* STATUS: Needs rework on existing functions before implementation */
			int reference1;
			int reference2;
			int amount;
			scanf("%d %d %d", &reference1, &reference2, &amount);
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
	return CONTINUE;

int main(int argc, char const *argv[]){
	Network *network;
	network = malloc(sizeof(Network));
	network_init(network);
	
	/*while (requestInput() != QUIT){}*/
	
	network_addBank(network, "ola", 1, 18273);
	network_addBank(network, "stuff", 1, 19281);
	network_addBank(network, "coisas", 1, 1647);
	
	bank_addLoan(network_bank(network, 1), network_bankByReference(network, 18273), 17363);
	bank_addLoan(network_bank(network, 2), network_bankByReference(network, 18273), 123);
	bank_addLoan(network_bank(network, 0), network_bankByReference(network, 19281), 1223);

	printf("Numero de parceiros do %s: %d\n", 
		bank_name(network_bank(network, 0)),
		network_partners(network, network_bank(network, 0)));

	network_terminate(network);
	return 0;
}
