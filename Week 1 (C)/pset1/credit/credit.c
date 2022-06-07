#include <stdio.h>

long get_cnum(void);            // This prompts the user to enter the credit card number. It will reject negative numbers.
int check_cnum(long cnum);      // This checks if the credit card number is valid using Luhn’s Algorithm.
void get_ctype(long cnum);      // This checks which type of credit card number it is.

int main(void)
{
    // Ask the user for the credit card number.
    long cnum = get_cnum();
    // printf("%li \n", cnum); // Used to check if the number is getting stored correctly.

    // Calculate check sum to check if its a valid credit card number
    int check = check_cnum(cnum);
    // printf ("%i \n", check); // Used to check if the check is passed. 1 is passed. 2 is failed.

    // Check how many digits are in the credit card number. If there are 15 digits, it is AMEX. If there are 16 digits, it is MASTERCARD. If there are 13 or 16 digits, it is VISA.
    if (check == 1)
    {
        get_ctype(cnum);
    }
    else
    {
        printf("INVALID\n");
    }
}

// This prompts the user to enter the credit card number. It will reject negative numbers.
long get_cnum(void)
{
    long cnum;
    do
    {
        printf("Number: ");
        scanf("%li", &cnum);
        // cnum = get_long("Number: ");
    }
    while (cnum < 1);
    return cnum;
}


// This checks if the credit card number is valid using Luhn’s Algorithm.
int check_cnum(long cnum)
{
    int odd_sum = 0, even_sum = 0;
    while (cnum != 0)
    {
        odd_sum = odd_sum + cnum % 10;                      // This adds the last digit and every alternate number to odd_sum.
        cnum = cnum / 10;                                   // This then divides the credit card number by 10.
        even_sum = even_sum + (((cnum % 10) * 2) % 10);     // This adds the second last number multiplied by 2 and every alternate number
                                                            // to even_sum.
        if (((cnum % 10) * 2) >= 10)                        // This checks if the product is greater than 10. If so, we split the numbers
                                                            // and add them to even_sum.
        {
            even_sum = even_sum + 1;
        }
        cnum = cnum / 10;                                   // This then divides the credit card number by 10.
    }
    // printf ("Odd: %i, Even: %i\n", odd_sum, even_sum);   // This is used to check the odd_sum and even_sum.
    if ((odd_sum + even_sum) % 10 == 0)                     //This checks if the sum of odd_sum and even_sum is divisible by 10. If it is,
                                                            // it returns the integer 1. If not, it returns the integer 2.
    {
        return 1;
    }
    else
    {
        return 2;
    }
}


// This checks which type of credit card number it is.
void get_ctype(long cnum)
{
    int amt_num = 0;
    long cnum2 = cnum;
    long cnum3 = cnum;
    long cnum4 = cnum;

    // This while loop is used to find put how many numbers are there in the credit card.
    while (cnum != 0)
    {
        // printf("%li\n", cnum % 10);
        cnum = cnum / 10;
        amt_num = amt_num + 1;
    }
    // printf ("%i\n", amt_num); //Used to check if we are counting the right amount of digits.

    // Check if it is an AMEX credit card. Has 15 digits and starts with 34 or 37
    if (amt_num == 15)
    {
        while (cnum2 >= 100)            // This while loop divides the number until we are left with the first 2 digits.
        {
            cnum2 = cnum2 / 10;
        }
        // printf ("%li", cnum2); Used to check if the first 2 digits are correctly captured.
        if (cnum2 == 34 || cnum2 == 37) // If the first 2 digits are either 34 or 37, it is an AMEX credit card.
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");        // Or else, it is an invalid credit card number.
        }
    }

    // Check if it is a MASTERCARD credit card. Has 16 digits and starts with 51/52/53/54/55.
    else if (amt_num == 16)
    {
        while (cnum3 >= 100)
        {
            cnum3 = cnum3 / 10;
        }

        if (cnum3 >= 51 && cnum3 <= 55) // If the first 2 digits are 51/52/53/54/55, it is an AMEX credit card.
        {
            printf("MASTERCARD\n");
        }

        // Check if it is a VISA credit card. Has 16 digits and starts with 4.
        else if ((cnum3 /10) == 4)      // Some VISA card have 16 digits so we have to check if the first digit is 4.
        {
            printf("VISA\n");           // If the first digit is 4, it is a VISA credit card.
        }

        else
        {
            printf("INVALID\n");        // Or else, it is an invalid credit card number.
        }
    }

    // Check if it is a VISA credit card. Has 13 digits and starts with 4.
    else if (amt_num == 13)
    {
        while (cnum4 >= 10)
        {
            cnum4 = cnum4 / 10;
        }

        if (cnum4 == 4)
        {
            printf("VISA\n");
        }
    }

    else
    {
        printf("INVALID\n");
    }
}