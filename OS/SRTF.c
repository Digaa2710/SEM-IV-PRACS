#include<stdio.h>
#define n 5
int main(){
    int arrival[]={2,5,1,0,4};
    int burst[]={6,2,8,3,4};
    int visited[n];
    int presentTime=0;
    int complete=0;
    int process[n];
    int remaining[n];
    // int priority[]={4,5,7,2,1,6};
    for(int i=0;i<n;i++){
        process[i]=i+1;
        visited[i]=0;
        remaining[i]=burst[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arrival[i]>arrival[j]){
                int temp=arrival[i];
                arrival[i]=arrival[j];
                arrival[j]=temp;
                
                 temp=burst[i];
                burst[i]=burst[j];
                burst[j]=temp;
                
                 temp=process[i];
                process[i]=process[j];
                process[j]=temp;
                
                temp=remaining[i];
                remaining[i]=remaining[j];
                remaining[j]=temp;
            }
        }
    }
    int completion_time[n];
    int turn_around[n];
    int waiting_time[n];
  
  presentTime+=arrival[0];
  while(complete<n){
      int min=1000;
      int min_index=-1;
      for(int i=0;i<n;i++){
          if(visited[i]==0 && arrival[i]<=presentTime && min>remaining[i]){
              min=remaining[i];
              min_index=i;
          }
      }
      printf("P%d\t",process[min_index]);
      printf("%d\n",presentTime);
      presentTime++;
      remaining[min_index]--;
      
      if(remaining[min_index]==0){
         
          completion_time[min_index]=presentTime;
          turn_around[min_index]=completion_time[min_index]-arrival[min_index];
          waiting_time[min_index]=turn_around[min_index]-burst[min_index];
          visited[min_index]=1;
          complete++;
      }
  }
  printf("Process\tAT\tBT\tCT\tTAT\tWT\t\n");
  for(int i=0;i<n;i++){
      printf("%d\t%d\t%d\t%d\t%d\t%d\t\n",process[i],arrival[i],burst[i],completion_time[i],turn_around[i],waiting_time[i]);
  }
}
