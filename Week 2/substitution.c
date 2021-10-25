#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

//Task: https://cs50.harvard.edu/x/2021/psets/2/substitution/

//Prototypes
void print_ciphertext(string plaintext, string key, int key_length);

//Main
int main(int argc, string argv[])
{
    //Variables
    string key = argv[1];
    int key_length = strlen(argv[1]);

    //Validate key, get user input & execute method
    if (argc == 2)
    {
        if (key_length == 26)
        {
            for (int i = 0; i < key_length; i++)
            {

                if (!isalpha(key[i]))
                {
                    printf("Key must contain 26 characters.\n");

                    return 1;
                }

                for (int j = i + 1; j < key_length; j++)
                {

                    if (toupper(key[j]) == toupper(key[i]))
                    {
                        printf("Key must not contain repeated alphabets.\n");

                        return 1;
                    }
                }
            }

            string plaintext = get_string("plaintext:  ");

            print_ciphertext(plaintext, key, key_length);
        }
        else
        {
            printf("Key must contain 26 characters.\n");

            return 1;
        }
    }
    else
    {
        printf("Usage: ./substitution key\n");

        return 1;
    }

    return 0;
}

//Methods
void print_ciphertext(string plaintext, string key, int key_length)
{
    //Variables
    int plaintext_length = strlen(plaintext);
    int alphabetic_plaintext[plaintext_length];
    string cyphertext = "hut";

    //Save plaintext as an array in alphabetic order with numbers
    for (int i = 0; i < plaintext_length; i++)
    {
        if (plaintext[i] > 64 && plaintext[i] < 91)
        {
            alphabetic_plaintext[i] = plaintext[i] - 65;
        }

        else if (plaintext[i] > 96 && plaintext[i] < 123)
        {
            alphabetic_plaintext[i] = plaintext[i] - 97;
        }

        else
        {
            alphabetic_plaintext[i] = plaintext[i];
        }
    }

    //Create & print cyphertext
    printf("ciphertext: ");

    for (int i = 0; i < plaintext_length; i++)
    {
        int number = alphabetic_plaintext[i];

        if (islower(plaintext[i]))
        {
            printf("%c", tolower(key[number]));
        }

        else if (isupper(plaintext[i]))
        {
            printf("%c", toupper(key[number]));
        }

        else
        {
            printf("%c", alphabetic_plaintext[i]);
        }
    }

    printf("\n");
}
