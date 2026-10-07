#include <stdio.h>

void clearInput(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

int main(void)
{
    long balance = 0;
    long amount;
    int deposits = 0;
    int withdrawals = 0;
    int choice;
    int status;

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

        /* Switch statement goes here next */
    }

    return 0;
}