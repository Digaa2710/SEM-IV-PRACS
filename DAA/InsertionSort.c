#include<stdio.h>
#include<time.h>

int insertion_sort(int array[],int n ){
    int key;
    int j;
    for(int i=0;i<n;i++){
        key=array[i];
        j=i-1;
        while(j>=0 && array[j]>key){
            array[j+1]=array[j];
            j--;
        }
        array[j+1]=key;
    }
}
int main(){
  int  n=1000;
  int array[1000];
    clock_t t1,t2,t3;
    t1=clock();
    insertion_sort(array,n);
    t2=clock();
    t3=t2-t1;
    printf("Best case:%d\n",t3);
    int j=0;
    for(int i=999;i>=0;i--){
        array[i]=j;
        j++;
    }
    t1=clock();
    insertion_sort(array,n);
    t2=clock();
    t3=t2-t1;
    printf("Worst case:%d\n",t3);
    
    for(int i=0;i<n;i++){
        array[i]=rand();
    }
     t1=clock();
    insertion_sort(array,n);
    t2=clock();
    t3=t2-t1;
    printf("Average case:%d\n",t3);
}