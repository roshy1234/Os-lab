#include <stdio.h>

void main() {
    int n,r,need[10][10],alloc[10][10],max[10][10],avail[10];
    printf("Enter the number of processes -- ");
    scanf("%d", &n);
    printf("Enter the number of resources -- ");
    scanf("%d", &r);
    printf("Enter the allocation matrix -- \n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < r; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }
    printf("Enter the max matrix -- \n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < r; j++) {
            scanf("%d", &max[i][j]);
        }
    }
    printf("Enter the available resources -- ");
    for(int i = 0; i < r; i++) {
        scanf("%d", &avail[i]);
    }
    //need matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < r; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
    int finish[10],ans[10],ind=0;
    for(int i = 0; i < n; i++) {
        finish[i] = 0;
    }
    int flag,j;
    //deadlock detection
    for(int i = 0; i < n; i++) {
        flag = 0;
        if(finish[i] == 0) { //process is not finished
            for(j = 0; j < r; j++) { // check if need is less than available
                if(need[i][j] > avail[j]) {
                    flag=1;
                    break;
                    }
                }
                if(flag == 0) { //need is less than available so complete process
                    finish[i] = 1;
                    ans[ind++] = i;
                    for(int k = 0; k < r; k++) { //adding alloc to available
                        avail[k] += alloc[i][k];
                    }
                    i = -1;
                }
            }
        }
    flag = 0; //check if the system is in deadlock
    for(int i = 0; i < n; i++) {
        if(finish[i] == 0) {
            printf("The system is in deadlock\n"); 
            flag = 1;
            break;
        }
    }
    if(flag == 0) {
        printf("The system is in safe state\n");
        printf("Safe sequence is -- ");
        for(int i = 0; i < n; i++) {
            printf("P%d ", ans[i]);
        }
    }
}
