#include <stdio.h>

int main() {
  int n = 5;
  int arrival[] = {1,3,6,7,9};
  int burst[] = {7,3,2,10,8};
  int process[n]; 
  int final[n]; 
  int visited[n]; 

  
  for (int i = 0; i < n; i++) {
    process[i] = i + 1;
    visited[i] = 0;
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
      }
    }
  }

  int current_time = 0; 
  int completed = 0;
int completion_time[n];
  int turn_around_time[n];
  int waiting_time[n];
  current_time+=arrival[0];
  while (completed < n) {
    int min_burst = 1000; 
    int min_index = -1; 

  
    for (int i = 0; i < n; i++) {
      if (visited[i] == 0 && arrival[i] <= current_time && burst[i] < min_burst) {
        min_burst = burst[i];
        min_index = i;
      }
    }
     completion_time[min_index] = current_time + burst[min_index];
      turn_around_time[min_index] = completion_time[min_index] - arrival[min_index];
      waiting_time[min_index] = turn_around_time[min_index] - burst[min_index];
      final[completed] = process[min_index];
      printf("%d\n", final[completed]);
      visited[min_index] = 1;

      current_time += burst[min_index];
      completed++;
    
  }

  
 
 printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
  for (int i = 0; i < n; i++) {
    printf("P%d\t%d\t%d\t%d\t%d\t%d\n", process[i], arrival[i], burst[i], completion_time[i],
           turn_around_time[i], waiting_time[i]);
  }
  printf("\n");

  return 0;
}