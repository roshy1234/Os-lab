#include <stdio.h>

struct process {
    int id, at, pr, bt, wt, tat, ct;
} P[20], temp;

void main() {
    int n,time = 0, completed = 0;
    printf("Enter the number of processes -- ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter the arrival time, priority, and burst time of process %d -- ", i + 1);
        scanf("%d %d %d", &P[i].at, &P[i].pr, &P[i].bt);
        P[i].id = i + 1;
    }

    // Sorting processes based on arrival time first, then priority
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (P[j].at > P[j + 1].at || (P[j].at == P[j + 1].at && P[j].pr > P[j + 1].pr)) {
                temp = P[j];
                P[j] = P[j + 1];
                P[j + 1] = temp;
            }
        }
    }

    printf("Gantt Chart -- ");
    while (completed < n) {
        int idx = -1;
        int min_pr = 9999;
        for (int i = 0; i < n; i++) {
            if (P[i].at <= time && P[i].bt > 0 && P[i].pr < min_pr) {
                min_pr = P[i].pr;
                idx = i;
            }
        }

        if (idx != -1) {
            time += P[idx].bt;
            P[idx].ct = time;
            P[idx].tat = P[idx].ct - P[idx].at;
            P[idx].wt = P[idx].tat - P[idx].bt;
            P[idx].bt = 0;
            completed++;
            printf("P%d ", P[idx].id);
        } else {
            time++;
        }
    }

    // Calculate and print average waiting time and average turnaround time
    float avg_wt = 0, avg_tat = 0;
    for (int i = 0; i < n; i++) {
        avg_wt += P[i].wt;
        avg_tat += P[i].tat;
    }
    avg_wt /= n;
    avg_tat /= n;

    printf("\nAverage Waiting Time: %.2f", avg_wt);
    printf("\nAverage Turn Around Time: %.2f", avg_tat);

    // Print the process details
    printf("\nProcess\tAT\tPR\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", P[i].id, P[i].at, P[i].pr, P[i].bt, P[i].ct, P[i].tat, P[i].wt);
    }
}

