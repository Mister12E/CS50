// #include <cs50.h>
#include <stdio.h>

// This program takes the username as input from the commmand line and prints "hello, username" then returns 0 to represent no error. If not, it will print "Missing command-line argument" and return 1 which represent an error.
// This is a program I wrote myself which uses char** instead of the variable type string that is defined in the cs50 library.
int main(int argc, char** argv)
{
    if (argc != 2)
    {
        printf("Missing command-line argument \n");
        return 1;
    }
    printf("hello, %s \n", argv[1]);
    return 0;
}