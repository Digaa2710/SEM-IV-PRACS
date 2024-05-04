#include<stdio.h>
#define size 50
int a[size],n;
int selectionSort(int a[size],int n){
    int new,temp;
    for(int i=0;i<n;i++){
        new=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[new]){
                new=j;
            }
        }
        temp=a[i];
        a[i]=a[new];
        a[new]=temp;
    }
} 
int main(){
    printf("Enter number of terms:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    selectionSort(a,n);
    for(int i=0;i<n;i++){
        printf("%d\n",a[i]);
    }
}