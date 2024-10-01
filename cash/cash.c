#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int debt;
    int coinCount = 0;

    do
    {
        debt = get_int("Change owed: ");
    }
    while (debt < 0);

    while (debt > 0)
    {
        if (debt - 25 >= 0)
        {
            debt -= 25;
            coinCount += 1;
        }
        else if (debt - 10 >= 0)
        {
            debt -= 10;
            coinCount += 1;
        }
        else if (debt - 5 >= 0)
        {
            debt -= 5;
            coinCount += 1;
        }
        else if (debt - 1 >= 0)
        {
            debt -= 1;
            coinCount += 1;
        }
    }
    printf("%i\n", coinCount);
}

