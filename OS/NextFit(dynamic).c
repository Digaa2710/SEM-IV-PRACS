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
        int lastValue=0;
        
        int j = lastValue;
        do {
            if(remaining[j]>=processSize[i]){
                lastValue=j;
                index=j;
                break;
            }
            j = (j + 1) % 2;
        } while (j != lastValue);
        if(index!=-1){
            printf("Process %d goes to block %d\n",processSize[i],blockSize[index]);
            remaining[index]-=processSize[i];
        }
    } 
}