#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float avarageValue = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = avarageValue;
            image[i][j].rgbtGreen = avarageValue;
            image[i][j].rgbtBlue = avarageValue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = (width / 2) - 1; j >= 0; j--)
        {

            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;

        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            int tempRed = 0;
            int tempGreen = 0;
            int tempBlue = 0;
            float pixelCount = 0;

            for (int m = -1; m < 2; m++)
            {
                for (int n = -1; n < 2; n++)
                {
                    if ((i + m >= 0 && i + m < height) && (j + n >= 0 && j + n < width))
                    {
                        tempRed += image[i + m][j + n].rgbtRed;
                        tempGreen += image[i + m][j + n].rgbtGreen;
                        tempBlue += image[i + m][j + n].rgbtBlue;
                        pixelCount++;
                    }
                }
            }

            temp[i][j].rgbtRed = round(tempRed / pixelCount);
            temp[i][j].rgbtGreen = round(tempGreen / pixelCount);
            temp[i][j].rgbtBlue = round(tempBlue / pixelCount);
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{

    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int redx = 0;
            int greenx = 0;
            int bluex = 0;
            int redy = 0;
            int greeny = 0;
            int bluey = 0;

            for (int m = -1; m < 2; m++)
            {
                for (int n = -1; n < 2; n++)
                {
                    if ((i + m >= 0 && i + m < height) && (j + n >= 0 && j + n < width))
                    {
                        redx += image[i  + m][j  + n].rgbtRed * Gx[m + 1][ n + 1];
                        greenx += image[i + m][j  + n].rgbtGreen * Gx[m + 1][n + 1];
                        bluex += image[i + m][j  + n].rgbtBlue * Gx[m + 1][n + 1];

                        redy += image[i + m][j  + n].rgbtRed * Gy[m + 1][n + 1];
                        greeny += image[i  + m][j  + n].rgbtGreen * Gy[m + 1][n + 1];
                        bluey += image[i  + m][j  + n].rgbtBlue * Gy[m + 1][n + 1];
                    }
                }
            }

            int red = round(sqrt((redx * redx) + (redy * redy)));
            int green = round(sqrt((greenx * greenx) + (greeny * greeny)));
            int blue = round(sqrt((bluex * bluex) + (bluey * bluey)));

            if (red > 255)
            {
                red = 255;
            }
            if (green > 255)
            {
                green = 255;
            }
            if (blue > 255)
            {
                blue = 255;
            }

            temp[i][j].rgbtRed = red;
            temp[i][j].rgbtGreen = green;
            temp[i][j].rgbtBlue = blue;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
        }
    }
    return;
    return;
}
