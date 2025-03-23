#include <stdio.h>

// 检查是否为素数的函数
int isPrime(int num) {
    if (num < 2) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int main() {
    for (int i = 2; i <= 200; i++) {
        if (isPrime(i)) {
            printf("%d\n", i);
        }
    }
    return 0;
}
