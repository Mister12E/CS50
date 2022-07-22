// #include <cs50.h>
#include <stdio.h>

int get_negative_int(void);

// The first program prints 3 #'s. The second program askes the user for a negative integer then prints the negative integer. This was used to try the debug command.   
int main(void)
{
    /* This was the first program where the code prints 4 hashes instead of 3 so we use printf to see where we went wrong.
    for(int i = 0; i <= 3; i++)
    {
        printf("i is %i\n", i);
        printf ("# \n");
    {
    */

   // This is the second program
    int i = get_negative_int();
    printf("%i\n", i);
}

int get_negative_int(void)
{
    int n;
    do
    {
        printf("Negative Integer: ");
        scanf("%i", &n);
        // n = get_int("Negative Integer: ");
        printf("n is %i\n", n);
    }
    while (n < 0); // The bug is here. We want a negative number but when the user types a negative number in. It fulfils this condition and goes back into the loop. 
    return n;
}