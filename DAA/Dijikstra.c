#include<stdio.h>
int map[100][100];
int visited[100];
int parent[100];
int value[100];
int min_array[100];
int main(){
    int n;
    printf("Enter number of vertices:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&map[i][j]);
        }
        printf("\n");
    }
    for(int i=0;i<n;i++){
        min_array[i] = value[i]=1000;
        parent[i]=-1;
    }
    for(int i=0;i<n;i++){
        visited[i]=0;
    }
    int index=0;
    value[index] = value[index] = 0;
    int k=0;
    while(k<n){
        for(int i=0;i<n;i++){
            if(visited[i]==0 && map[index][i]!=0){
                if(value[i]>=value[index]+map[index][i]){
                    min_array[i]=value[index]+map[index][i];
                    value[i]=value[index]+map[index][i];
                    parent[i]=index;
                }
            }
        }
        visited[index]=1;
        int min=1000;
        for(int i=0;i<n;i++){
            if(visited[i]==0 && min>min_array[i]){
                min=min_array[i];
                index=i;
            }
        }
        k++;
    }
    for(int i=0;i<n;i++){
        printf("%d ",value[i]);
    }
    for(int i=0;i<n;i++){
        printf("%d ",parent[i]);
    }
}
