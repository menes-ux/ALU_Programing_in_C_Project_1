#include <stdio.h>

/* Function to print the menu so main stay clean */
void print_menu(void)
{
    printf("\n===== MOBILE MONEY TRANSACTION SYSTEM =====\n");
    printf("1. Deposit\n");
    printf("2. Withdraw\n");
    printf("3. Check Balance\n");
    printf("4. Transaction Summary\n");
    printf("5. Exit\n");
    printf("Enter choice: ");
}

int main(void)
{
    /* Variables to track the account and transactions */
    int balance = 0;
    int choice = 0;
    int amount = 0;
    int deposit_count = 0;
    int withdraw_count = 0;

    /* Just testing the menu display for now */
    print_menu();

    return 0;
}