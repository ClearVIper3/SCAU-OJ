#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i=0;i<height;i++)
    {
        for(int u=0;u<width;u++)
        {
            int a=(image[i][u].rgbtBlue+image[i][u].rgbtGreen+image[i][u].rgbtRed+1.5)/3.0;
            image[i][u].rgbtBlue=a;
            image[i][u].rgbtGreen=a;
            image[i][u].rgbtRed=a;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i=0;i<height;i++)
    {
        for(int u=0;u<width;u++)
        {            // 保存原始 RGB 值
            int originalRed = image[i][u].rgbtRed;
            int originalGreen = image[i][u].rgbtGreen;
            int originalBlue = image[i][u].rgbtBlue;

            // 使用原始值计算新的 Sepia 值
            int sepiaRed = (int)(0.393 * originalRed + 0.769 * originalGreen + 0.189 * originalBlue+0.5);
            int sepiaGreen = (int)(0.349 * originalRed + 0.686 * originalGreen + 0.168 * originalBlue+0.5);
            int sepiaBlue = (int)(0.272 * originalRed + 0.534 * originalGreen + 0.131 * originalBlue+0.5);

            // 确保 RGB 值在 0-255 范围内
            image[i][u].rgbtRed = (sepiaRed > 255) ? 255 : sepiaRed;
            image[i][u].rgbtGreen = (sepiaGreen > 255) ? 255 : sepiaGreen;
            image[i][u].rgbtBlue = (sepiaBlue > 255) ? 255 : sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i=0;i<height;i++)
    {
        for(int u=0;u<width/2;u++)
        {
            int tempB=image[i][width-u-1].rgbtBlue;
            image[i][width-u-1].rgbtBlue=image[i][u].rgbtBlue;
            image[i][u].rgbtBlue=tempB;
            int tempR=image[i][width-u-1].rgbtRed;
            image[i][width-u-1].rgbtRed=image[i][u].rgbtRed;
            image[i][u].rgbtRed=tempR;
            int tempG=image[i][width-u-1].rgbtGreen;
            image[i][width-u-1].rgbtGreen=image[i][u].rgbtGreen;
            image[i][u].rgbtGreen=tempG;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int totalRed = 0, totalGreen = 0, totalBlue = 0;
            int count = 0;

            // Loop over the neighboring pixels (including the pixel itself)
            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    int new_i = i + di;
                    int new_j = j + dj;

                    // Check if neighboring pixel is within bounds
                    if (new_i >= 0 && new_i < height && new_j >= 0 && new_j < width)
                    {
                        totalRed += copy[new_i][new_j].rgbtRed;
                        totalGreen += copy[new_i][new_j].rgbtGreen;
                        totalBlue += copy[new_i][new_j].rgbtBlue;
                        count++;
                    }
                }
            }

            // Calculate the average of the surrounding pixels
            image[i][j].rgbtRed = (totalRed + count / 2) / count; // 手动四舍五入
            image[i][j].rgbtGreen = (totalGreen + count / 2) / count; // 手动四舍五入
            image[i][j].rgbtBlue = (totalBlue + count / 2) / count; // 手动四舍五入
        }
    }
    return;
}
