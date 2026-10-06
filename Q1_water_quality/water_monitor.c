#include <stdio.h>
#include <stdlib.h> // Since the temperature Deviation is the absolute value of (Temperature - 25) we need to use the abs() function and stdlib is required for that

// Function to calculate the water quality index
int calculate_index(int temp, int turb) {
    int temp_deviation = abs(temp - 25);
    int turb_penalty = turb / 2;
    return 100 - (temp_deviation + turb_penalty);