#include <cs50.h>
#include <stdio.h>

// Function prototypes
int get_positive_int(void);
void pyramid(int n);

int main(void)
{
    // get a valid positive height from user
    int height = get_positive_int();

    // print pyramid of given height
    pyramid(height);
}

// function to prompt user to get input between 1 and 8
int get_positive_int(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height > 8 || height < 1);

    return height;
}

// function to print mirrored pyramid of given height
void pyramid(int n)
{
    for (int i = 1; i <= n; i++)
    {
        // calculate spaces
        int space = n - i;

        // print a row

        // 1. print number of spaces required
        for (int j = 0; j < space; j++)
        {
            printf(" ");
        }

        // 2. print left pyramid col
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }

        // 3. print two additional spaces between pyramids
        printf("  ");

        // 4. print right pyramid
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }

        // 4. print next line
        printf("\n");
    }
}
