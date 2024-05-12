#include <stdio.h>

struct Process {
	int at, bt, ct, wt, tat, remaining, visited;
} p[20];

int main() {
	int i, j, l, n, quantum, ready[100], k = 0, completed = 0, clock = 0;
	printf("Enter the number of processes: ");
	scanf("%d", &n);
	printf("\nEnter the arrival time of processes: ");
	for (i = 0; i < n; i++)
		scanf("%d", &p[i].at);
	printf("\nEnter the burst time of processes: ");
	for (i = 0; i < n; i++) {
		scanf("%d", &p[i].bt);
		p[i].remaining = p[i].bt;
	}
	printf("\nEnter the quantum time: ");
	scanf("%d", &quantum);
	for (i = 0; i < n; i++)
		p[i].visited = 0;
	i = 0;
	l = 0;
	while (completed < n) {
		while (i < n && !p[i].visited && p[i].at <= clock + quantum) {
			for (j = l; j < k; j++)
				if (ready[j] == i)
					break;
			if (j == k)			
				ready[k++] = i;
			i++;
		}
		if (p[ready[l]].remaining > quantum) {
			p[ready[l]].remaining -= quantum;
			clock += quantum;
			ready[k++] = ready[l];
		}
		else {
			clock += p[ready[l]].remaining;
			p[ready[l]].remaining = 0;
			p[ready[l]].visited = 1;
			p[ready[l]].ct = clock;
			p[ready[l]].tat = p[ready[l]].ct - p[ready[l]].at;
			p[ready[l]].wt = p[ready[l]].tat - p[ready[l]].bt;
			completed++;
		}
		l++;
	}
	printf("\nPid\tAT\tBT\tCT\tWT\tTAT");
	for (i = 0; i < n; i++)
		printf("\nP%d\t%d\t%d\t%d\t%d\t%d", i + 1, p[i].at, p[i].bt, p[i].ct, p[i].wt, p[i].tat);
	return 0;
}