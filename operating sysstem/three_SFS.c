#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct{
    int pid;
    int burst;
} processes;

void swap(processes *a, processes *b){
    processes temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void sort(processes p[],  int n){
    int i, j, min;
    for(i = 0; i < n-1; i++){
        min = i;
        for(j = i+1; j < n; j++){
            if(p[j].burst < p[min].burst)
                min = j;
        }
        swap(&p[i], &p[min]);
    }
}

void calculateTime(processes p[], int n, int waiting[], int turnaround[]){
    int i;
    waiting[0] = 0; // First process doesn't wait
    for(i = 1; i < n; i++){ // Start from i = 1 to avoid invalid index
        waiting[i] = waiting[i-1] + p[i-1].burst;
    }
    for(i = 0; i < n; i++){
        turnaround[i] = waiting[i] + p[i].burst;
    }
}

void calculateAverage(processes p[], int n){
    int i, waiting[n], turnaround[n];
    int totalwaiting = 0, totalturnaround = 0;
    sort(p, n);
    calculateTime(p, n, waiting, turnaround);
    printf("Processes\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++){
        totalwaiting += waiting[i];
        totalturnaround += turnaround[i];
        printf("%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].burst, waiting[i], turnaround[i]);
    }
    double averagewaiting = (double)totalwaiting / n;
    double averageturnaround = (double)totalturnaround / n;
    printf("\nAverage Waiting Time: %f", averagewaiting);
    printf("\nAverage Turnaround Time: %f", averageturnaround);
}

void main(){
    int i, n;
    printf("Dhiraj Sharma\n");
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    processes p[n];
    for(i = 0; i < n; i++){
        printf("Process %d\n", i+1);
        p[i].pid = i+1;
        printf("Burst Time: ");
        scanf("%d", &p[i].burst);
    }
    calculateAverage(p, n);
    getch();
}
