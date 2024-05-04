#include<stdio.h>
#define size 50
int a[size],n;
int selectionSort(int a[size],int n){
    int temp,j;
    for(int i=0;i<n;i++){
        temp=a[i];
        j=i-1;
        while(j>=0 && a[j]>temp){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
}
int main(){
    printf("Enter number of terms:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    InsertionSort(a,n);
    for(int i=0;i<n;i++){
        printf("%d",a[i]);
    }
}