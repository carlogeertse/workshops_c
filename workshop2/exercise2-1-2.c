#include <stdio.h>

int fib(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        int fibRes = fib(n - 1) + fib(n - 2);
        printf("%d ", fibRes);
        return fibRes;
    }
}

int main() {
    fib(6);
}