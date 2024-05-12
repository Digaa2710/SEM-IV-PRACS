#include<stdio.h>
#include<stdlib.h>
#define n 10

int main(){
    int queue[]={45, 21, 67, 90, 4, 89, 52, 61, 87, 25};
   int head=50;
  int visited[n], i, idx, min, count = 0, curr = head, total = 0;
	for (i = 0; i < n; i++)
		visited[i] = 0;
	while (count < n) {
		min = 1000;
		for (i = 0; i < n; i++){
			if (!visited[i] && abs(queue[i] - curr) < min) {
				min = abs(queue[i] - curr);
				idx = i;
			}
		}
		total += min;
		curr = queue[idx];
		visited[idx] = 1;
		count++;
	}
	printf("%d",total);
}
