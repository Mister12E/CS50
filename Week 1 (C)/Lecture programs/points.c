// #include <cs50.h>
#include <stdio.h>

int main(void)
{
    const int MINE = 2;
    int points;
    printf ("How many points did you lose? ");
    scanf ("%i", &points);
    // int points = get_int ("How many points did you lose? ");
    if (points < MINE)
    {
        printf ("You lost fewer points than me.\n");
    }
    else if (points > MINE)
    {
        printf ("You lost more points than me.\n");
    }
    else
    {
        printf ("You lost the same amount of points as me.\n");
    }
}