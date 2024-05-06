#include<stdio.h>
int d[]={3,2,4,2,5};
int cost[100][100];
int parent[100][100];
int values[100];
void PrintOptimalParents(int i,int j){
    if(i==j){
        printf("A%d",i);
    }
    else{
        printf("(");
        PrintOptimalParents(i,parent[i][j]);
        PrintOptimalParents(parent[i][j]+1,j);
        printf(")");
    }
}
int main(){
    int n;
    printf("Enter number of matrices:");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j){
                cost[i][j]=0;
                parent[i][j]=-1;
            }
            else if(i>j){
                cost[i][j]=-1;
                parent[i][j]=-1;
            }
        }
    }
    int j;
    
    for(int len=1;len<=n;len++){
        for(int i=1;i<=n-len;i++){
            j=i+len;
            int min=1000;
            int value;
            for(int k=i;k<j;k++){
                int new_cost = cost[i][k] + cost[k + 1][j] + d[i - 1] * d[k] * d[j];
                if(min > new_cost){
                    min = new_cost;
                    value=k;
                }
            }
            cost[i][j]=min;
            parent[i][j]=value;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%d ",cost[i][j]);
            
        }
        printf("\n");
    }
     for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%d ",parent[i][j]);
            
        }
        printf("\n");
    }
    PrintOptimalParents(1,n);
}
