#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int cash;
    int points = 0;

    // 输入并验证非负数
    do
    {
        cash = get_int("Change owed: ");
    }
    while (cash < 0);

    // 计算需要的硬币数量
    points += cash / 25;  // 25美分硬币的数量
    cash %= 25;           // 计算剩余的零钱

    points += cash / 10;  // 10美分硬币的数量
    cash %= 10;           // 计算剩余的零钱

    points += cash / 5;   // 5美分硬币的数量
    cash %= 5;            // 计算剩余的零钱

    points += cash;       // 1美分硬币的数量

    // 输出结果
    printf("%d\n", points);
}
