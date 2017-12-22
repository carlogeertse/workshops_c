#include <stdio.h>

void printNumbers(int n) {
    if (n == 0) {
        printf("%d ", 0);
    } else {
        printNumbers(n - 1);
        printf("%d ", n);
    }
}

int main() {
    printNumbers(5);
}