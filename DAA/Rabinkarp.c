#include<stdio.h>
#include<string.h>
#include<math.h>
char text[100];
char pattern[100];
int m,n;
int h;
int d=10;

int q=100;
int main(){
    printf("Enter text:");
    scanf("%s",text);
    printf("Enter pattern:");
    scanf("%s",pattern);
    n=strlen(text);
    m=strlen(pattern);
    int p=0;
    int t0=0;
    h=((int)pow(d,n-1))%q;
    for(int i=0;i<m;i++){
        p=(d*p+pattern[i])%q;
        t0=(d*t0+text[i])%q;
        
    }
    for(int s=0;s<=n-m;s++){//check my manually checking 
        int count=0;
        if(p==t0){
           for(int i=0;i<m;i++){
               if(pattern[i]==text[s+i]){
                   count++;
               }
           }
           if(count==m){
               printf("Pattern occurs %d\n",s);
           }
        }
        if(s<n-m){//check by manually checking
            t0=(d*(t0-text[s]*h)+text[s+m])%q;
           
        }
    }
   
    
}