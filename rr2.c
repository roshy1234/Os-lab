#include <stdio.h>

struct process {
    int id, bt, wt, tat, tbt, at;
} P[20];

void main() {
    int i = 0, x = 0, y = 0, n, tq;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the time quantum: ");
    scanf("%d", &tq);
    for (i = 0; i < n; i++) {
        printf("Enter arrival time of process %d: ", i + 1);
        scanf("%d", &P[i].at);
        printf("Enter burst time of process %d: ", i + 1);
        scanf("%d", &P[i].bt);
        P[i].id = i + 1;
        P[i].tbt = P[i].bt;
    }

    int time = 0;
    printf("Gantt Chart:\n");
    while (1) {
        int done = 1;
        for (i = 0; i < n; i++) {
            if (P[i].at <= time && P[i].bt > 0) {
                done = 0;
                if (P[i].bt > tq) {
                    time += tq;
                    P[i].bt -= tq;
                    printf("P%d ", P[i].id);
                } else {
                    time += P[i].bt;
                    P[i].bt = 0;
                    P[i].tat = time - P[i].at; // Turnaround time = completion time - arrival time
                    P[i].wt = P[i].tat - P[i].tbt; // Waiting time = Turnaround time - burst time
                    printf("P%d ", P[i].id);
                    y++;
                }
            }
        }
        if (done == 1) break;
    }

    printf("\nProcess\tAT\tBT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", P[i].id, P[i].at, P[i].tbt, P[i].tat, P[i].wt);
    }
}
