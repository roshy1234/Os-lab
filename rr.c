#include <stdio.h>

struct process {
    int id, bt, wt, tat, tbt, at;
} P[20];

void main() {
    int i = 0, x = 0, y = 0, n, tq;
    printf("Enter the number of processes -- ");
    scanf("%d", &n);
    printf("Enter the time quantum -- ");
    scanf("%d", &tq);
    for(i = 0; i < n; i++) {
        printf("Enter the arrival time and burst time of process %d -- ", i + 1);
        scanf("%d %d", &P[i].at, &P[i].bt);
        P[i].id = i + 1;
        P[i].tbt = P[i].bt;
    }
    printf("Gantt Chart -- \n");
    while(1) {
        int j, min_at = -1;
        for(j = 0; j < n; j++) {
            if(P[j].bt > 0) {
                if(min_at == -1 || P[j].at < min_at) {
                    min_at = P[j].at;
                }
            }
        }
        if(min_at != -1 && min_at > x) {
            x = min_at;
        }
        if(P[i].bt > 0 && P[i].at <= x) {
            if(P[i].bt > tq) {
                P[i].bt -= tq;
                x += tq;
                printf("P%d ", P[i].id);
            }
            else {
                x += P[i].bt;
                P[i].bt = 0;

                P[i].tat = x - P[i].at; // TAT = completion time - arrival time
                P[i].wt = P[i].tat - P[i].tbt; // WT = TAT - burst time
                printf("P%d ", P[i].id);
                y++;
                if(y == n) break;
            }
        }
        i = (i + 1) % n; // move to next process even if current process has 0 burst time
    }
    
    printf("\nProcess\tBT\tAT\tTAT\tWT\n");
    for(i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", P[i].id, P[i].at, P[i].tbt, P[i].tat, P[i].wt);
    }

}