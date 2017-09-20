#include <stdio.h>

int main() {
    int amount = 0; //init aray size 1

    /**
     * Moves some items in an array to the right
     * @param int items[]: An array filled with items
     * @param int shiftStart: The index of the start of the collection of items that need to be shifted to the right
     * @param int shiftEnd: The index of the end of the collection of items that need to be shifted to the right
     * @param int shiftAmount: The amount of positions that the items need to be shifted to the right
     */
    void shiftRight(int items[], int shiftStart, int shiftEnd, int shiftAmount) {
        for (int i = shiftEnd; i > shiftStart; i--) {
            items[i] = items[i - shiftAmount];
        }
    }

    //Fill array 1
    printf("Please insert the amount of integers to be stored in the arrays:\n");
    scanf("%d", &amount);
    int numberArray1[amount];
    for (int i = 0; i < amount; ++i) {
        printf("Element %d:\t", i);
        scanf("%d", &numberArray1[i]);
    }

    //Fill array 2
    printf("Please insert the integers to be stored in array 2:\n");
    int numberArray2[amount];
    for (int i = 0; i < amount; ++i) {
        printf("Element %d:\t", i);
        scanf("%d", &numberArray2[i]);
    }

    int mergedArray[amount * 2];

    //Copy firt element of array 1 into merged array
    mergedArray[0] = numberArray1[0];

    int insterted = 0;
    int i = 0;
    //Merge the rest of array1 into merged array, sorting in the meantime
    for (int j = 1; j < amount; ++j) {
        while (!insterted) {
            if (numberArray1[j] < mergedArray[i]) {
                shiftRight(mergedArray, i, amount * 2 - 1, 1);
                mergedArray[i] = numberArray1[j];
                insterted = 1;
            } else if (i == amount * 2 - 1) {
                mergedArray[i] = numberArray1[j];
            } else {
                i++;
            }
        }
    }


    for (int j = 0; j < 3; j++) {
        printf("%d ", mergedArray[j]);
    }
}