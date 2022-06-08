#include <stdio.h>

void meow (int n);

int main (void)
{
        meow(3); // Change the number in the brackets to change the number of times meow is printed in the terminal. 
}

void meow (int n)
{
    for ( int i = 0; i < n; i++)
    {
        printf ("meow\n");
    }
}