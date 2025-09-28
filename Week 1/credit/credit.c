#include <cs50.h>
#include <stdio.h>

// function prototype
long get_credit_number(void);
int get_digits(long n);
bool luhn_check(long number);
string provider(long number);
int get_digit_sum(int n);

int main(void)
{
    // prompt user to get valid credit card number
    long number = get_credit_number();

    // print provider
    printf("%s\n", provider(number));
}

// function to get valid credit card number
long get_credit_number(void)
{
    long number;
    do
    {
        number = get_long("Number: ");
    }
    while (number < 0);
    return number;
}

int get_digit_sum(int n)
{
    int sum = 0;

    while (n > 0)
    {
        sum = sum + n % 10;
        n = n / 10;
    }

    return sum;
}

// Luhn's Algorithm for validity check
bool luhn_check(long number)
{
    // from second-to-last mutiliply each number by two
    // and add it's digit
    int sum1 = 0; // hold sum of every other digit from last digit
    int sum2 =
        0; // hold sum of every other digit from second-to-last digit after required operation
    int i = 1;

    while (number > 0)
    {
        int last_digit = number % 10;
        if (i % 2 == 0)
        {
            last_digit *= 2;
            sum2 += get_digit_sum(last_digit);
        }
        else
        {
            sum1 += last_digit;
        }
        i++;
        number /= 10;
    }

    // now add both sums
    int final = sum1 + sum2;

    // the card is valid if last digit of final is 0 else invalid
    return (final % 10) == 0;
}

// function to calculate digits in a number
int get_digits(long number)
{
    int digits = 0;

    while (number > 0)
    {
        digits++;
        number /= 10;
    }
    // printf("digits: %i\n", digits);

    return digits;
}

// check for provider
string provider(long number)
{
    // check for luhn's algorithm
    bool syntax = luhn_check(number);

    // get the digits in a card number
    int digits = get_digits(number);

    // check for VISA with 13 digit card number
    if (syntax && digits == 13)
    {
        int prefix = number / 1000000000000;
        if (prefix == 4)
        {
            return "VISA";
        }
    }

    // check for American Express
    else if (syntax && digits == 15)
    {
        int prefix = number / 10000000000000;
        if (prefix == 34 || prefix == 37)
        {
            return "AMEX";
        }
    }

    // check for MASTER CARD and VISA with 16 digit card number
    else if (syntax && digits == 16)
    {
        int prefix = number / 100000000000000;
        if (prefix == 51 || prefix == 52 || prefix == 53 || prefix == 54 || prefix == 55)
        {
            return "MASTERCARD";
        }
        else
        {
            prefix = number / 1000000000000000;
            if (prefix == 4)
            {
                return "VISA";
            }
        }
    }

    // anything else will be invalid
    return "INVALID";
}
