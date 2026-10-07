#include <stdio.h>

/* Discards leftover characters up to the newline */
void clearInput(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

/* Keeps asking until an integer between min and max is entered.
   Returns 1 on success, 0 if the input stream ends. */
int readInt(const char *prompt, int min, int max, int *value)
{
    int status;

    while (1)
    {
        printf("%s", prompt);
        status = scanf("%d", value);

        if (status == EOF)
        {
            return 0;
        }
        if (status != 1)
        {
            clearInput();
            printf("Error: please enter a whole number. Try again.\n");
            continue;
        }
        if (*value < min || *value > max)
        {
            printf("Error: value must be between %d and %d. Try again.\n", min, max);
            continue;
        }
        return 1;
    }
}

/* Returns the total distance using a loop */
int totalDistance(int distances[], int n)
{
    int total = 0;
    int i;

    for (i = 0; i < n; i++)
    {
        total += distances[i];
    }
    return total;
}

/* Returns the average distance (reuses totalDistance) */
double averageDistance(int distances[], int n)
{
    return (double)totalDistance(distances, n) / n;
}

/* Returns the longest route */
int longestRoute(int distances[], int n)
{
    int longest = distances[0];
    int i;

    for (i = 1; i < n; i++)
    {
        if (distances[i] > longest)
        {
            longest = distances[i];
        }
    }
    return longest;
}

/* Counts routes with a distance greater than the given limit */
int countAboveLimit(int distances[], int n, int limit)
{
    int count = 0;
    int i;

    for (i = 0; i < n; i++)
    {
        if (distances[i] > limit)
        {
            count++;
        }
    }
    return count;
}

/* Recursive sum of the first n elements.
   Base case: no elements left -> sum is 0.
   Recursive case: last element + sum of the first n - 1 elements. */
int recursiveSum(int distances[], int n)
{
    if (n == 0)
    {
        return 0;
    }
    return distances[n - 1] + recursiveSum(distances, n - 1);
}

int main(void)
{
    int distances[100];
    int n;
    int limit;
    int i;

    if (!readInt("Number of routes (1-100): ", 1, 100, &n))
    {
        printf("Input ended unexpectedly.\n");
        return 1;
    }

    for (i = 0; i < n; i++)
    {
        printf("Route %d - ", i + 1);
        if (!readInt("Distance in km (0-1000000): ", 0, 1000000, &distances[i]))
        {
            printf("Input ended unexpectedly.\n");
            return 1;
        }
    }

    if (!readInt("Distance limit in km (0-1000000): ", 0, 1000000, &limit))
    {
        printf("Input ended unexpectedly.\n");
        return 1;
    }

    printf("\n===== DELIVERY DISTANCE ANALYSIS =====\n");
    printf("Total distance: %d km\n", totalDistance(distances, n));
    printf("Average distance: %.2f km\n", averageDistance(distances, n));
    printf("Longest route: %d km\n", longestRoute(distances, n));
    printf("Routes above %d km: %d\n", limit, countAboveLimit(distances, n, limit));
    printf("Recursive sum: %d km\n", recursiveSum(distances, n));

    /* Function reuse: same function, different argument */
    printf("Routes above %d km: %d\n", limit * 2,
           countAboveLimit(distances, n, limit * 2));

    return 0;
}