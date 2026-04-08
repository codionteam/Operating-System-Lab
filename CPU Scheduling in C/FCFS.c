#include <stdio.h>

int main()
{
    int pid[50], bt[50], at[50];
    int st[50], ct[50], wt[50], tat[50];
    int n, i, j;

    printf("Enter the number of processes: ");
    scanf("%d",&n);

    printf("Enter process IDs:\n");
    for (i = 0; i < n; i++) scanf("%d", &pid[i]);

    printf("Enter burst times:\n");
    for (i = 0; i < n; i++) scanf("%d", &bt[i]);

    printf("Enter arrival times:\n");
    for (i = 0; i < n; i++) scanf("%d", &at[i]);

    // Sort by arrival time
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (at[j] < at[i]) {
                // swap AT
                int temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                // swap BT
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                // swap PID
                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;
            }
        }
    }

    // First process
    st[0] = at[0];
    ct[0] = st[0] + bt[0];   // 🔥 FIXED LINE
    tat[0] = ct[0] - at[0];
    wt[0] = tat[0] - bt[0];

    // Remaining processes
    for (i = 1; i < n; i++) {
        if (ct[i-1] < at[i])
            st[i] = at[i];
        else
            st[i] = ct[i-1];

        ct[i] = st[i] + bt[i];
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    float total_wt = 0, total_tat = 0;

    printf("\nPID\tAT\tBT\tST\tCT\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], at[i], bt[i], st[i], ct[i], wt[i], tat[i]);

        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f", total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);






    // 🔥 GANTT CHART PRINT
    printf("\nGantt Chart:\n");

    // Top bar
    printf(" ");
    for (i = 0; i < n; i++) {
        printf("------");
    }
    printf("\n|");

    // Process IDs
    for (i = 0; i < n; i++) {
        printf(" P%d |", pid[i]);
    }

    printf("\n ");

    // Bottom bar
    for (i = 0; i < n; i++) {
        printf("------");
    }

    // Time line
    printf("\n%d", st[0]);
    for (i = 0; i < n; i++) {
        printf("     %d", ct[i]);
    }

    printf("\n");

    return 0;
}
