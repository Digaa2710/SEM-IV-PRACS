#include<stdio.h>
#include<time.h>
void selection_sort(int n,int array[]){
    int new;
    for(int i=0;i<n;i++){
        new=i;
        for(int j=i+1;j<n;j++){
            if(array[j]<array[new]){
                new=j;
            }
            
        }
        int temp=array[i];
        array[i]=array[new];
        array[new]=temp;
    }
}
int main(){
    int n=1000;
    int array[1000];
    for(int i=0;i<n;i++){
        array[i]=i;
    }
    clock_t t1,t2,t3;
    t1=clock();
    selection_sort(n,array);
    t2=clock();
    t3=t2-t1;
    printf("Best case:%d\n",t3);
    int j=0;
    for(int i=999;i>=0;i--){
        array[i]=j;
        j++;
    }
     t1=clock();
    selection_sort(n,array);
    t2=clock();
    t3=t2-t1;
    printf("Worst case:%d\n",t3);
    
    for(int i=0;i<n;i++){
        array[i]=rand();
    }
    t1=clock();
    selection_sort(n,array);
    t2=clock();
    t3=t2-t1;
    printf("Average case:%d\n",t3);
}