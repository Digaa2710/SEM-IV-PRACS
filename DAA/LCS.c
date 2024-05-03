#include<stdio.h>
#include<string.h>
char sequence[100];
int count=0;
int LCS[100][100];
char direction[100][100];
void print(int i,int j,char m[]){
    
    if(i==0 || j==0)
    return;
    if (direction[i][j]=='C'){
    print(i-1,j-1,m);
    sequence[count]=m[i-1];
    count++;
   
    
    }
    if(direction[i][j]=='L'){
        print(i,j-1,m);
    }
    if(direction[i][j]=='U'){
        print(i-1,j,m);
    }
 
   
}
int main(){
    char m[100],n[100];
    printf("Enter string1");
    scanf("%s",m);
    printf("Enter string2");
    scanf("%s",n);
    int x,y;
    x=strlen(m);
    y=strlen(n);
   
    for(int i=0;i<x+1;i++){
        LCS[i][0]=0;
    }
    for(int j=0;j<y+1;j++){
        LCS[0][j]=0;
    }
    for(int i=1;i<x+1;i++){
        for(int j=1;j<y+1;j++){
            if(m[i-1]==n[j-1]){
                LCS[i][j]=LCS[i-1][j-1]+1;
                direction[i][j]='C';
            }
            else if(LCS[i-1][j]>LCS[i][j-1]){
                LCS[i][j]=LCS[i-1][j];
                direction[i][j]='U';
            }
            else{
                LCS[i][j]=LCS[i][j-1];
                direction[i][j]='L';
                
            }
        }
    }
    for(int i=0;i<x+1;i++){
        for(int j=0;j<y+1;j++){
            printf("%d ",LCS[i][j]);
        }
        printf("\n");
    }
    
    
    int k=x,l=y;
    print(x,y,m);
   
   
    for(int i=0;i<count;i++){
        printf("%c",sequence[i]);
    }
    
    
}