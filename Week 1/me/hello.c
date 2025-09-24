#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // prompt user for their name
    string name = get_string("What's your name? ");

    // greet them by their name
    printf("hello, %s\n", name);
}
