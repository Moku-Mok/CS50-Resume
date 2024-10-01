#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int size = 5;
    int list[size];

    for (int i = 0; i < size; i++)
    {
        list[i] = i;
        printf("%i", list[i]);
    }

}
