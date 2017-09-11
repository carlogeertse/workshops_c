#include <stdio.h>
#include <time.h>
#include <windows.h>

int main() {
    clock_t start, end;
    double cpu_time_used[10];
    int cpu_time_size = sizeof(cpu_time_used) / sizeof(cpu_time_used[0]);

    for (int j = 0; j < 10; ++j) {
        start = clock();

        /*
        for (int i = 0; i < 500; ++i) {
            printf("test\n");
        }*/

        //CODE HERE
        Sleep(200);

        end = clock();

        cpu_time_used[j] = ((double) (end - start) / CLOCKS_PER_SEC);
        printf("Operation number %d took %lf seconds\n", j, cpu_time_used[j]);
    }

    double average = 0.0;
    double sum = 0.0;
    for (int i = 0; i < cpu_time_size; ++i) {
        sum += cpu_time_used[i];
    }
    average = sum / cpu_time_size;

    printf("Average time the operation took after %d executions: %lf", cpu_time_size, average);
}