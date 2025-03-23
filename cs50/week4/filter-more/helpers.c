#include "helpers.h"
#include<math.h>
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

    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            int counts=0,Red=0,Green=0,Blue=0;
            for(int a=-1;a<=1;a++)
            {
                for(int b=-1;b<=1;b++)
                {
                    if(a+i>=0&&a+i<height&&b+j<width&&b+j>=0)
                    {
                        counts++;
                        Red+=copy[a+i][b+j].rgbtRed;
                        Green+=copy[a+i][b+j].rgbtGreen;
                        Blue+=copy[a+i][b+j].rgbtBlue;
                    }
                }
            }
            if(counts!=0)
            {
            image[i][j].rgbtRed=(Red+counts/2)/counts;
            image[i][j].rgbtGreen=(Green+counts/2)/counts;
            image[i][j].rgbtBlue=(Blue+counts/2)/counts;
        }
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // 创建副本以避免在处理图像时更改原始数据
    RGBTRIPLE copy[height][width];

    // 复制原始图像
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // Sobel 操作的核心部分
    int Gx[3][3] = {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };

    int Gy[3][3] = {
        {1, 2, 1},
        {0, 0, 0},
        {-1, -2, -1}
    };

    // 处理每个像素
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // 初始化 Gx 和 Gy
            int redX = 0, greenX = 0, blueX = 0;
            int redY = 0, greenY = 0, blueY = 0;

            // 遍历周围的 3x3 像素
            for (int a = -1; a <= 1; a++)
            {
                for (int b = -1; b <= 1; b++)
                {
                    // 检查边界，确保不越界，同时让边缘保持黑色
                    if (i + a < 0 || i + a >= height || j + b < 0 || j + b>= width)
                    {
                        continue; // 如果越界，跳过
                    }

                    // 使用 Sobel 卷积核计算 Gx 和 Gy
                    redX += copy[i + a][j + b].rgbtRed * Gx[a + 1][b + 1];
                    greenX += copy[i + a][j + b].rgbtGreen * Gx[a + 1][b + 1];
                    blueX += copy[i + a][j + b].rgbtBlue * Gx[a + 1][b + 1];

                    redY += copy[i + a][j + b].rgbtRed * Gy[a + 1][b + 1];
                    greenY += copy[i + a][j + b].rgbtGreen * Gy[a + 1][b + 1];
                    blueY += copy[i + a][j + b].rgbtBlue * Gy[a + 1][b + 1];
                }
            }

            // 计算最终的 RGB 值
            image[i][j].rgbtRed = fmin(255,(int)round(sqrt(redX * redX + redY * redY)));
            image[i][j].rgbtGreen =fmin(255, (int)round(sqrt(greenX * greenX + greenY * greenY)));
            image[i][j].rgbtBlue = fmin(255,(int)round(sqrt(blueX * blueX + blueY * blueY)));
        }
    }
    return;
}

