// #include <cs50.h>
#include <stdio.h>
#include <string.h>

// int get_length(string s);

// This program asks the user for a name, calculates the length of the string and prints it. 
int main(void)
{
    char name[20]; 
    printf("Name: ");
    scanf("%s", name);
    // string name = get_string("Name: ");
    int length = strlen(name);
    // int length = get_length(name);
    printf("%i\n", length);
}

/* This is the function for calculating the length of the string. 
int get_length(string s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return i;
}
*/