#include <stdio.h>
#include <cs50.h>

// Task: https://cs50.harvard.edu/x/2021/psets/1/mario/more/

int main(void)
{
    // Variables
    int height;
    int amountOfSpaces;
    int amountOfHashes = 1;

    // Enter height & determine amount of spaces
    do
    {
        height = get_int("Enter the height of both pyramides (1 - 8): ");
    } while (height < 1 || height > 8);

    amountOfSpaces = height - 1;

    // Build pyramide
    for (int i = 0; i < height; i++)
    {
        for (int k = 0; k < amountOfSpaces; k++)
        {
            printf(" ");
        }

        for (int j = 0; j < amountOfHashes; j++)
        {
            printf("#");
        }

        printf("  ");

        for (int n = 0; n < amountOfHashes; n++)
        {
            printf("#");
        }

        printf("\n");

        amountOfHashes++;

        amountOfSpaces--;
    }
}
