#include <stdio.h>

int main() {
    int pid[20], bt[20], at[20], wt[20], tat[20], ct[20];
    int n, completed = 0, time = 0, i, smallest;
    int visited[20] = {0};
    float avgWT = 0, avgTAT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Process IDs: ");
    for (i = 0; i < n; i++)
        scanf("%d", &pid[i]);

    printf("Enter Burst Times: ");
    for (i = 0; i < n; i++)
        scanf("%d", &bt[i]);

    printf("Enter Arrival Times: ");
    for (i = 0; i < n; i++)
        scanf("%d", &at[i]);

    while (completed < n) {
        smallest = -1;

        // Find process with shortest burst time among arrived ones
        for (i = 0; i < n; i++) {
            if (visited[i] == 0 && at[i] <= time) {
                if (smallest == -1 || bt[i] < bt[smallest]) {
                    smallest = i;
                }
            }
        }

        // If no process has arrived yet, move time forward
        if (smallest == -1) {
            time++;
            continue;
        }

        // Execute the selected job
        time += bt[smallest];
        ct[smallest] = time;
        tat[smallest] = ct[smallest] - at[smallest];
        wt[smallest] = tat[smallest] - bt[smallest];

        visited[smallest] = 1;
        completed++;
    }

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);

        avgWT += wt[i];
        avgTAT += tat[i];
    }

    avgWT /= n;
    avgTAT /= n;

    printf("\nAverage Waiting Time: %.2f", avgWT);
    printf("\nAverage Turnaround Time: %.2f\n", avgTAT);

    return 0;
}
