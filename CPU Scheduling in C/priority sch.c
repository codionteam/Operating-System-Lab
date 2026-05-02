#include <stdio.h>

int main() {
    int n, i;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[n], at[n], bt[n], pr[n];
    int wt[n], tat[n], completed[n];

    // Input
    for (i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("\nProcess %d:\n", pid[i]);

        printf("Arrival Time: ");
        scanf("%d", &at[i]);

        printf("Burst Time: ");
        scanf("%d", &bt[i]);

        printf("Priority (lower value = higher priority): ");
        scanf("%d", &pr[i]);

        completed[i] = 0;
    }

    int time = 0, done = 0;
    float total_wt = 0, total_tat = 0;

    while (done < n) {
        int idx = -1;            //no process is selected yet
        int highest_priority = 9999;        //large value, comparison purpose

        // Find highest priority process
        for (i = 0; i < n; i++) {
            if (at[i] <= time && completed[i] == 0) {
                if (pr[i] < highest_priority) {
                    highest_priority = pr[i];
                    idx = i;
                }
                else if (pr[i] == highest_priority) {        //if same priority, then choose process with earlier arrival time
                    if (at[i] < at[idx]) {
                        idx = i;
                    }
                }
            }
        }

        if (idx != -1) {              //if a process is selected
            time += bt[idx];

            tat[idx] = time - at[idx];
            wt[idx] = tat[idx] - bt[idx];

            total_wt += wt[idx];
            total_tat += tat[idx];

            completed[idx] = 1;
            done++;
        } else {
            time++; // CPU idle
        }
    }

    // Output
    printf("\nPID\tAT\tBT\tPR\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], at[i], bt[i], pr[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);

    return 0;
}
