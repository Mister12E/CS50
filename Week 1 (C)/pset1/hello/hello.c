#include <stdio.h>

int main(void)
{
    // This gets the name of the user and puts the name in the variable called name
    char name[50]; 
    printf ("What is your name? ");
    gets (name);
    // scanf ("%s", name); We dont use this because it cannot scan the space between a user's name and last name.

    // This prints hello, (name of user) in the terminal 
    printf("Hello, %s\n", name);
}