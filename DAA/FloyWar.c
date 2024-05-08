#include<stdio.h>
int graph[100][100];
int parent[100][100];

int main(){
    int n;
    printf("Enter of vertices:");
    scanf("%d",&n);
    printf("Enter vertices:");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    printf("Parents:");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(graph[i][j]!=0 && graph[i][j]!=1000){
                parent[i][j]=i+1;
            }
            else{
                parent[i][j]=-1;
            }
        }
    }
    int k=0;
    while(k<n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(graph[i][j]>graph[i][k]+graph[k][j]){
                graph[i][j]=graph[i][k]+graph[k][j];
                parent[i][j]=k+1;
            }
        }
    }
    k++;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d",parent[i][j]);
        }
        printf("\n");
    }
}