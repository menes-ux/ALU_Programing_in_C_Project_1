#include <stdio.h>

/* 1. Calculate the total distance using a normal loop */
int get_total_distance(int distances[], int size)
{
    int sum = 0;
    int i;
    for (i = 0; i < size; i++)
    {
        sum += distances[i];
    }
    return sum;
}

/* 2. Find the longest route in the array */
int get_longest_route(int distances[], int size)
{
    int max = distances[0];
    int i;
    for (i = 1; i < size; i++)
    {
        if (distances[i] > max)
        {
            max = distances[i];
        }
    }
    return max;
}

int main(void)
{
    /* Store the distances and setup variables exactly like the example */
    int distances[] = {12, 25, 18, 40, 15, 30};
    int num_routes = 6;
    
    int total = get_total_distance(distances, num_routes);
    int longest = get_longest_route(distances, num_routes);

    /* Just printing these two to test our progress */
    printf("===== DELIVERY DISTANCE ANALYSIS =====\n");
    printf("Total distance: %d km\n", total);
    printf("Longest route: %d km\n", longest);

    return 0;
}