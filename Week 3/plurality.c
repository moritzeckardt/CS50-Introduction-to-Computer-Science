#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Task: https://cs50.harvard.edu/x/2021/psets/3/plurality/

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
} candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

// Main
int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Methods
bool vote(string name) // Update vote totals given a new vote
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;

            return true;
        }
    }

    return false;
}

void print_winner(void) // Print the winner (or winners) of the election
{
    int winner = -1;

    for (int i = 0; i < candidate_count; i++)
    {
        if (winner == -1)
        {
            if (candidates[i].votes > candidates[i + 1].votes)
            {
                winner = i;
            }
        }
        else
        {
            if (candidates[winner].votes < candidates[i + 1].votes)
            {
                winner = i + 1;
            }
        }
    }

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[winner].votes == candidates[i].votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
}
