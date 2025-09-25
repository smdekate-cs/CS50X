#include <cs50.h>
#include <stdio.h>

// function prototype
int get_positive_int(void);
void print_coins(int change);

int main()
{
    // prompt user for valid input, change owed.
    int change = get_positive_int();

    // print minimum number of coins that sum up to the change owed
    print_coins(change);
}

// function to get valid positive integer input from user
int get_positive_int(void)
{
    int number;
    do
    {
        number = get_int("Change owed: ");
    }
    while (number < 0);

    return number;
}

// function to calculate minimum number of coins
void print_coins(int change)
{
    int coins = 0;

    // implement greedy appoach to minimize the number of coins
    while (change >= 25)
    {
        change -= 25;
        coins++;
    }

    while (change >= 10)
    {
        change -= 10;
        coins++;
    }

    while (change >= 5)
    {
        change -= 5;
        coins++;
    }

    while (change >= 1)
    {
        change--;
        coins++;
    }

    // finally print the coins
    printf("%i\n", coins);
}
