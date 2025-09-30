#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Prototype
int get_score(string s);

int main(void)
{
    // Prompt the user for two words
    string player1 = get_string("Player 1: ");
    string player2 = get_string("Player 2: ");

    // Compute the score of each word
    int p1_score = get_score(player1);
    int p2_score = get_score(player2);

    // Decide winner and print the winner
    if (p1_score > p2_score)
    {
        printf("Player 1 wins!\n");
    }
    else if (p1_score < p2_score)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

// calculate score of a word
int get_score(string s)
{
    // array to hold score of each letter
    int letter_score[26] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                               1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    // conver string to lower case
    int n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        s[i] = tolower(s[i]);
    }

    // calculate the score for a given word
    int score = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            score += letter_score[s[i] - 'a'];
        }
    }

    return score;
}
