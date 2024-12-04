#include<stdio.h>
typedef struct{
	int pid;
	int burst;
} process;

void turnaroundtime(process p[], int n, int waiting[], int turnaround[]) {
	int i;
	for(i = 0; i < n; i++) {
		turnaround[i] = p[i].burst + waiting[i];
	}
}

void waitingtime(process p[], int n, int waiting[], int quantum) {
	int i, rem_bt[n], t = 0, flag;
	for(i = 0; i < n; i++) {
		rem_bt[i] = p[i].burst;
		waiting[i] = 0;
	}
	
	while(1) {
		flag = 1;
		for(i = 0; i < n; i++) {
			if(rem_bt[i] > 0) {
				flag = 0;
				if(rem_bt[i] > quantum) {
					t += quantum;
					rem_bt[i] -= quantum;
				} else {
					t += rem_bt[i];
					waiting[i] = t - p[i].burst;
					rem_bt[i] = 0;
				}
			}
		}
		if(flag == 1) {
			break;
		}
	}
}
void calculateAverage(process p[], int n, int quantum) {
	int i, waiting[n], turnaround[n];
	int totalwaiting = 0, totalturnaround = 0;
	waitingtime(p, n, waiting, quantum);
	turnaroundtime(p, n, waiting, turnaround);
	printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
	for(i = 0; i < n; i++) {
		totalwaiting += waiting[i];
		totalturnaround += turnaround[i];
		printf("%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].burst, waiting[i], turnaround[i]);
	}
	double averagewaiting = (double)totalwaiting / n;
	double averageturnaround = (double)totalturnaround / n;
	printf("Average Waiting Time: %.4f\n", averagewaiting);
	printf("Average Turn Around Time: %.4f\n", averageturnaround);
}
int main() {
	int i, n, quantum;
	printf("This is Dhiraj sharma.\n");
	printf("Enter the number of processes: ");
	scanf("%d", &n);
	process p[n];
	for(i = 0; i < n; i++) {
		printf("Process %d:\n", i + 1);
		p[i].pid = i + 1;
		printf("Burst Time: ");
		scanf("%d", &p[i].burst);
	}	
	printf("Enter the quantum size: ");
	scanf("%d", &quantum);
	calculateAverage(p, n, quantum);
	return 0;
}