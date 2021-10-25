#include <stdio.h>
#include <cs50.h>
#include <string.h>

// Task: https://cs50.harvard.edu/x/2021/psets/1/credit/
// Note: It is probably not the cleanest way of solving this problem set

//Prototypes
int calculate_checksum(long card_number);
bool validate_checksum(int checksum);
string check_card_type(long card_number);

//Global variables
int counter = 0; //Used for calculating the checksum, but also indicates the card's length

// Main
int main(void)
{
    long card_number = get_long("Type in a valid card number: ");

    int checksum = calculate_checksum(card_number);

    bool card_evaluation = validate_checksum(checksum);

    if (card_evaluation == true && (counter == 13 || counter == 15 || counter == 16))
    {
        string card_type = check_card_type(card_number);

        printf("%s\n", card_type);
    }
    else
    {
        printf("INVALID\n");
    }
}

//Functions
int calculate_checksum(long card_number)
{
    //Variables
    int first_summand = 0;
    int second_summand = 0;

    while (card_number != 0)
    {
        if (counter % 2 != 0)
        {
            int digit = (card_number % 10) * 2;

            first_summand += digit / 10 + digit % 10;

            card_number /= 10;

            counter++;
        }
        else
        {
            second_summand += card_number % 10;

            card_number /= 10;

            counter++;
        }
    }

    return first_summand + second_summand;
}

bool validate_checksum(int checksum)
{
    int last_digit = checksum % 10;

    if (last_digit == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

string check_card_type(long card_number)
{
    while (card_number != 0)
    {
        if (card_number == 34 || card_number == 37)
        {
            return "AMEX";
        }
        else if ((card_number == 51 || card_number == 52 || card_number == 53 || card_number == 54 || card_number == 55))
        {
            return "MASTERCARD";
        }
        else if (card_number == 4)
        {
            return "VISA";
        }

        card_number /= 10;
    }

    return "INVALID";
}
