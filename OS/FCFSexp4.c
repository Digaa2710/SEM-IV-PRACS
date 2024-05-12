#include <stdio.h>
#define n 4
int main() {

  int arrival[] = {0,1,5,6};
  int burst[] = {2,2,3,4};
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
  current_time+=burst[0];
  completion_time[0]=current_time;
  for(int i=1;i<n;i++){
      if(arrival[i]<=current_time){
          current_time=current_time+burst[i];
          completion_time[i]=current_time;
      }
      else{
          current_time=arrival[i]+burst[i];
          completion_time[i]=current_time;
      }
  }
for(int i=0;i<n;i++){
    turn_around_time[i]=completion_time[i]-arrival[i];
    waiting_time[i]=turn_around_time[i]-burst[i];
}
  
  printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
  for (int i = 0; i < n; i++) {
    printf("P%d\t%d\t%d\t%d\t%d\t%d\n", process[i], arrival[i], burst[i], completion_time[i],
           turn_around_time[i], waiting_time[i]);
  }
 
  printf("\n");

  return 0;
}
