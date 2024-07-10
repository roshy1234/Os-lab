#include <stdio.h>

struct process {
    int id,at,bt,wt,tat;
} P[20],temp;

void main() {
    int n;
    printf("Enter the number of processes -- ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        printf("Enter the arrival time and burst time of process %d -- ", i + 1);
        scanf("%d %d", &P[i].at, &P[i].bt);
        P[i].id = i + 1;
        }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(P[j].at>P[j+1].at){
                temp=P[j];
                P[j]=P[j+1];
                P[j+1]=temp;
            }
        }
    }
    printf("Gantt Chart -- ");
    for(int i=0;i<n;i++){
        printf("P%d ",P[i].id);
    }

    P[0].wt = 0; // First process has no waiting time
    P[0].tat = P[0].bt; // Turnaround time of first process is its burst time
    for(int i = 1; i < n; i++) {
        P[i].wt = P[i-1].tat + P[i-1].wt - P[i].at; // Waiting time of current process
        P[i].tat = P[i].wt + P[i].bt; // Turnaround time
    }
    //Displaying the table
    printf("\nProcess\tAT\tBT\tTAT\tWT\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", P[i].id,P[i].at,P[i].bt, P[i].tat, P[i].wt);
    }
}