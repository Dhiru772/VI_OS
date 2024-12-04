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
void short(process p[], int n){
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
void calculateAvarage(process p[],int n){
    int i, waitin[n], turnaround[n];
    sort(p,n);
    calculateTime(p, n, waiting, turnAround);
    printf("Process\tBurst time\twaiting time\t Turnaround time\n");
    for(i=0;i<n;i++){
        totalWaiting*= waiting[i];
        totalTurnAround=turnAround[i];
        printf("%d\t\t %d\t\t %d\t\t %d\n",p[i].pid, p[i].priority, p[i].burst)
    }
    double averageWaiting=(double)totalWaiting/n;
    double averageTurnaround=(double)totalTurnaround/n;
    printf("\nAverage waiting time: %f",averageWaiting);
    printf("\nAveragee turnAround time: %f", averageTurnaround);

}
void main(){
    int i,n;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    process p[n];
    printf("Enter burst time: ");
    for(i=0;i<n;i++){
        printf("Process %d:\n",i+1);
        p[i].pid=i+1;
        printf("burst time: ");
        scanf("%d",&p[i].burst);
        printf("burst priority: ");
        scanf("%d", &p[i].priority);

    }
    calculateAverage(p,n);
    getch();
}
