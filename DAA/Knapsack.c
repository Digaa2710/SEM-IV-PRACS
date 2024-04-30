#include<stdio.h>

int main() {
    int n;
    printf("Enter number of profits and weights:");
    scanf("%d",&n);
    int profit[n];
    printf("Enter profits:");
    for(int i=0;i<n;i++){
        scanf("%d",&profit[i]);
    }
    int weight[n];
    printf("Enter weights:");
    for(int i=0;i<n;i++){
        scanf("%d",&weight[i]);
    }
    
    float ratio[n];
    int totalWeight ;
    printf("Enter weight required:");
    scanf("%d",&totalWeight);
    int sum = totalWeight;

    for(int i = 0; i < n; i++) {
         ratio[i] = (float) profit[i] / weight[i];
         printf("%f\n", ratio[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(ratio[i]<ratio[j]){
                float temp;
                temp=ratio[i];
                ratio[i]=ratio[j];
                ratio[j]=temp;
                
                int tempWeight=weight[i];
                weight[i]=weight[j];
                weight[j]=tempWeight;
                
                int tempProfit=profit[i];
                profit[i]=profit[j];
                profit[j]=tempProfit;
            }
        }
    }
    float profit_ratio[n];
    int currentWeight = 0; 
    int i = 0;
    int sum1 = 0;
    while(totalWeight >= 0) {
        totalWeight = totalWeight - weight[i];
        if(totalWeight > 0) {
            profit_ratio[i] = 1;
        } else if(totalWeight == 0) {
            profit_ratio[i] = 0;
        } else {
            profit_ratio[i] = (float) (sum - sum1) / weight[i];
        }
        sum1 += weight[i];
        i++;
    }
    printf("Ratios is as follows:\n");
    for(int i = 0; i < n; i++) {
        printf("%f ", profit_ratio[i]);
    }
    printf("\n");
   float total_profit[n];
   float totalProfit=0;
   for(int i=0;i<n;i++){
       totalProfit=totalProfit+profit_ratio[i]*profit[i];
   }
   printf("Total profit earned is: %f",totalProfit);
}
