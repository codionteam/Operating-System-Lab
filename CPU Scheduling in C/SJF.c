#include <stdio.h>
int main()
{
    int n, i, cnt=0, time=0, idx;
    int pid[20], bt[20], at[20], wt[20], tat[20], ct[20];
    int visited[20] = {0};

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Process IDs: ");
    for (i=0; i<n; i++)
        scanf("%d", &pid[i]);

    printf("Enter Burst Times: ");
    for (i=0; i<n; i++)
        scanf("%d", &bt[i]);

    printf("Enter Arrival Times: ");
    for (i=0; i<n; i++)
        scanf("%d", &at[i]);

    while (cnt < n)
    {
        idx = -1;
        // Find process with shortest BT among arrived ones
        for (i=0; i<n; i++)
        {
            if (visited[i] == 0 && at[i] <= time)
            {
                if (idx == -1 || bt[i] < bt[idx] || (bt[i] == bt[idx] && at[i] < at[idx]))
                {
                    idx = i;
                }
            }
        }
        // If no process has arrived → CPU idle
        if (idx == -1)
        {
            time++;
            continue;
        }

        // Handle idle gap (important fix)
        if (time < at[idx])
            time = at[idx];

        // Execute process
        time += bt[idx];
        ct[idx] = time;
        tat[idx] = ct[idx] - at[idx];
        wt[idx] = tat[idx] - bt[idx];

        visited[idx] = 1;
        cnt++;
    }
    float avgWT=0, avgTAT=0;

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (i=0; i<n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);

        avgWT += wt[i];
        avgTAT += tat[i];
    }

    printf("\nAverage Waiting Time: %.2f", avgWT/n);
    printf("\nAverage Turnaround Time: %.2f\n", avgTAT/n);

    return 0;
}
