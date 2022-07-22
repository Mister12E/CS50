// #include <cs50.h>
#include <stdio.h>

// This program prints HI! and is used to demostrate how strings are arrays. 
int main(void)
{
    /* The first program is used to print the ASCII values of HI! which is 72, 73, 33.
    char c1 = 'H';
    char c2 = 'I';
    char c3 = '!';

    printf("%i %i %i\n", c1, c2, c3);
    */

   // The second program is used to print strings. 
   char s[4] = "HI!";
   char t[5] = "BYE!";
   // string s = "HI!";
   // string t = "BYE!";

    printf("%s\n", s);
    printf("%s\n", t);
   // printf("%i %i %i %i\n", s[0], s[1], s[2], s[3]);
}