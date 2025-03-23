#include <iostream>
using namespace std;

void removeElement(int arr[], int& size, int value) {
    int i = 0;
    while (i < size) {
        if (arr[i] == value) {
            // 移动元素
            for (int j = i; j < size - 1; j++) {
                arr[j] = arr[j + 1];
            }
            size--;  // 减小数组大小
        } else {
            i++;  // 只有不删除元素时才向后移动
        }
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 3, 6};
    int size = 7;

    removeElement(arr, size, 3);

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
