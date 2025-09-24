#include <cs50.h>
#include <stdio.h>

// function prototypes
int get_positive_int(void);
void pyramid(int height);

int main(void)
{
    // get valid input from user
    int height = get_positive_int();

    // print pyramid of given height
    pyramid(height);
}

// function to get valid input from user
int get_positive_int(void)
{
    int height;

    do
    {
        height = get_int("Height: ");
    }
    while (height < 1);

    return height;
}

// print pyramid of given height
void pyramid(int height)
{
    // print each row of the pyramid from top to bottom
    for (int i = 1; i <= height; i++)
    {
        // 1. calculate spaces before brick
        int spaces = height - i;

        // 2. print spaces
        for (int j = 0; j < spaces; j++)
        {
            printf(" ");
        }

        // 3. print bricks of the pyramid
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }

        // 4. print new line
        printf("\n");
    }
}
