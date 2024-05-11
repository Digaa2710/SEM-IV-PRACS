#include<stdio.h>
int x=0;
int full=0;
int empty=10;
int mutex=1;

    void producer(){
        mutex--;
        empty--;
        x++;
        printf("Producer produces item %d",x);
        full++;
        mutex++;
    }

    void consumer(){
        mutex--;
        full--;
        printf("Consumer consumes item %d ",x);
        x--;
        empty++;
        mutex++;
    }
    
    int main(){
        int choice;
        
        do{
            printf("Enter choice:");
        scanf("%d",&choice);
            switch(choice){
                case 1:
                if((mutex==1) && (empty!=0)){
                    producer();
                }
                else{
                    printf("Buffer is full");
                }
                break;
                case 2:
                if((mutex==1) && (full!=0)){
                    consumer();
                }
                else{
                    printf("Buffer is empty");
                }
                break;
            }
        }while(choice!=3);
    }