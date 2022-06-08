// #include <cs50.h>
#include <stdio.h>

int main(void)
{
    long x, y;
    // Prompt user for x
    printf ("x: ");
    scanf ("%li", &x);
    // long x = get_int("x: ");

    // Prompt user for y
    printf ("y: ");
    scanf ("%li", &y);
    // long y = get_int("y: ");

    // Perform addition
    printf("The sum of x and y is: %li \n", x + y);
}