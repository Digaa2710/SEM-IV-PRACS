#include <stdio.h>
#define n 4
int main() {
  
  int arrival[] = {0,1,2,4};
  int burst[] = {5,4,2,1};
  int remaining_burst[n];
  int process[n];; 
  int final[n]; 
  int visited[n]; 
  int priority[]={10,20,30,40};

  
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
        
        temp=priority[i];
        priority[i]=priority[j];
        priority[j]=temp;
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
    int max = -1; 
    int max_index = -1;

    for (int i = 0; i < n; i++) {
      if (visited[i] == 0 && arrival[i] <= current_time && priority[i] >max) {
        max = priority[i];
        max_index = i;
      }
    }
    current_time++;
    remaining_burst[max_index]--;
    if (remaining_burst[max_index] == 0) {
      completion_time[max_index] = current_time;
      turn_around_time[max_index] = completion_time[max_index] - arrival[max_index];
      waiting_time[max_index] = turn_around_time[max_index] - burst[max_index];
      final[completed] = process[max_index];
      // printf("%d\n", final[completed]);
      visited[max_index] = 1;
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