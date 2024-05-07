#include<stdio.h>
int knapsack[100][100];
int value[100];
int weight[100];
int array[100];
//value is profit here 
int max(int a,int b){
    return (a>b)?a:b;
}
int main(){
    int m;
    printf("Enter number :");
    scanf("%d",&m);
    printf("Enter profits:");
    for(int i=0;i<m;i++){
        scanf("%d",&value[i]);
    }
    printf("Enter weights:");
     for(int i=0;i<m;i++){
        scanf("%d",&weight[i]);
    }
    int n;
    printf("Enter number max weight (which is number of columns):");
    scanf("%d",&n);
    for(int i=0;i<=n;i++){
        knapsack[0][i]=0;
    }
    for(int i=0;i<=m;i++){
        knapsack[i][0]=0;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(j-weight[i-1]<0){
                knapsack[i][j]=knapsack[i-1][j];
            }
            else{
                knapsack[i][j]=max(knapsack[i-1][j],knapsack[i-1][j-weight[i-1]]+value[i-1]);
            }
        }
    }
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            printf("%d ",knapsack[i][j]);
        }
        printf("\n");
    }
    printf("Maximum profit is %d",knapsack[m][n]);
    printf("\n");
     int i=m;
     int j=n;
    int count=0;
    while(i>0 && j>0){
        if(knapsack[i][j]==knapsack[i-1][j]){
            i--;
        }
        else{
            array[count]=value[i-1];
            
            j=j-weight[i-1];
            count++;
            i--;
        }
    }
    for(int i=0;i<count;i++){
        printf("%d ",array[i]);
    }
    
}