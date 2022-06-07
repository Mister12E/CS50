#include <stdio.h>

// This program prints out 2 triangles. 1 right aligned triangle and 1 left aligned triangle seperated by 2 spaces.
int main(void)
{
    // First, we declare the variable h which will store the height the user enters.
    int h;

    // Second, we create a do while loop that asks the user for a number between 1 and 8. If the number is out of this range, it will ask the user again.
    do
    {
         printf ("Height: ");
        scanf ("%d", &h);
        // h = get_int("Height: ");
    }
    while (h < 1 || h > 8);

    // Third, we create a for loop that counts the number of rows.
    for (int i = 1; i <= h; i++)
    {
        // Fourth, we create another for loop that prints the spaces by starting at 1 and ending at height value - row number. E.g If it is on row 3 and the height is 5, this will only print 2 spaces.
        for (int j = 1; j <= (h - i); j++)
        {
            printf(" ");
        }

        // Fifth, we create another for loop that prints the # by starting at 1 and ending at the row number. E.g If it is on row 3, it will only print 3 #. This is placed after the spaces so that the spaces will be printed first.
        for (int k = 1; k <= i ; k++)
        {
            printf("#");
        }

        // Sixth, we print 2 spaces to seperate the 2 triangles.
        printf("  ");

        // Seventh, we print the left aligned triangle by starting at 1 and ending at the row number. E.g If it is on row 3, it will only print 3 #.
        for (int m = 1; m <= i; m++)
        {
            printf("#");
        }

        // This prints the new line that is required when we move from row to row.
        printf("\n");
    }
}