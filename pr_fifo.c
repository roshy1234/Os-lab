#include <stdio.h>

int main() {
    int i, j, n, f, pf = 0, next = 0, hits = 0;
    int rs[25], Frame[10], flag[25];
    printf("Enter the length of the reference string -- ");
    scanf("%d", &n);
    printf("Enter the reference string -- ");
    for (i = 0; i < n; i++) {
        scanf("%d", &rs[i]);
        flag[i] = 0;
    }
    printf("Enter the number of frames -- ");
    scanf("%d", &f);

    for (i = 0; i < f; i++) {
        Frame[i] = -1; // Initialize frame array with -1 indicating empty slots
    }

    // FIFO Page Replacement
    for (i = 0; i < n; i++) {
        int found = 0;
        for (j = 0; j < f; j++) {
            if (rs[i] == Frame[j]) {
                found = 1;
                hits++;
                break;
            }
        }
        if (!found) {
            Frame[next] = rs[i];
            next = (next + 1) % f; // Move to the next frame position, wrapping around
            pf++; // Increment page fault count
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