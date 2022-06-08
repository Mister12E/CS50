// #include <cs50.h>
#include <stdio.h>

int main (void)
{
    char c;
    // Prompt user to agree
    printf("Do you agree? ");
    scanf("%c", &c);
    // char c = get_char("Do you agree? ");

    // Check whether user agreed
    if (c == 'y' || c == 'Y')
    {
        printf ("Agreed. \n");
    }
    else if (c == 'n' || c == 'N')
    {
        printf ("Not agreed. \n");
    }
    else
    {
        printf ("Invalid input. \n");
    }
}