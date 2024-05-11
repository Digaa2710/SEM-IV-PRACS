#include<stdio.h>

int main() {
    int arr[] = {1, 3, 0, 3, 5, 6, 3};
    int capacity = 3;
    int hit = 0;
    int miss = 0;
    int solution[3];
    for (int i = 0; i < 3; i++) {
        solution[i] = -1;
    }
    int current = 0;
    for (int i = 0; i < 7; i++) {
        int found = 0;
        for (int j = 0; j < capacity; j++) {
            if (solution[j] == arr[i]) {
                hit++;
                found = 1;
                printf("Step %d: Element %d found at index %d (Hit)\n", (i + 1), arr[i], j);
                break;
            }
        }
        if (found == 0) {
            printf("Step %d: Element %d inserted into memory at index %d (Miss)\n", (i + 1), arr[i], current);
            solution[current] = arr[i];
            current = (current + 1) % 3;
            miss++;
        }
    }
    printf("Total Misses: %d\n", miss);
    printf("Total Hits: %d\n", hit);
    return 0;
}
