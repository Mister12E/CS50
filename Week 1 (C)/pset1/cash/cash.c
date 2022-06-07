#include <stdio.h>
#include <math.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

// This function helps us to get the number of cents from the user and rejects any invalid input like negative numbers.
int get_cents(void)
{
    int cents;
    do
    {
        printf ("Change owed: ");
        scanf ("%d", &cents);
        // cents = get_int("Change owed: ");
    }
    while (cents < 1);
    return cents;
}

// This function calculates the number of quarters(25 cents) to give.
int calculate_quarters(int cents)
{
    int num_q = floor(cents / 25);
    return num_q;
}

// This function calculates the number of dimes(10 cents) to give.
int calculate_dimes(int cents)
{
    int num_d = floor(cents / 10);
    return num_d;
}

// This function calculates the number of nickels(5 cents) to give.
int calculate_nickels(int cents)
{
    int num_n = floor(cents / 5);
    return num_n;
}

// This function calculates the number of pennies(1 cent) to give.
int calculate_pennies(int cents)
{
    int num_p = floor(cents / 1);
    return num_p;
}