#include <stdio.h>

int main() {
    int amount = 0;

    printf("Please insert the amount of integers to be stored in an array:\n");
    scanf("%d", &amount);
    int numberArray[amount];
    for (int i = 0; i < amount; ++i) {
        printf("Element %d:\t", i);
        scanf("%d", &numberArray[i]);
    }
    int duplicates = 0;
    int seen[amount];
    seen[0] = numberArray[0];
    for (int j = 1; j < amount; ++j) {
        for (int i = 0; i < sizeof(seen) / sizeof(seen[0]); ++i) {
            if (seen[i] == numberArray[j]) {
                duplicates++;
            }
        }
        seen[j] = numberArray[j];
    }
    printf("Total number of duplicate elements found in the array is: %d", duplicates);
}