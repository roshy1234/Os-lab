#include <stdio.h>

struct process {
    int id, at, bt, wt, tat, pr;
} P[20], temp;

void main() {
    int n;
    printf("Enter the number of processes -- ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter the arrival time, priority, and burst time of process %d -- ", i + 1);
        scanf("%d %d %d", &P[i].at, &P[i].pr, &P[i].bt);
        P[i].id = i + 1;
    }

    // Sorting processes based on priority first, then arrival time
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (P[j].pr > P[j + 1].pr || (P[j].pr == P[j + 1].pr && P[j].at > P[j + 1].at)) {
                temp = P[j];
                P[j] = P[j + 1];
                P[j + 1] = temp;
            }
        }
    }

    int time = 0;
    printf("Gantt Chart -- ");
    for (int i = 0; i < n; i++) {
        if (time < P[i].at) {
            time = P[i].at; // Adjust time to the arrival time of the next process
        }
        printf("P%d ", P[i].id);
        P[i].wt = time - P[i].at;
        time += P[i].bt;
        P[i].tat = time - P[i].at;
    }

    // Displaying the table
    printf("\nProcess\tAT\tPR\tBT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", P[i].id, P[i].at, P[i].pr, P[i].bt, P[i].tat, P[i].wt);
    }
}

