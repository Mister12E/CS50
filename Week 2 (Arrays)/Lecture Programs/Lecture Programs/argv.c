// #include <cs50.h>
#include <stdio.h>

// This program takes the username as input from the commmand line and prints "hello, username". If no name or 2 or more names are given, it will print "hello, world". 
// I can't run this natively in c because I need cs50 which defines the variable string. 
/*
int main(int argc, string argv[])
{
    if(argc == 2)
    {
        printf("hello, %s\n", argv[1]);
    }
    else
    {
        printf("hello, world\n");
    }
}
*/ 

// This is a program I wrote myself which print out how many words have been typed into the command line. 
int main(int argc, char** argv)
{
    printf("%i\n", argc);
}