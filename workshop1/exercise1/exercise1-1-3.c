#include <stdio.h>

int main() {
    float weight1 = 15;
    float weight2 = 25;
    float amount1 = 5;
    float amount2 = 4;
    float average = (weight1 * amount1 + weight2 * amount2) / (amount1 + amount2);
    printf("%f",average);
}