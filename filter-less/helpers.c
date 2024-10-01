#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            int average = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);

            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }


    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            int sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            int sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if ( sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }

    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE tempstore = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = tempstore;

        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int counter = 0;
    float averageRed = 0.0;
    float averageGreen = 0.0;
    float averageBlue = 0.0;
    RGBTRIPLE tempstore[height][width];


    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //Reset counter and averages to 0
            counter = 0;
            averageRed = 0;
            averageGreen = 0;
            averageBlue = 0;

            //loop to get pixels above and below height
            for (int k = i - 1; k <= i + 1 && k < height; k++)
            {
                //if index out of bounds make it 0
                if (k < 0)
                {
                    continue;
                }

                //loop to get pixels to the left and right of width
                for (int l = j - 1; l <= j + 1 && l < width; l++)
                {
                    if (l < 0)
                    {
                        continue;
                    }

                    //add values to the average and up the counter
                    counter++;
                    averageRed += image[k][l].rgbtRed;
                    averageGreen += image[k][l].rgbtGreen;
                    averageBlue += image[k][l].rgbtBlue;

                }
            }

            //update temp array with averaged values
            tempstore[i][j].rgbtRed = round(averageRed / counter);
            tempstore[i][j].rgbtGreen = round(averageGreen / counter);
            tempstore[i][j].rgbtBlue = round(averageBlue / counter);
        }
    }

    //Finish the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = tempstore[i][j];
        }
    }
    return;
}
