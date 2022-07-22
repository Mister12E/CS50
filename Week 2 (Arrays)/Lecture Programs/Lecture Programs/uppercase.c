// #include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// This program asks the user for a string and converts all the characters to uppercase letters using the ASCII chart. (a = 97, A = 65)
int main(void)
{
    char s[30];
    printf("Before: ");
    scanf("%s", s); 
    // string s = get_string("Before: ");
    printf("After: ");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        printf("%c", toupper(s[i]));
    }

    /* This is how we use the function islower to check if a character is lowercase or not. If its lowercase, it returns a non-zero value. If not, it returns 0.
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (islower(s[i]))
        {
            printf("%c", toupper(s[i]));
        }
        else
        {
            printf("%c", s[i]);
        }
    }
    */

    /* This is how we originally change lowercase letters to uppercase letters.
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            printf("%c", s[i] - 32);
        }
        else
        {
            printf("%c", s[i]);
        }
    }
    */
    printf("\n");
}