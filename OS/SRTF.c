#include <stdio.h>
#define n 5
int main() {
  
  int arrival[] = {2,5,1,0,4};
  int burst[] = {6,2,8,3,4};
  int remaining_burst[n];
  int process[n]; 
  int final[n]; 
  int visited[n]; 

  
  for (int i = 0; i < n; i++) {
    process[i] = i + 1;
    visited[i] = 0;
    remaining_burst[i] = burst[i];
  }
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (arrival[i] > arrival[j]) {
        int temp = arrival[i];
        arrival[i] = arrival[j];
        arrival[j] = temp;

        temp = burst[i];
        burst[i] = burst[j];
        burst[j] = temp;

        temp = process[i];
        process[i] = process[j];
        process[j] = temp;

        temp = remaining_burst[i];
        remaining_burst[i] = remaining_burst[j];
        remaining_burst[j] = temp;
      }
    }
  }

  int current_time = 0; 
  int completed = 0;
int completion_time[n];
  int turn_around_time[n];
  int waiting_time[n];
  current_time += arrival[0];
  while (completed < n) {
    int min_burst = 1000; 
    int min_index = -1;

    for (int i = 0; i < n; i++) {
      if (visited[i] == 0 && arrival[i] <= current_time && remaining_burst[i] < min_burst) {
        min_burst = remaining_burst[i];
        min_index = i;
      }
    }
    current_time++;
    remaining_burst[min_index]--;
    if (remaining_burst[min_index] == 0) {
      completion_time[min_index] = current_time;
      turn_around_time[min_index] = completion_time[min_index] - arrival[min_index];
      waiting_time[min_index] = turn_around_time[min_index] - burst[min_index];
      final[completed] = process[min_index];
      // printf("%d\n", final[completed]);
      visited[min_index] = 1;
      completed++;
    }
  }
 printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
  for (int i = 0; i < n; i++) {
    printf("P%d\t%d\t%d\t%d\t%d\t%d\n", process[i], arrival[i], burst[i], completion_time[i],
           turn_around_time[i], waiting_time[i]);
  }
  printf("\n");

  return 0;
}