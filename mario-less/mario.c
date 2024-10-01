#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    void buildpyramid(int);

    do
    {
        height = get_int("Height: ");
    }
    while (height < 1);

    buildpyramid(height);
}

void buildpyramid(int z)
{
    int i;
    int j;
    int k;
    int spaces;
    int bricks;

    for (i = z; i > 0; i--)
    {
        spaces = i - 1;
        bricks = z - spaces;

        for (j = spaces; j > 0; j--)
        {
            printf(" ");
        }

        for (k = bricks; k > 0; k--)
        {
            printf("#");
        }

        printf("\n");
    }
}
