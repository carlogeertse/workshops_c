#include <stdio.h>

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

    int mergedArray[amount*2];

    

    void swapArrayElements(int intArray[], int index1, int index2){

    }
}