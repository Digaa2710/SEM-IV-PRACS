#include<stdio.h>
int remaining[100];
int main(){
    int blockSize[]={150,350};
    for(int i=0;i<2;i++){
        remaining[i]=blockSize[i];
    }
    int diff;
    int processSize[]={300,25,125,50};
    for(int i=0;i<4;i++){
        int index=-1;
        int max=0;
        
        for(int j=0;j<2;j++){
            
            diff=remaining[j]-processSize[i];
            if(remaining[j]>=processSize[i] && max<diff ){
                max=diff;
                index=j;
            }
        }
        if(index!=-1){
            printf("Process %d goes to block %d\n",processSize[i],blockSize[index]);
            remaining[index]-=processSize[i];
        }
    } 
}