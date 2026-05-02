#include <stdio.h>

int main() {
    int frames, pages[50], temp[50];
    int i, j, k, n, page_faults = 0, flag;

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter the page reference string:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    for(i = 0; i < frames; i++)  //Initializes all memory frames as empty (-1 means no page is currently loaded).
        temp[i] = -1;

    j = 0; // points to the oldest frame

    printf("\nPage\tFrames\n");

    for(i = 0; i < n; i++) {            //flag=0 means Miss, flag=1 means hit
        flag = 0;

        // Check if page is already in any frame
        for(k = 0; k < frames; k++) {
            if(temp[k] == pages[i]) {
                flag = 1;
                break;
            }
        }

        // Page fault occurs
        if(flag == 0) {
            temp[j] = pages[i];     //temp stores the page into frame
            j = (j + 1) % frames;
            page_faults++;
        }

        printf("%d\t", pages[i]);
        for(k = 0; k < frames; k++) {
            if(temp[k] != -1)
                printf("%d ", temp[k]);
            else
                printf("- ");
        }
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", page_faults);

    return 0;
}

