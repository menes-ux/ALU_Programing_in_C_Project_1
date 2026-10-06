#include <stdio.h>
#include <stdlib.h> /* Required for the abs() function */

/* Calculates the water-quality index from the two sensor readings */
int calculate_index(int temperature, int turbidity)
{
    int deviation = abs(temperature - 25);
    int penalty = turbidity / 2;
    return 100 - (deviation + penalty);
}

/* Prints Good, Warning or Critical depending on the index */
void print_status(int index)
{
    if (index >= 80)
    {
        printf("Status: Good\n");
    }
    else if (index >= 60)
    {
        printf("Status: Warning\n");
    }
    else
    {
        printf("Status: Critical\n");
    }
}

int main(void)
{
    int temperature;
    int turbidity;
    int index;

    /* Read the two sensor values */
    printf("Enter temperature (C): ");
    scanf("%d", &temperature);
    printf("Enter turbidity (NTU): ");
    scanf("%d", &turbidity);

    /* Calculate the index using our custom function */
    index = calculate_index(temperature, turbidity);

    /* Print the formatted report */
    printf("\n===== WATER QUALITY REPORT =====\n");
    printf("Temperature   : %d C\n", temperature);
    printf("Turbidity     : %d NTU\n", turbidity);
    printf("Quality index : %d\n", index);
    
    /* Call the status function */
    print_status(index);
    printf("================================\n");

    return 0;
}