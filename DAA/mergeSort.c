#include<stdio.h>
#include<time.h>
int mergeSort(int l,int m,int r,int array[]){
    int i=l;
    int j=m+1;
    int k=l;
    int b[1000];
    while(i<=m && j<=r){
        if(array[i]<array[j]){
            b[k]=array[i];
            i++;
            k++;
        }
        else{
            b[k]=array[j];
            j++;
            k++;
        }
    }
    while(i<=m){
        b[k]=array[i];
        i++;
        k++;
    }
    while(j<=r){
        b[k]=array[j];
        j++;
        k++;
    }
    for(int i=l;i<=r;i++){
        array[i]=b[i];
    }
}
int Sort(int array[],int l,int r){
    int m=(l+r)/2;
    if(l<r){
        Sort(array,l,m);
        Sort(array,m+1,r);
        mergeSort(l,m,r,array);
    }
}
int main(){
    clock_t t1,t2,t3;
    int n=1001;
    int array[1001];
   for(int i=0;i<n;i++){
       array[i]=i;
   }
    t1=clock();
    Sort(array,0,n-1);
   
    t2=clock();
    t3=t2-t1;
    printf("Best case:%d\n",t3);
    int j=0;
    for(int i=1000;i>=0;i--){
        array[i]=j;
        j++;
    }
     t1=clock();
    Sort(array,0,n-1);
   
    t2=clock();
    t3=t2-t1;
    printf("Worst case:%d\n",t3);
    
    for(int i=0;i<n;i++){
        array[i]=rand();
        
    }
 t1=clock();
    Sort(array,0,n-1);
   
    t2=clock();
    t3=t2-t1;
    printf("Average case:%d\n",t3);
}
