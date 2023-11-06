#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            int sum = image[i][j].rgbtBlue + image[i][j].rgbtGreen+ image[i][j].rgbtRed;
            int average = (sum) / 3;
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i <= height/2 ; i++)
    {
        for(int j = 0; j < width; j++)
        {
            int oheight = height - i;
            int owidth = width - j;
            int tempblue = image[i][j].rgbtBlue;
            int tempgreen = image[i][j].rgbtGreen;
            int tempred = image[i][j].rgbtRed;

            image[i][j].rgbtBlue = image[oheight][owidth].rgbtBlue;
            image[oheight][owidth].rgbtBlue = tempblue;
            image[i][j].rgbtRed = image[oheight][owidth].rgbtRed;
            image[oheight][owidth].rgbtRed = tempred;
            image[i][j].rgbtGreen = image[oheight][owidth].rgbtGreen;
            image[oheight][owidth].rgbtGreen = tempgreen;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for(int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            int counter = 0;
            float greensum = 0, redsum = 0, bluesum = 0;
            for(int k = -1; k < 2; k++)
            {
                for(int l = -1; l < 2; l++)
                {
                    int newheight = k + i;
                    int newwidth = l + j;
                    if(newheight >= 0 || newwidth >= 0 || newheight <= height || newwidth <= width)
                    {
                        counter++;
                        greensum = greensum + copy[newheight][newwidth].rgbtGreen;
                        redsum = redsum + copy[newheight][newwidth].rgbtRed;
                        bluesum = bluesum + copy[newheight][newwidth].rgbtBlue;
                    }
                }
            }
            image[i][j].rgbtGreen = round(greensum) / counter;
            image[i][j].rgbtRed = round(redsum) / counter;
            image[i][j].rgbtBlue = round(bluesum) / counter;
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
    RGBTRIPLE copy[height][width];

    for(int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            double long GXRed = 0, GYRed = 0;
            double long GXBlue = 0, GYBlue = 0;
            double long GXGreen = 0, GYGreen = 0;
            for(int k = -1; k <= 1; k++)
            {
                int kh = k + 1;
                int nh = i + k;
                for(int l = -1; l <= 1; l++)
                {
                    int kl = l + 1;
                    int nw = l + j;
                    if(nh >= 0 && nh <= height - 1 && nw >= 0 && nw <= width - 1)
                    {
                        GXRed += (Gx[kh][kl] * copy[nh][nw].rgbtRed);
                        GXBlue += (Gx[kh][kl] * copy[nh][nw].rgbtBlue);
                        GXGreen += (Gx[kh][kl] * copy[nh][nw].rgbtGreen);

                        GYRed += (Gy[kh][kl] * copy[nh][nw].rgbtRed);
                        GYBlue += (Gy[kh][kl] * copy[nh][nw].rgbtBlue);
                        GYGreen += (Gy[kh][kl] * copy[nh][nw].rgbtGreen);
                    }

                }
            }

            double Red = sqrt((GXRed * GXRed) + (GYRed * GYRed));
            if (Red > 255)
            {
                Red = 255;
            }

            double Blue = sqrt((GXBlue * GXBlue) + (GYBlue * GYBlue));
            if (Blue > 255)
            {
                Blue = 255;
            }
            double Green = sqrt((GXGreen * GXGreen) + (GYGreen * GYGreen));
            if (Green > 255)
            {
                Green = 255;
            }
            image[i][j].rgbtRed = round(Red);
            image[i][j].rgbtBlue = round(Blue);
            image[i][j].rgbtGreen = round(Green);
        }
    }
    return;
}