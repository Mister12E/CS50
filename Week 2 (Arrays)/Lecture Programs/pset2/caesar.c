// #include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // printf("argv: %i\n", (int)(argv[1]));
    // printf("argc: %i\n", argc);
    // Ensure that the user typed in 1 command-line argument. If the amount of arguments is not 2 then we display a message that tells the user how to use the program.
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Ensure every character in argv[1] is a digit
    char *s = argv[1]; // Here we initialise a string called s with the second element of argv which holds the key.
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (isdigit(s[i]) == 0)         //  This function returns a non-zero int if c is a decimal digit and 0 if c is not a decimal digit.
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // Convert argv[1] from a string to an int
    int key = atoi(argv[1]);
    // printf("Key integer: %i\n", key); // This checks if the second element in argv is converted to an integer.

    // Get the plaintext from the user
    char plaint[200];
    printf("plaintext: ");
    fgets(plaint, sizeof(plaint), stdin);
    // scanf("%s", plaint);
    // printf("Memory: %s", plaint);
    // char plaint = get_string("plaintext: ");
    // printf("First letter: %c\n", plaint[0]);

    // Add the key to the plaintext to produce the ciphertext
    int n = strlen(plaint);
    char ciphert;
    printf("ciphertext: ");
    for (int i = 0; i < n; i++) // Here we iterate over all the elements of the plain text.
    {
        if (plaint[i] >= 65 && plaint[i] <= 90) // Checks if the character is an uppercase character.
        {
            // printf("Uppercase\n");
            plaint[i] = plaint[i] - 65;
            ciphert = (plaint[i] + key) % 26 + 65;
            printf("%c", ciphert);
        }

        else if (plaint[i] >= 97 && plaint[i] <= 122) // Checks if the character is an lowercase character.
        {
            plaint[i] = plaint[i] - 97;
            ciphert = (plaint[i] + key) % 26 + 97;
            printf("%c", ciphert);
        }

        else
        {
            printf("%c", plaint[i]); // This prints the spacebars and punctuations as they are.
        }
    }
    // printf("\n"); // Lastly we print a new line for clarity of the cipher text.
}