#include <stdio.h>

/* Discards leftover characters in the input buffer (up to the newline) */
void clearInput(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        /* keep discarding */
    }
}

int main(void)
{
    long balance = 0;       /* current balance in RWF */
    long amount;            /* amount entered for a transaction */
    int deposits = 0;       /* number of successful deposits */
    int withdrawals = 0;    /* number of successful withdrawals */
    int choice;             /* menu choice */
    int status;             /* result of scanf */

    while (1)
    {
        printf("\n===== MOBILE MONEY TRANSACTION SYSTEM =====\n");
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. Check Balance\n");
        printf("4. Transaction Summary\n");
        printf("5. Exit\n");
        printf("Enter choice: ");

        status = scanf("%d", &choice);

        if (status == EOF)              /* input stream closed */
        {
            printf("\nInput closed. System terminated.\n");
            break;
        }
        if (status != 1)                /* not a number */
        {
            clearInput();
            printf("Invalid input: please enter a number from 1 to 5.\n");
            continue;                   /* back to the menu */
        }
        clearInput();

        if (choice == 5)                /* Exit: leaves the while loop */
        {
            printf("System terminated.\n");
            break;
        }

        switch (choice)
        {
            case 1: /* Deposit */
                printf("Enter deposit amount: ");
                if (scanf("%ld", &amount) != 1)
                {
                    clearInput();
                    printf("Transaction rejected: Amount must be a number.\n");
                    continue;           /* back to the menu */
                }
                clearInput();

                if (amount <= 0)
                {
                    printf("Transaction rejected: Amount must be positive.\n");
                }
                else
                {
                    balance += amount;
                    deposits++;
                    printf("Deposit successful.\n");
                    printf("Current balance: %ld RWF\n", balance);
                }
                break;                  /* leaves the switch */

            case 2: /* Withdrawal */
                printf("Enter withdrawal amount: ");
                if (scanf("%ld", &amount) != 1)
                {
                    clearInput();
                    printf("Transaction rejected: Amount must be a number.\n");
                    continue;           /* back to the menu */
                }
                clearInput();

                if (amount <= 0)
                {
                    printf("Transaction rejected: Amount must be positive.\n");
                }
                else if (amount > balance)
                {
                    printf("Transaction rejected: Insufficient balance.\n");
                }
                else
                {
                    balance -= amount;
                    withdrawals++;
                    printf("Withdrawal successful.\n");
                    printf("Current balance: %ld RWF\n", balance);
                }
                break;

            case 3: /* Balance inquiry */
                printf("Current balance: %ld RWF\n", balance);
                break;

            case 4: /* Transaction summary */
                printf("Successful deposits   : %d\n", deposits);
                printf("Successful withdrawals: %d\n", withdrawals);
                break;

            default: /* Any other number */
                printf("Invalid choice: please select 1 to 5.\n");
                break;
        }
    }

    return 0;
}