// Implements a dictionary's functionality
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

#include "dictionary.h"

// Task: https://cs50.harvard.edu/x/2021/psets/5/speller/

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Additonal global variables
int dict_count = 0; // Count for words in dictionary
int location = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    location = hash(word);

    node *cursor = table[location];
    while (cursor)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }

        cursor = cursor->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // Easy solution:
    /*if (word[0] > 64 && word[0] < 91)
    {
        return word[0] - 65;
    }

    else if (word[0] > 96 && word[0] < 123)
    {
        return word[0] - 97;
    }
    
    return 0;*/

    // Efficient solution
    int sum = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        sum += tolower(word[i]);
    }

    return (sum % N);
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Variables
    char word[LENGTH + 1];

    // Open file
    FILE *dict = fopen(dictionary, "r");
    if (!dict)
    {
        printf("Could not open %s.\n", dictionary);
        return false;
    }

    // Read from dictionary
    while ((fscanf(dict, "%s", word)) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (!n)
        {
            printf("Could not allocate memory.\n");
            return false;
        }

        strcpy(n->word, word);
        n->next = NULL;

        location = hash(n->word);
        if (table[location] == NULL)
        {
            table[location] = n;
        }
        else
        {
            n->next = table[location];
            table[location] = n;
        }

        dict_count++;
    }

    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return dict_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        while (table[i] != NULL)
        {
            node *tmp = table[i]->next;
            free(table[i]);
            table[i] = tmp;
        }
    }

    return true;
}
