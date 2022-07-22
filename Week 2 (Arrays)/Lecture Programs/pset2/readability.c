// #include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

float count_letters(char *s);   // This counts the number of letters in the user's string.
float count_words(char *s);     // This counts the number of words in the user's string.
float count_sentences(char *s); // This counts the number of sentences in the user's string.

// This program takes any amount of words from the user then uses the Coleman-Liau index to determine it's grade of readability.
int main(void)
{
    char s[200];
    // This asks the user for a string of text.
    printf ("Text: ");
    fgets(s, sizeof(s), stdin);
    printf("%s", s); // This checks if the string is correct. 

    // Declaration of variables.
    float L = 0, s1 = 0, clets = 0, cwords = 1, csents = 0;
    int index = 0;

    // Check how many letters are there.
    clets = count_letters(s);
    // printf("%f\n", clets); // Used to check if the number of letters are correct.

    // Check how many words are there.
    cwords = count_words(s);
    // printf("%f\n", cwords); // Used to check if the number of words are correct.

    // Check how many sentences are there.
    csents = count_sentences(s);
    // printf("%f\n", csents); // Used to check if the number of sentences are correct.

    L = (clets / cwords) * 100;                    // L is the average number of letters per 100 words.
    s1 = (csents / cwords) * 100;                  // s1 is the average number of sentences per 100 words. 
    index = round(0.0588 * L - 0.296 * s1 - 15.8); // This is the index that we use to calculate the readability grade.
    // printf("L: %f, S: %f, index: %i \n", L, s1, index);  // Used to check if L, S and the index is correct.
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

float count_letters(char *s)
{
    float clets = 0;
    // This for loop helps us to run through the whole string.
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        // This checks for the number of letters a to z and A to Z using the ACSII values.
        if ((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122))
        {
            clets = clets + 1;
        }
    }
    return clets;
}

float count_words(char *s)
{
    float cwords = 1;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        // This checks for the number words by adding 1 whenever a spacebar is encountered. The value starts at 1 to account for the last word which does not have the spacebar.
        if (s[i] == 32)
        {
            cwords = cwords + 1;
        }
    }
    return cwords;
}

float count_sentences(char *s)
{
    float csents = 0;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        // This checks for the number of sentences by adding 1 whenever an exclaimation point, period or question mark is encountered.
        if (s[i] == 33 || s[i] == 46 || s[i] == 63)
        {
            csents = csents + 1;
        }
    }
    return csents;
}

/* This was how I coded the program without knowing how to pass strings to variables. 
int main(void)
{
    char s[200];
    // This asks the user for a string of text.
    printf ("Text: ");
    fgets(s, sizeof(s), stdin);
    // printf("%s", s); // This checks if the string is correct. 

    float L = 0, s1 = 0, clets = 0, cwords = 1, csents = 0;
    int index = 0;

    for(int i = 0, n = strlen(s); i < n; i++)
    {
        if((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122))
        {
            clets = clets + 1;
        }
        else if(s[i] == 32)
        {
            cwords = cwords + 1;
        }
        else if(s[i] == 33 || s[i] == 46 || s[i] == 63)
        {
            csents = csents + 1;
        }
    }
    printf("Number of letters: %f\n", clets);
    printf("Number of words: %f\n", cwords);
    printf("Number of sentences: %f\n", csents);

    L = (clets / cwords) * 100;
    s1 = (csents/cwords) * 100;
    index = round(0.0588 * L - 0.296 * s1 - 15.8);
    printf("L: %f, S: %f, index: %i \n", L, s1, index);
    if(index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if(index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}
*/

/* This was how I coded the program in CS50 with functions and passing the string variable.
float count_letters(char s);   // This counts the number of letters in the user's string.
float count_words(char s);     // This counts the number of words in the user's string.
float count_sentences(char s); // This counts the number of sentences in the user's string.

// This program takes any amount of words from the user then uses the Coleman-Liau index to determine it's grade of readability.
int main(void)
{
    char s[200];
    // This asks the user for a string of text.
    printf ("Text: ");
    fgets(s, sizeof(s), stdin);
    // scanf ("%s", s); // We cannot use scanf as it will not read whitespaces like the spacebar which means that words after the spacebar will be missing. 
    // string s = get_string("Text: ");

    // Declaration of variables.
    float L = 0, s1 = 0, clets = 0, cwords = 1, csents = 0;
    int index = 0;

    // Check how many letters are there.
    clets = count_letters(s);
    // printf("%f\n", clets); // Used to check if the number of letters are correct.

    // Check how many words are there.
    cwords = count_words(s);
    // printf("%f\n", cwords); // Used to check if the number of words are correct.

    // Check how many sentences are there.
    csents = count_sentences(s);
    // printf("%f\n", csents); // Used to check if the number of sentences are correct.

    L = (clets / cwords) * 100;                    // L is the average number of letters per 100 words.
    s1 = (csents / cwords) * 100;                  // S is the average number of sentences per 100 words
    index = round(0.0588 * L - 0.296 * s1 - 15.8); // This is the index that we use to calculate the readability grade.
    // printf("L: %f, S: %f, index: %i \n", L, s1, index);  // Used to check if L, S and the index is correct.
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

float count_letters(char s)
{
    float clets = 0;
    // This for loop helps us to run through the whole string.
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        // This checks for the number of letters a to z and A to Z using the ACSII values.
        if ((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122))
        {
            clets = clets + 1;
        }
    }
    return clets;
}

float count_words(char s)
{
    float cwords = 1;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        // This checks for the number words by adding 1 whenever a spacebar is encountered. The value starts at 1 to account for the last word which does not have the spacebar.
        if (s[i] == 32)
        {
            cwords = cwords + 1;
        }
    }
    return cwords;
}

float count_sentences(char s)
{
    float csents = 0;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        // This checks for the number of sentences by adding 1 whenever an exclaimation point, period or question mark is encountered.
        if (s[i] == 33 || s[i] == 46 || s[i] == 63)
        {
            csents = csents + 1;
        }
    }
    return csents;
}
*/

/* This is how I originally coded this program without creating the functions.
string s = get_string("Text: ");
// printf("%s\n", s);
int index = 0;
float L = 0, s1 = 0, clets = 0, cwords = 1, csents = 0;

// This for loop counts the nunmber of letters and words. 32 = Spacebar / 33 = Exclaimation point / 46 = Period / 63 = Question mark
for(int i = 0, n = strlen(s); i < n; i++)
{
     if((s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122))
     {
         clets = clets + 1;
     }
     else if(s[i] == 32)
     {
         cwords = cwords + 1;
     }
     else if(s[i] == 33 || s[i] == 46 || s[i] == 63)
     {
        csents = csents + 1;
     }
}
// This lets me see if the number of letters, words and sentences are correct.
printf("Number of letters: %f\n", clets);
printf("Number of words: %f\n", cwords);
printf("Number of sentences: %f\n", csents);

L = (clets / cwords) * 100;
s1 = (csents/cwords) * 100;
index = round(0.0588 * L - 0.296 * s1 - 15.8);
printf("L: %f, S: %f, index: %i \n", L, s1, index);
if(index < 1)
{
printf("Before Grade 1\n");
}
else if(index >= 16)
{
printf("Grade 16+\n");
}
else
{
printf("Grade %i\n", index);
}
*/