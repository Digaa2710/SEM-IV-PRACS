#include<stdio.h>
int usedProcesses[100]={0,0,0,0,0};
int diff;
int main(){
    int blockSize[]={100,500,300,200,600};
    int processSize[]={212,417,212,426};
    int lastBlock=0;
    for(int i=0;i<4;i++){
        int index=-1;
        for(int j=lastBlock;j<5;j++){
            if(usedProcesses[j]==0 && blockSize[j]>=processSize[i]){
                    index=j;
                    lastBlock=j;
                    break;
                }
            }
            lastBlock=0;
        
        if(index!=-1){
            printf("Pocess %d goes to block %d\n",processSize[i],blockSize[index]);
            usedProcesses[index]=1;
        }
        else{
            printf("Process %d cant be allocated\n",processSize[i]);
        }
    }
    
}