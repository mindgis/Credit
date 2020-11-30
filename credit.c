#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    long number, number1, number2, lastdigit1, lastdigit2, sum1, sum2;
    // Get card number
    do
    {
        number = get_long("Number: ");
    }
    while (number < 99999999 || number > 10000000000000000);

    // Sum of digits that weren't multiplied
    number1 = number;
    sum1 = 0;
    for (long row = 0; row < 16; row++)
    {
        lastdigit1 = number1 % 10;
        number1 = number1 / 100;
        sum1 = sum1 + lastdigit1;
    }

    // Sum of products digits mulplied by two
    number2 = number;
    sum2 = 0;
    for (long row = 0; row < 16; row++)
    {
        number2 = number2 / 10;
        lastdigit2 = number2 % 10;
        number2 = number2 / 10;
        if (lastdigit2 * 2 > 9)
        {
            sum2 = sum2 + (lastdigit2 * 2 % 10) + (lastdigit2 * 2 / 10);
        }
        else
        {
            sum2 = sum2 + (lastdigit2 * 2);
        }
    }

    // Check if last digit of the card is 0
    if ((sum1 + sum2) % 10 == 0)
    {
        // If AMEX
        if (number / 10000000000000 == 34 || number / 10000000000000 == 37)
        {
            printf("AMEX\n");
        }
        // If VISA
        else if (number / 1000000000000000 == 4 || number / 1000000000000 == 4)
        {
            printf("VISA\n");
        }
        // If MASTERCARD
        else if (number / 100000000000000 < 56 && number / 100000000000000 > 50)
        {
            printf("MASTERCARD\n");
        }
        // If OTHER
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
