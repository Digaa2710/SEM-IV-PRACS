#include<stdio.h>
int main(){
    int n=5;
    int forks[5];
    for(int i=0;i<n;i++){
        forks[i]=1;
    }
    int philosopher;
    
    while(1){
        printf("Enter the philosopher who wants to eat\n:");
        scanf("%d",&philosopher);
        if(philosopher==-1){
            break;
        }
        else{
            printf("P%d is now thinking to eat\n",philosopher);
            if(forks[philosopher-1]==1){
                printf("P%d gets fork %d\n",philosopher,philosopher);
                forks[philosopher-1]=0;
            }
            if(forks[philosopher%n]==1){
                printf("P%d gets fork %d\n",philosopher,philosopher%n+1);
                forks[philosopher%n]=0;
            }
            printf("P%d starts eating...\n",philosopher);
            forks[philosopher-1]=1;
            forks[philosopher%n]=1;
            printf("P%d stops eating eating\n",philosopher);
            
        }
        
    }
}
