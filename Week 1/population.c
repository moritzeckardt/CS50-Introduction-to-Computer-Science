#include <stdio.h>
#include <cs50.h>
#include <math.h>

// Task: https://cs50.harvard.edu/x/2021/labs/1/population/

int main(void)
{
    //Variables
    int startingPopulationSize;
    int currentPopulationSize;
    int endingPopulationSize;
    int requiredYears = 0;

    // TODO: Prompt for start size
    do
    {
        startingPopulationSize = get_int("Enter the starting population size of the llamas (equal or greater than 9): ");
    } while (startingPopulationSize < 9);

    // TODO: Prompt for end size
    do
    {
        endingPopulationSize = get_int("Enter the ending population size of the llamas (equal or greater than starting population size): ");
    } while (endingPopulationSize < startingPopulationSize);

    // TODO: Calculate number of years until we reach threshold
    currentPopulationSize = startingPopulationSize;

    while (currentPopulationSize < endingPopulationSize)
    {
        currentPopulationSize = round(currentPopulationSize + (currentPopulationSize / 3) - (currentPopulationSize / 4));

        requiredYears++;
    }

    // TODO: Print number of years
    printf("Years: %i\n", requiredYears);
}
