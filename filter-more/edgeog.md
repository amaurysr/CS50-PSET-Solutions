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
            long long GXRed = 0, GYRed = 0;
            long long GXBlue = 0, GYBlue = 0;
            long long GXGreen = 0, GYGreen = 0;
            for(int k = -1, kh = k + 1, nh = i + k; k <= 1; k++)
            {
                for(int l = -1, kl = l + 1, nw = l + j; l <= 1; l++)
                {
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