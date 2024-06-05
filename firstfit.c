#include <stdio.h>
void main() {
    int bsize[10],psize[10],b,p,allocation[10];
    for(int i = 0; i < 10; i++) {
        allocation[i] = -1;
    }
    printf("Enter the number of blocks -- ");
    scanf("%d", &b);
    printf("Enter the size of each block -- ");
    for(int i = 0; i < b; i++) {
        scanf("%d", &bsize[i]);
    }
    printf("Enter the number of processes -- ");
    scanf("%d", &p);
    printf("Enter the size of each process -- ");
    for(int i = 0; i < p; i++) {
        scanf("%d", &psize[i]);
    }
    // First Fit algorithm
    for(int i = 0; i < p; i++) {
        for(int j = 0; j < b; j++) {
            if(bsize[j] >= psize[i]) {
                allocation[i] = j;
                bsize[j] -= psize[i];
                break;
            }
        }
    }
    printf("\nProcess no.\tProcess size\tBlock no.");
    for(int i = 0; i < p; i++) {
        printf("\n%d\t\t%d\t\t", i+1,psize[i]);
        if(allocation[i] != -1) {
            printf("%d", allocation[i]+1);
        }
        else {
            printf("Not allocated");
        }
    }
}