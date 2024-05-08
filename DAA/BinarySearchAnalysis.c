#include<stdio.h>
#include<time.h>
int sort(int n,int array[]){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(array[j]>array[j+1]){
                int temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
        }
    }
}
int binarySearch(int l,int r,int key,int array[]){
    int mid;
    while(l<=r){
        mid=(l+r)/2;
        if(array[mid]==key){
            return mid;
        }
        else if(array[mid]<key){
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
}
int main(){
    int n=1000;
    int array[1000];
    for(int i=0;i<n;i++){
        array[i]=rand();
    }
    sort( n, array);
    clock_t t1,t2,t3;
    t1=clock();
    binarySearch(0,n-1,array[n/2],array);
    t2=clock();
    printf("Best case:%d\n",t2-t1);
    t1=clock();
    binarySearch(0,n-1,array[0],array);
    t2=clock();
    printf("Worst case:%d\n",t2-t1);
     t1=clock();
    binarySearch(0,n-1,array[25],array);
    t2=clock();
    printf("Average case:%d\n",t2-t1);
}