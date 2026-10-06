#include <stdio.h>
#include <stdlib.h> /* Required for the abs() function */

/* Calculates the water-quality index from the two sensor readings */
int calculate_index(int temperature, int turbidity)
{
    int deviation = abs(temperature - 25);
    int penalty = turbidity / 2;
    return 100 - (deviation + penalty);
}