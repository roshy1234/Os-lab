#include <stdio.h>
#include <stdlib.h>

void main() {
    int n,RQ[10],initial,thm=0,lr,sr,dir,size;
    printf("Enter the number of requests -- ");
    scanf("%d", &n);
    printf("Enter the request sequence : \n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &RQ[i]);
    }
    printf("Enter the initial head position -- ");
    scanf("%d", &initial);
    //fcfs disk scheduling algorithm

    for(int i=0;i<n;i++) {
        thm += abs(initial - RQ[i]);
        initial = RQ[i];
    }
    printf("Total head movement = %d\n", thm);
}