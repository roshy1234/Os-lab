#include <stdio.h>

void main() {
    int i, j, min, rs[25], m[10], count[10], use_order[10], n, f, pf = 0;

    printf("Enter the length of the reference string -- ");
    scanf("%d", &n);

    printf("Enter the reference string -- ");
    for(i = 0; i < n; i++) {
        scanf("%d", &rs[i]);
    }

    printf("Enter the number of frames -- ");
    scanf("%d", &f);

    // Initialize frames, counts, and use order
    for(i = 0; i < f; i++) {
        m[i] = -1;        // -1 indicates an empty frame
        count[i] = 0;     // Frequency of pages in frames
        use_order[i] = 0; // Order of usage to manage ties (for FIFO replacement in case of tie)
    }

    printf("\nThe Page Replacement process is -- \n");

    for(i = 0; i < n; i++) {
        int found = 0;
        int current_page = rs[i];

        // Check if the page is already in a frame
        for(j = 0; j < f; j++) {
            if(m[j] == current_page) {
                count[j]++;        // Increase frequency count if page is found
                found = 1;
                break;
            }
        }

        if(!found) {
            // If there's an empty frame, use it
            int added_to_frame = 0;
            for(j = 0; j < f; j++) {
                if(m[j] == -1) {
                    m[j] = current_page;
                    count[j] = 1;         // Initialize frequency count for new page
                    use_order[j] = i;     // Set use order to the current time
                    added_to_frame = 1;
                    pf++;                 // Increment page fault count
                    break;
                }
            }

            // If no empty frame was found, replace the LFU page
            if (!added_to_frame) {
                // Find the least frequently used page
                min = 0;
                for(j = 1; j < f; j++) {
                    if(count[j] < count[min]) {
                        min = j;
                    } else if(count[j] == count[min]) {
                        // In case of tie, select the page with the oldest use_order
                        if(use_order[j] < use_order[min]) {
                            min = j;
                        }
                    }
                }

                // Replace the page at position `min`
                m[min] = current_page;
                count[min] = 1;       // Reset frequency count for new page
                use_order[min] = i;   // Update use order to the current time
                pf++;                 // Increment page fault count
            }
        }

        // Print the current state of frames
        for(j = 0; j < f; j++) {
            if(m[j] != -1) // Only print valid pages in frames
                printf("%d\t", m[j]);
            else
                printf("-\t"); // Empty frame indicator
        }
        
        // Indicate a page fault occurred if the page wasn't found
        if(!found)
            printf("PF no. -- %d", pf);
        
        printf("\n");
    }
    printf("\nTotal Page Faults -- %d", pf);
}
