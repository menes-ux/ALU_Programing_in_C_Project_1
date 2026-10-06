#include <stdio.h>

int main() {
    
    int temperature; 
    int turbidity; 

    printf("Please enter the water temperature (in Celsius): ");
    scanf("%d", &temperature);
    printf("Please enter the water turbidity (in NTU): ");
    scanf("%d", &turbidity);
    int water_quality_index = 100 - (temperature + turbidity);
    printf("Water Quality Index: %d\n", water_quality_index);
    return 0;
}