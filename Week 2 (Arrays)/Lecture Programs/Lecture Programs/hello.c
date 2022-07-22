// #include <cs50.h>
#include <stdio.h>

// This program asks for the user's name and will print "hello user_name". We used this for the clang command to compile the program.
int main(void)
{
    char name[50];
    printf("What's your name? ");
    scanf("%s", name);
    // string name = get_string("What's your name? ");
    printf("hello, %s\n", name);
}