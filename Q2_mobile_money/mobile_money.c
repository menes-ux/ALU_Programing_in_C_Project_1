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


    return 0;
}