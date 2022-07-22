// #include <cs50.h>       // Allows user to define string as data type and use get_string.
#include <stdio.h>      // Allows user to use printf and scanf.
#include <string.h>     // Allows user to use strlen.
#include <ctype.h>      // Allows user to use isdigit.

int main(int argc, char *argv[])
{
    // printf("argv: %i\n", (int)(argv[1]));
    // printf("argc: %i\n", argc);
    // If the user did not enter any command line arguments(CLA) or entered too many CLAs, we show them a message about how to use the program.
    if (argc == 1 || argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Check if the user has entered 26 characters for the substitution cipher.
    char *s = argv[1]; // Here we initialise a string called s with the second element of argv which holds the key.
    // printf("%c", s[0]); // Check if we can print the elements in the string which the user has given us.
    int noc = strlen(s); // noc = Number of characters.
    if (noc < 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // Here we iterate over all the elements in the key to check if the key is valid.
    for (int i = 0; i < noc; i++)
    {
        if (s[i] < 65 || s[i] > 90) // This checks if the elements are uppercase characters.
        {
            if (s[i] < 97 || s[i] > 122) // This checks if the elements are lowercase characters. If they are not characters, display the error message. 
            {
                printf("Key must only contain characters.\n");
                return 1;
            }
        }

        for (int j = 0; j < noc; j++)
        {
            if (i != j)
            {
                if (s[i] == s[j]) // This checks if there is a duplicate by comparing the i-th element with every other element using the j-th index.
                {
                    printf("Key must contain 26 unique characters. No duplicates.\n");
                    return 1;
                }
            }

        }
    }

    // Get the plaintext from the user
    char plaint[200];
    printf("plaintext: ");
    fgets(plaint, sizeof(plaint), stdin);
    // string plaint = get_string("plaintext: ");
    // printf("First letter: %c\n", plaint[0]);


    // Substitute the letters in the plaintext with the ones in the key the user entered.
    char ciphert;
    int n = strlen(plaint);
    printf("ciphertext: ");
    for (int i = 0; i < n; i++) // Here we iterate over all the elements of the plain text.
    {
        if (plaint[i] >= 65 && plaint[i] <= 90) // Checks if the character is an uppercase character.
        {
            int alpn = plaint[i] - 65;
            ciphert = s[alpn];
            if (islower(ciphert))
            {
                printf("%c", toupper(ciphert));
            }
            else
            {
                printf("%c", ciphert);
            }
        }

        else if (plaint[i] >= 97 && plaint[i] <= 122) // Checks if the character is an lowercase character.
        {
            int alpn = plaint[i] - 97;
            ciphert = s[alpn];
            if (isupper(ciphert))
            {
                printf("%c", tolower(ciphert));
            }
            else
            {
                printf("%c", ciphert);
            }
        }

        else
        {
            printf("%c", plaint[i]); // This prints the spacebars and punctuations as they are.
        }

    }
    // printf("\n"); // Lastly we print a new line for clarity of the cipher text.
}