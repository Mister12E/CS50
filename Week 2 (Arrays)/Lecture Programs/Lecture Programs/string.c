// #include <cs50.h>
#include <stdio.h>
#include <string.h>

// This program asks the user for an input string then prints each character using a for loop until the end of the string using strlen. We also defined 2 variables in the for loop here. 
int main (void)
{
    char s[20]; 
    printf("Input: ");
    scanf("%s", s);
    // string s = get_string("Input: ");
    printf("Output: ");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        printf("%c", s[i]);
    }
    printf("\n");
}