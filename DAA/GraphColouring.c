#include<stdio.h>
#include<stdlib.h>
int graph[100][100];
int x[100];
int Nextvalue(int k,int n,int m){
    int j;
    int flag = 1;
    while (flag) {
        x[k]=(x[k]+1) % (m+1);
        if (x[k]==0){
            return 0;
        }
        for (j=0;j<n;j++){
            if (graph[k][j]!=0 && x[k]==x[j]){
                break;
            }
        }
        if(j==n){
            return 1;
        }
    }
}

int mcoloring(int k,int n,int m){
    Nextvalue(k,n,m);
    if (x[k]==0){
        return 0;
    }
    if(k==n-1){
        for(int i=0;i<n;i++){
            printf("%d ",x[i]);
        }
    }
    else{
        mcoloring(k+1,n,m);
    }
}
    


int main(){
    int n;
    printf("Enter number of graph vertices:");
    scanf("%d",&n);
    printf("Enter graph vertices:");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
        }
        printf("\n");
    }
    int k=0;
    int m;
    printf("Enter number of color:");
    scanf("%d",&m);
    for (int i = 0; i < n; i++)
        x[i] = 0;
    mcoloring(k,n,m);
}