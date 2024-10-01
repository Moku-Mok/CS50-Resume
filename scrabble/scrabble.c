#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int evaluate(string word);
int pointArray[] = {1,	3,	3,	2,	1,	4,	2,	4,	1,	8,	5,	1,	3,	1,	1,	3,	10,	1,	1,	1,	1,	4,	4,	8,	4, 10};

int main(void)
{


    string p1 = get_string("Player 1: ");
    string p2 = get_string("Player 2: ");

    int points1 = evaluate(p1);
    int points2 = evaluate(p2);

    if (points1 > points2)
    {
        printf("Player 1 wins!\n");
    }
    else if (points1 < points2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}


int evaluate(string word)
{
    int points = 0;

    for (int i = 0, len = strlen(word); i < len; i++)
    {
        if(isupper(word[i]))
        {
            points += pointArray[word[i] - 'A'];
        }

        else if (islower(word[i]))
        {
            points += pointArray[word[i] - 'a'];
        }
    }

    return points;
}
