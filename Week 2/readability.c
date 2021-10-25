#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//Task: https://cs50.harvard.edu/x/2021/psets/2/readability/

//Prototypes
int calculate_grade(string text);

//Main
int main(void)
{
    string text = get_string("Text: ");

    int index = calculate_grade(text);

    if (index > 0 && index < 16)
    {
        printf("Grade %i\n", index);
    }

    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }

    else if (index > 15)
    {
        printf("Grade 16+\n");
    }
}

//Methods
int calculate_grade(string text)
{
    //Variables
    float amount_of_letters = 0;
    float amount_of_words = 1;
    float amount_of_sentences = 0;
    float average_number_of_letters_l = 0;
    float average_number_of_sentences_s = 0;

    //Determines amount of letters, words and sentences
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        char letter = toupper(text[i]);
        int letter_as_number = letter;

        if (letter_as_number > 64 && letter_as_number < 91)
        {
            amount_of_letters++;
        }

        else if (letter == ' ')
        {
            amount_of_words++;
        }

        else if (letter == '.' || (letter == '?' || letter == '!'))
        {
            amount_of_sentences++;
        }
    }

    //Calculates value of s and l
    average_number_of_letters_l = amount_of_letters / amount_of_words * 100;
    average_number_of_sentences_s = amount_of_sentences / amount_of_words * 100;

    float index = round((0.0588 * average_number_of_letters_l) - (0.296 * average_number_of_sentences_s) - 15.8);

    return index;
}