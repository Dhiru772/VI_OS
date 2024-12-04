#include<stdio.h>
#include<conio.h>

typedef struct{
    int pid;
    int burst;
    int priority;

}process;

void swap(process *a, process *b){
    process temp;
    temp= *a;
    *a= *b;
    *b= temp;
}

void sort(process p[], int n){
    int i, j, min;
    for(i=0; i<n-1;i++){
        min=i;
        for(j=i+1;j<n;j++){
            if(p[j].priority<p[min].priority)
                min=j;
        }
        swap(&p[i],&p[min]);
    }
}

void calculateTime(process p[], int n, int waiting[], int turnAround[]){
    int i;
    waiting[0]=0;
    for(i=1;i<n;i++)
        waiting[i]=waiting[i-1]+p[i-1].burst;
    for(i=0;i<n;i++)
        turnAround[i]=waiting[i]+p[i].burst;
}

void calculateAverage(process p[], int n){
    int i, waiting[n], turnAround[n];
    sort(p,n);
    calculateTime(p, n, waiting, turnAround);
    printf("Process\tBurst time\tPriority\tWaiting time\tTurnaround time\n");
    int totalWaiting = 0, totalTurnAround = 0;
    for(i=0;i<n;i++){
        printf("%d\t\t %d\t\t %d\t\t %d\t\t %d\n",p[i].pid, p[i].burst, p[i].priority, waiting[i], turnAround[i]);
        totalWaiting += waiting[i];
        totalTurnAround += turnAround[i];
    }
    double averageWaiting=(double)totalWaiting/n;
    double averageTurnaround=(double)totalTurnAround/n;
    printf("\nAverage waiting time: %f",averageWaiting);
    printf("\nAverage turnAround time: %f", averageTurnaround);
}

void main(){
    int i,n;
    printf("***Dhiraj Sharma\n");
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    process p[n];
    printf("Enter burst time and priority:\n");
    for(i=0;i<n;i++){
        printf("Process %d:\n",i+1);
        p[i].pid=i+1;
        printf("burst time: ");
        scanf("%d",&p[i].burst);
        printf("priority: ");
        scanf("%d", &p[i].priority);
    }
    calculateAverage(p,n);
    getch();
}