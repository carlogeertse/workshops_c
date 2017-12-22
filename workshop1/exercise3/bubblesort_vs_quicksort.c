#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <math.h>

/**
 * A function that prints statistics about an array of numbers it prints the following info:
 * Average number, Minimum number, Maximum number, Variance and Standard deviation.
 * @param numberArray The array of numbers whose statistics need to be shown
 * @param arraySize The amount of numbers in the array
 * @param name A name to be shown when printing the statistics
 */
void printStats(double numberArray[], int arraySize, char name[]) {
    double average;
    double sum = 0.0;
    //compute the sum of numberArray
    for (int i = 0; i < arraySize; ++i) {
        sum += numberArray[i];
    }
    //compute the average cpu_time
    average = sum / arraySize;

    //Compute variance and standard deviation of cpu times
    double sum1 = 0;
    for (int i = 0; i < arraySize; i++) {
        sum1 = sum1 + pow((numberArray[i] - average), 2);
    }
    double variance = sum1 / (float) arraySize;
    double std_deviation = sqrt(variance);

    //Compute the minimum time it took to execute the action
    double minimum = numberArray[0];
    for (int c = 1; c < arraySize; c++) {
        if (numberArray[c] < minimum) {
            minimum = numberArray[c];
        }
    }

    //Compute the maximum time it took to execute the action
    double maximum = numberArray[0];
    for (int c = 1; c < arraySize; c++) {
        if (numberArray[c] > maximum) {
            maximum = numberArray[c];
        }
    }

    printf("\nStatistics for %s with %d executions:\n", name, arraySize);
    printf("Average time:\t\t%lf\n", average);
    printf("Minimum time:\t\t%lf\n", minimum);
    printf("Maximum time:\t\t%lf\n", maximum);
    printf("Variance:\t\t%lf\n", variance);
    printf("Standard deviation:\t%lf\n\n", std_deviation);
}

/**
 * Swap two elements based on their pointers
 * @param element1Ptr pointer to element 1
 * @param element2Ptr pointer to element 2
 */
void swap(int *element1Ptr, int *element2Ptr) {
    int hold = *element1Ptr;
    *element1Ptr = *element2Ptr;
    *element2Ptr = hold;
}

/**
 * Sort an array of integers by using the BubbleSort algorithm
 * Complexity: Best case: O(n)
 *             Worst case: O(n^2)
 *             Average case: O(n^2)
 * @param array The array that needs to be sorted
 * @param size The size of the array that needs to be sorted
 */
void bubbleSort(int *array, const int size) {
    int pass, j;
    for (pass = 0; pass < size - 1; pass++) {
        for (j = 0; j < size - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}

/**
 * This function takes last element as pivot, places the pivot element at its correct position in sorted array,
 * and places all smaller (smaller than pivot) to left of pivot and all greater elements to right of pivot.
 * @param arr
 * @param low
 * @param high
 * @return
 */
int partition(int arr[], int low, int high) {
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot) {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

/**
 * This function sorts an array of integers by applying the QuickSort algorithm
 * Complexity: Best case: O(n log n)
 *             Worst case: O(n^2)
 *             Average case: O(n log n)
 * @param arr Array to be sorted
 * @param low Starting index
 * @param high Ending index
 */
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // pi is partitioning index, arr[p] is now at right place
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    clock_t start, end;
    int numberOfTests = 10;
    int arraySize = 20000;
    double cpu_time_used_bubble[numberOfTests];
    double cpu_time_used_quick[numberOfTests];

    //Initialise random arrays
    int randomArray1[numberOfTests][arraySize];
    int randomArray2[numberOfTests][arraySize];
    srand(time(NULL));
    for (int i = 0; i < numberOfTests; ++i) {
        for (int j = 0; j < arraySize; ++j) {
            randomArray1[i][j] = rand();
            randomArray2[i][j] = rand();
        }
    }

    //Generate {numberOfTests} bubblesort times
    for (int j = 0; j < numberOfTests; ++j) {
        start = clock();

        bubbleSort(randomArray1[j], arraySize);

        end = clock();

        cpu_time_used_bubble[j] = ((double) (end - start) / CLOCKS_PER_SEC);
        printf("Operation number %d took %lf seconds\n", j, cpu_time_used_bubble[j]);
    }

    printf("\n");

    //Generate {numberOfTests} quicksort times
    for (int j = 0; j < numberOfTests; ++j) {
        start = clock();

        quickSort(randomArray2[j], 0, arraySize - 1);

        end = clock();

        cpu_time_used_quick[j] = ((double) (end - start) / CLOCKS_PER_SEC);
        printf("Operation number %d took %lf seconds\n", j, cpu_time_used_quick[j]);
    }

    printStats(cpu_time_used_bubble, numberOfTests, "Bubblesort");
    printStats(cpu_time_used_quick, numberOfTests, "Quicksort");
}