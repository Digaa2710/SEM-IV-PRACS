#include<stdio.h>

#include<malloc.h>
#define size 100
int n,a[size];

void merge(int l, int m, int r) {
	int b[n], i = l, j = m + 1, k = l;
	while(i <= m && j <= r) {
		if(a[i] < a[j])
			b[k++] = a[i++];
		else
			b[k++] = a[j++];
	}
	while(i <= m)
		b[k++] = a[i++];
	while(j <= r)
		b[k++] = a[j++];
	for(i = l; i <= r; i++)
		a[i] = b[i];
}

void mergeSort(int l, int r) {
	int m = (l + r) / 2;
	if(l < r) {
		mergeSort(l, m);
		mergeSort(m + 1, r);
		merge(l, m, r);
	}
}

int main() {
	int i;
	printf("Enter the number of elements: ");
	scanf("%d", &n);

	printf("Enter the elements: ");
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	
	mergeSort(0, n - 1);
	for(i = 0; i < n; i++)
		printf("%d ", a[i]);
}
