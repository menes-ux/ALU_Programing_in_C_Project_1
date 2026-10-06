#include <stdio.h>

/* Find how much the temperature differ from 25 C. 
   We make sure it stay positive. */
float get_temp_deviation(float temperature)
{
    float deviation = temperature - 25.0;
    if (deviation < 0)
    {
        deviation = -deviation;
    }
    return deviation;
}

/* Calculate final water quality index using the formula */
float get_quality_index(float temperature, float turbidity)
{
    float deviation = get_temp_deviation(temperature);
    float penalty = turbidity / 2.0;
    return 100.0 - (deviation + penalty);
}

/* Check the index score to print the correct water status */
void print_status(float index)
{
    if (index >= 80.0)
    {
        printf("Status: Good\n");
    }
    else if (index >= 60.0)
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
    float temperature;
    float turbidity;
    float index;

    /* Ask the user to enter the sensor informations */
    printf("Please enter the water temperature (in Celsius): ");
    scanf("%f", &temperature);
    
    printf("Please enter the water turbidity (in NTU): ");
    scanf("%f", &turbidity);

    /* Get the calculated index */
    index = get_quality_index(temperature, turbidity);

    /* Print out the final report format */
    printf("\n===== WATER QUALITY REPORT =====\n");
    printf("Temperature: %.2f C\n", temperature);
    printf("Turbidity: %.2f NTU\n", turbidity);
    printf("Quality Index: %.2f\n", index);
    
    print_status(index);
    printf("================================\n");

    return 0;
}