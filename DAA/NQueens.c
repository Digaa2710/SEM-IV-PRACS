#include<stdio.h>
#include <stdlib.h>
int x[100];
int Place(int k,int i){
    for(int j=0;j<k;j++){
        if(x[j]==i || (abs(x[j]-i)==abs(j-k))){
            return 0;
        }
       
    }
     return 1;
}
void NQueens(int k,int n){
    for(int i=0;i<n;i++){
        if (Place(k,i)==1){
            x[k]=i;
            if(k==n-1){
                for(int i=0;i<n;i++){
                    printf("%d",x[i]+1);
                }
                printf("\n");
            }
            else{
                NQueens(k+1,n);
            }
        }
        
    }
}
int main(){
    int n;
    printf("Enter number of queens:");
    scanf("%d",&n);
    int k=0;
    NQueens(k,n);
}