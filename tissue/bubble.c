#include <stdio.h>

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90}; // 待排序数组
    int n = sizeof(arr) / sizeof(arr[0]);   // 数组长度
    int i, j, temp;

    // 冒泡排序
    for (i = 0; i < n - 1; i++)     //一个外界相当于一个数到顶端
    {
        for (j = 0; j < n - 1 - i; j++) //一个内界相当于一个数移动一位
         {
            if (arr[j] > arr[j + 1]) {
                // 交换 arr[j] 和 arr[j + 1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    // 打印排序后的数组
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
