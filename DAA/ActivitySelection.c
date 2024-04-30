#include<stdio.h>
int main(){
    int n;
    printf("Enter number activities:");
    scanf("%d",&n);
    int start[n];
    printf("Enter start time:");
    for(int i=0;i<n;i++){
        scanf("%d",&start[i]);
    }
    int finish[n];
    printf("Enter finish time:");
    for(int i=0;i<n;i++){
        scanf("%d",&finish[i]);
    }
   
    int activity[n];
    for(int i=0;i<n;i++){
        activity[i]=i+1;
    }
    int k=0;
for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
        if(finish[i]>finish[j]){
            int temp=finish[i];
            finish[i]=finish[j];
            finish[j]=temp;
            
            int tempStart=start[i];
            start[i]=start[j];
            start[j]=tempStart;
            
            int tempAct=activity[i];
            activity[i]=activity[j];
            activity[j]=tempAct;
        }
    }
}
        printf("A%d ",activity[0]);
    
    for(int j=1;j<n;j++){
        if(start[j]>=finish[k]){
            printf("A%d ",activity[j]);
            k=j;
        }
    }
    return 0;
}