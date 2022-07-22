// #include <cs50.h>
#include <stdio.h>

// This program asks the user for how many scores he/she has, calculates the average of the scores and prints the average. 
int main(void)
{
    int n;
    printf ("How many scores? ");
    scanf("%i", &n);
    // int n = get_int("How many scores? ");
    float scores[n], total = 0;
    float average;

    for (int i = 0; i < n; i++)
    {
        printf("Score: ");
        scanf("%f", &scores[i]);
        // scores[i] = get_float("Score: ");
        total = total + scores[i];
    }
    average = total / n ;

    printf("Average: %.2f\n", average);
}