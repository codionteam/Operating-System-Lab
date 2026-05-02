#include <stdio.h>

int main()
{
    int pages[50], frames[10];
    int n, f, i, j, k, pos, faults = 0;
    int farthest, found;

    printf("Enter number of frames: ");
    scanf("%d", &f);

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter String: ");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    for(i = 0; i < f; i++)
        frames[i] = -1;

    for(i = 0; i < n; i++)
    {
        found = 0;

        // Check if page already in frame (Hit)
        for(j = 0; j < f; j++)
        {
            if(frames[j] == pages[i])
            {
                found = 1;
                break;
            }
        }

        // Page Fault
        if(found == 0)
        {
            // If empty frame available
            int empty = -1;

            for(j = 0; j < f; j++)
            {
                if(frames[j] == -1)
                {
                    empty = j;
                    break;
                }
            }

            if(empty != -1)
            {
                pos = empty;
            }
            else
            {
                // Find optimal page to replace
                farthest = -1;
                pos = 0;

                for(j = 0; j < f; j++)
                {
                    int found_future = 0;

                    for(k = i + 1; k < n; k++)
                    {
                        if(frames[j] == pages[k])
                        {
                            found_future = 1;
                            if(k > farthest)
                            {
                                farthest = k;
                                pos = j;
                            }
                            break;
                        }
                    }

                    // If page is never used again
                    if(found_future == 0)
                    {
                        pos = j;
                        break;
                    }
                }
            }

            frames[pos] = pages[i];
            faults++;
        }

        printf("%d -> ", pages[i]);

        for(j = 0; j < f; j++)
        {
            if(frames[j] == -1)
                printf("- ");
            else
                printf("%d ", frames[j]);
        }
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", faults);

    return 0;
}