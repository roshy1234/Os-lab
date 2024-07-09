#include <stdio.h>

struct process {
    int id, bt, wt, tat, tbt;
} P[20];

void main() {
    int i = 0, x = 0, y = 0, n, tq;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the time quantum: ");
    scanf("%d", &tq);
    for (i = 0; i < n; i++) {
        printf("Enter burst time of process %d: ", i + 1);
        scanf("%d", &P[i].bt);
        P[i].id = i + 1;
        P[i].tbt = P[i].bt;
    }
    printf("Gantt Chart:\n");
    i=0;
    while (1) {
        if (P[i].bt > 0) {
            if (P[i].bt > tq) {
                P[i].bt -= tq;
                x += tq;
                printf("P%d ", P[i].id);
            } else {
                x += P[i].bt;
                P[i].bt = 0;

                P[i].tat = x; // Turnaround time = completion time
                P[i].wt = P[i].tat - P[i].tbt; // Waiting time = Turnaround time - burst time
                printf("P%d ", P[i].id);
                y++;
                if (y == n) break;
            }
        }
        i = (i + 1) % n; // Move to next process even if current process has 0 burst time
    }

    printf("\nProcess\tBT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\n", P[i].id, P[i].tbt, P[i].tat, P[i].wt);
    }
}