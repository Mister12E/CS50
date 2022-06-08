// #include <cs50.h>
#include <stdio.h>

int main(void)
{
    char answer[50];
    printf("hello, world\n");
    printf("What's your name? ");
    scanf("%s", answer);
    // string answer = get_string("What's your name? ");
    printf("hello, %s\n", answer);
}