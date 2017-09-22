#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <math.h>

int main() {
    clock_t start, end;
    double cpu_time_used[10];
    int cpu_time_size = sizeof(cpu_time_used) / sizeof(cpu_time_used[0]);

    for (int j = 0; j < 10; ++j) {
        start = clock();

        //CODE HERE
        Sleep(200);

        end = clock();

        cpu_time_used[j] = ((double) (end - start) / CLOCKS_PER_SEC);
        printf("Operation number %d took %lf seconds\n", j, cpu_time_used[j]);
    }

    double average = 0.0;
    double sum = 0.0;
    //compute the sum of cpu_times
    for (int i = 0; i < cpu_time_size; ++i) {
        sum += cpu_time_used[i];
    }
    //compute the average cpu_time
    average = sum / cpu_time_size;

    //Compute variance and standard deviation of cpu times
    double sum1 = 0;
    for (int i = 0; i < cpu_time_size; i++) {
        sum1 = sum1 + pow((cpu_time_used[i] - average), 2);
    }
    double variance = sum1 / (float) cpu_time_size;
    double std_deviation = sqrt(variance);

    //Compute the minimum time it took to execute the action
    double minimum = cpu_time_used[0];
    for (int c = 1; c < cpu_time_size; c++) {
        if (cpu_time_used[c] < minimum) {
            minimum = cpu_time_used[c];
        }
    }

    //Compute the maximum time it took to execute the action
    double maximum = cpu_time_used[0];
    for (int c = 1; c < cpu_time_size; c++) {
        if (cpu_time_used[c] > maximum) {
            minimum = cpu_time_used[c];
        }
    }

    printf("\nStatistics for %d executions:\n", cpu_time_size);
    printf("Average time:\t\t%lf\n", average);
    printf("Minimum time:\t\t%lf\n", minimum);
    printf("Maximum time:\t\t%lf\n", maximum);
    printf("\nVariance:\t\t%lf\n", variance);
    printf("Standard deviation:\t%lf\n", std_deviation);
}