#include <stdio.h>
int main()
{
    int n,i,cnt=0,time=0,idx;
    int pid[20],bt[20],at[20],pr[20],wt[20],tat[20],ct[20],vis[20]={0};

    printf("Enter the number of processes: ");
    scanf("%d",&n);

    printf("Enter process IDs:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &pid[i]);

    printf("Enter burst times:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &bt[i]);

    printf("Enter arrival times:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &at[i]);

    printf("Enter priorities (lower number = higher priority):\n");
    for (i = 0; i < n; i++)
        scanf("%d", &pr[i]);

    while(cnt<n)
    {
        idx=-1;
        for(i=0;i<n;i++)
        {
            if(!vis[i] && at[i]<=time)
            {
                if(idx == -1 || pr[i] < pr[idx] || (pr[i] == pr[idx] && at[i] < at[idx]))
            //  if(idx == -1 || pr[i] > pr[idx] || (pr[i] == pr[idx] && at[i] < at[idx])) higher number = higher priority
                {
                    idx=i;
                }

            }
        }

        if(idx==-1)
        {
            time++;
            continue;
        }

        time+=bt[idx];
        ct[idx]=time;
        tat[idx]=ct[idx]-at[idx];
        wt[idx]=tat[idx]-bt[idx];

        vis[idx]=1;
        cnt++;
    }

    float total_wt = 0, total_tat = 0;

    printf("\nPID\tAT\tBT\tPR\tCT\tWT\tTAT\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",pid[i], at[i], bt[i], pr[i], ct[i], wt[i], tat[i]);

        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f", total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);

    return 0;
}
