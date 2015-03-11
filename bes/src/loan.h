typedef struct 
{
	int reference;
	int amount;
} Loan;

void load_init(Loan *loan, int reference, int amount);

int loan_reference(Loan *loan);

int loan_amount(Loan *loan);

void loan_setAmount(Loan *loan, int amount);

void loan_updateAmount(Loan *loan, int delta);