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

/* 2. Calculate the average distance 
   *RUBRIC CHECK*: We reuse get_total_distance() here! */
float get_average_distance(int distances[], int size)
{
    int total = get_total_distance(distances, size);
    return (float)total / size;
}

/* 3. Find the longest route in the array */
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

/* 4. Count how many routes are greater than the limit */
int count_above_limit(int distances[], int size, int limit)
{
    int count = 0;
    int i;
    for (i = 0; i < size; i++)
    {
        if (distances[i] > limit)
        {
            count++;
        }
    }
    return count;
}

int main(void)
{
    /* Store the distances and setup variables exactly like the example */
    int distances[] = {12, 25, 18, 40, 15, 30};
    int num_routes = 6;
    int limit = 20; /* Add our limit variable */
    
    int total = get_total_distance(distances, num_routes);
    float average = get_average_distance(distances, num_routes);
    int longest = get_longest_route(distances, num_routes);
    int above_limit = count_above_limit(distances, num_routes, limit);

    printf("===== DELIVERY DISTANCE ANALYSIS =====\n");
    printf("Total distance: %d km\n", total);
    printf("Average distance: %.2f km\n", average);
    printf("Longest route: %d km\n", longest);
    printf("Routes above %d km: %d\n", limit, above_limit);

    return 0;
}