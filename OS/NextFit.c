#include<stdio.h>
int usedProcesses[100]={0,0,0,0,0};
int diff;
int main(){
    int blockSize[]={125,500,200,300,600};
    int processSize[]={450,417,112,290,90};
    int lastBlock=0;
    for(int i=0;i<5;i++){
        int index=-1;
        int j=lastBlock;
        do{
            if(usedProcesses[j]==0 && blockSize[j]>=processSize[i]){
                    index=j;
                    lastBlock=j;
                    
                    break;
                }
                 j=(j+1)%5;
            } while(j!=lastBlock);
           if(index!=-1){
            printf("Pocess %d goes to block %d\n",processSize[i],blockSize[index]);
            usedProcesses[index]=1;
        }
        else{
            printf("Process %d cant be allocated\n",processSize[i]);
        }
    }
}
