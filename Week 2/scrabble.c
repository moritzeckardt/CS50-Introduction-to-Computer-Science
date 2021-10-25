#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

//Task: https://cs50.harvard.edu/x/2021/labs/2/

//Prototypes
int compute_score(string word);

//Variables
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

//Main
int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

//Methods
int compute_score(string word)
{
    //Variables
    int score = 0;

    // TODO: Compute and return score for string
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        char c = toupper(word[i]);
        int c_as_int = c;

        score += POINTS[c_as_int - 65];
    }

    return score;
}