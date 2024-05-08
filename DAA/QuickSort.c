#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(int i,int j,int array[]){
    int temp=array[i];
    array[i]=array[j];
    array[j]=temp;
}
int partition(int l,int r,int array[]){
    int pivot=array[r];
    int i,j;
    i=l-1;
  
    for(j=l;j<r;j++){
        if(array[j]<pivot){
            

            i++;
            swap(i,j,array);
        }
    }
    swap(i+1,r,array);
    return (i+1);
}
int quickSort(int l,int r,int array[]){
    if(l<r){
        int pivot=partition(l,r,array);
        quickSort(l,pivot-1,array);
        quickSort(pivot+1,r,array);
    }
}
int main(){
  int  n=1001;
    int array[1001];
    for(int i=0;i<n;i++){
        array[i]=i;
    }
    clock_t t1,t2,t3;
    t1=clock();
    quickSort(0,n-1,array);
    t2=clock();
    t3=t2-t1;
    printf("Best case:%d\n",t3);
    int k=0;
    for(int i=1000;i>=0;i--){
        array[i]=k;
        k++;
    }
     t1=clock();
    quickSort(0,n-1,array);
    t2=clock();
    t3=t2-t1;
    printf("Worst case:%d\n",t3);
    for(int i=0;i<n;i++){
        array[i]=rand();
    }
    t1=clock();
    quickSort(0,n-1,array);
    t2=clock();
    t3=t2-t1;
    printf("Average case:%d\n",t3);
    
    
}