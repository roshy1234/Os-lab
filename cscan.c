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
    printf("Enter the size of the disk -- ");
    scanf("%d", &size);
    printf("Enter the head movement direction 1 to high and 0 to low -- ");
    scanf("%d", &dir);
    lr = RQ[0];
    sr = RQ[0];
    for(int i=0;i<n;i++){
        if(RQ[i]>lr) {
            lr = RQ[i];
        }
        if(RQ[i]<sr) {
            sr = RQ[i];
        }
    }
    int m = sr;
    int l = lr;
    for(int i=0;i<n;i++) {
        if(RQ[i]>m && RQ[i]<initial) {
            m = RQ[i];
        }
    }
    for(int i=0;i<n;i++) {
        if(RQ[i]<l && RQ[i]>initial) {
            l = RQ[i];
        }
    }
    if(dir == 0) {
        thm = initial + size + size - l;
        printf("The total head movement is %d\n", thm);
    }
    else {
        thm = size - initial + size + m;
        printf("The total head movement is %d\n", thm);
    }
    printf("%d\n", m);
}