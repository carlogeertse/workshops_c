#include <stdio.h>

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

/**
 * This function merges an array into the target array. It assumes the target array has 'empty' spots represented as -1
 * @param sourceArray The source array that needs to be merged into the target array.
 * @param sourceSize The size of the source array
 * @param targetArray The target array that the source array needs to be merged into
 */
void mergeAndSortArrays(int sourceArray[], int sourceSize, int targetArray[]) {
    int inserted = 0;
    int i = 0;
    //Merge the rest of the source array into the target array, sorting in the meantime
    for (int j = 0; j < sourceSize; ++j) {
        while (!inserted) {
            if (sourceArray[j] > targetArray[i]) {
                shiftRight(targetArray, i, sourceSize * 2 - 1, 1);
                targetArray[i] = sourceArray[j];
                inserted = 1;
            } else if (targetArray[i] == -1) {
                targetArray[i] = sourceArray[j];
                inserted = 1;
            } else {
                i++;
            }
        }
        inserted = 0;
        i = 0;
    }
}

int main() {
    int amount = 0; //init aray size 1

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

    //Initialise array with -1 on all 'empty' positions.
    int mergedArray1[amount * 2];
    for (int k = 0; k < amount * 2; ++k) {
        mergedArray1[k] = -1;
    }

    mergeAndSortArrays(numberArray1, amount, mergedArray1);
    mergeAndSortArrays(numberArray2, amount, mergedArray1);

    for (int j = 0; j < amount*2; j++) {
        printf("%d ", mergedArray1[j]);
    }
}