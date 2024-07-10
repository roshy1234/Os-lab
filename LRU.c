#include <stdio.h>

int main() {
    int i, j, n, f, pf = 0, next = 0, hits = 0;
    int rs[25], Frame[10],time[10];
    printf("Enter the length of the reference string -- ");
    scanf("%d", &n);
    printf("Enter the reference string -- ");
    for (i = 0; i < n; i++) {
        scanf("%d", &rs[i]);
    }
    printf("Enter the number of frames -- ");
    scanf("%d", &f);

    for (i = 0; i < f; i++) {
        Frame[i] = -1; // Initialize frame array with -1 indicating empty slots
        time[i]=0;
    }

    // LRU Page Replacement
    for (i = 0; i < n; i++) {
        int found = 0;
        for (j = 0; j < f; j++) {
            if (rs[i] == Frame[j]) {
                found = 1;
                hits++;
                time[j]++;
                break;
            }
        }
        if(found!=1){
            int min=0;
            for(int j=1;j<f;j++){
                if(time[j]<time[min]){
                    min=j;
                }
            }
            Frame[min]=rs[i];
            time[min]++;
            pf++;
        }
        for (int k = 0; k < f; k++) {
            if (Frame[k] == -1) printf("- "); // Indicates an empty frame
            else printf("%d ", Frame[k]);
        }
        printf("\n");
    }
    printf("Total Page Faults: %d\n", pf);
    printf("Total Hits: %d\n", hits);
    printf("Hit Ratio: %.2f\n", (float)hits / n);
    
    return 0;
}