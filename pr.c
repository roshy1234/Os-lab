#include <stdio.h>

struct process {
    int id,at,bt,wt,tat,pr;
} P[20],temp;

void main() {
    int n;
    printf("Enter the number of processes -- ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        printf("Enter the priority and burst time of process %d -- ", i + 1);
        scanf("%d %d", &P[i].pr, &P[i].bt);
        P[i].id = i + 1;
        }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(P[j].pr>P[j+1].pr){
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
    P[0].wt=0;
    P[0].tat=P[0].bt;
    for(int i=1;i<n;i++){
        P[i].wt=P[i-1].tat;
        P[i].tat=P[i].wt+P[i].bt;
    }
    //Displaying the table
    printf("\nProcess\tpr\tBT\tTAT\tWT\n");
    for(int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", P[i].id,P[i].pr,P[i].bt, P[i].tat, P[i].wt);
    }
}