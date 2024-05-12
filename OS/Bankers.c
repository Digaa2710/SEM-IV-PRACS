#include<stdio.h>

int main() {
    int need[4][3];
    int available[3] = {2,1,1};
    int allocated_process[4];
    int allocation[4][3] = {
        {1,0,1},
        {2,1,2},
        {3,0,0},
        {1,0,1},
        
    };
    int visited[4];
    for(int i = 0; i < 4; i++) {
        visited[i] = 0;
    }
    int canAllocate;

    int max[4][3] = {
        {2,1,1},
        {5,4,4},
        {3,1,1},
        {1,1,1},
    };
int complete=0;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 3; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    for(int k=0;k<4;k++){
        for(int i=0;i<4;i++){
            canAllocate=1;
            for(int j=0;j<3;j++){
                if(visited[i]==0 && need[i][j]>available[j]){
                    canAllocate=0;
                    visited[i]=1;
                    break;
                }
            }
            if(visited[i]==0 && canAllocate==1){
                for(int j=0;j<3;j++){
                    available[j]+=allocation[i][j];
                }
                allocated_process[complete++]=i;
                visited[i]=1;
            }
        }
    }
    if(complete==4){
        printf("Sfe State");
        for(int i=0;i<complete;i++){
            printf("%d",allocated_process[i]);
        }
    }
        else{
            printf("Unsafe state");
        }
    
    return 0;
}
