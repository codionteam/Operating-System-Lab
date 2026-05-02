#include <stdio.h>

int main() {
    int frames, pages[50], temp[10], recent[10];
    int n, i, j, k, pos, page_faults = 0, flag1, flag2;

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string: ");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    // initialize frames to -1
    for(i = 0; i < frames; i++)
        temp[i] = -1;     //Initializes all memory frames as empty (-1 means no page is currently loaded).

    printf("\nPage\tFrames\n");

    for(i = 0; i < n; i++) {
        flag1 = flag2 = 0;     //miss

        // Check if page already exists (HIT)
        for(j = 0; j < frames; j++) {
            if(temp[j] == pages[i]) {
                flag1 = flag2 = 1;  // HIT
                recent[j] = i;      // update recent use
                break;
            }
        }

        // MISS condition
        if(flag1 == 0) {
            // Check if empty frame exists
            for(j = 0; j < frames; j++) {
                if(temp[j] == -1) {          // empty frame found
                    temp[j] = pages[i];
                    recent[j] = i;           // record recent use
                    page_faults++;
                    flag2 = 1;
                    break;
                }
            }
        }

        // If still MISS → choose LRU page to replace
        if(flag2 == 0) {    //miss and no empty frame;choose LRU replacement
            int min = recent[0];
            pos = 0;

            for(j = 1; j < frames; j++) {
                if(recent[j] < min) {  // find least recently used
                    min = recent[j];
                    pos = j;
                }
            }

            temp[pos] = pages[i];      // replace frame
            recent[pos] = i;           // update recent use
            page_faults++;
        }

        // Print current frame contents
        printf("%d\t", pages[i]);
        for(k = 0; k < frames; k++) {
            if(temp[k] == -1)
                printf("- ");
            else
                printf("%d ", temp[k]);
        }
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", page_faults);

    return 0;
}
