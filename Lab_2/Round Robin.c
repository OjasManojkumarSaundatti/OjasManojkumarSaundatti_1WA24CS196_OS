#include <stdio.h>

int main()
{
    int n, tq;
    int at[20], bt[20], rt[20];
    int ct[20], tat[20], wt[20];
    int i, time = 0, remain, flag = 0;

    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    printf("Enter Time Quantum: ");
    scanf("%d",&tq);

    printf("Enter arrival times:\n");
    for(i=0;i<n;i++)
        scanf("%d",&at[i]);

    printf("Enter burst times:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);
        rt[i] = bt[i];
    }

    remain = n;

    for(time=0,i=0; remain!=0;)
    {
        if(rt[i] <= tq && rt[i] > 0)
        {
            time += rt[i];
            rt[i] = 0;
            flag = 1;
        }
        else if(rt[i] > 0)
        {
            rt[i] -= tq;
            time += tq;
        }

        if(rt[i]==0 && flag==1)
        {
            remain--;
            ct[i] = time;
            tat[i] = time - at[i];
            wt[i] = tat[i] - bt[i];

            avg_wt += wt[i];
            avg_tat += tat[i];

            flag = 0;
        }

        if(i == n-1)
            i = 0;
        else if(at[i+1] <= time)
            i++;
        else
            i = 0;
    }

    printf("\nRRS scheduling:\n");
    printf("PID\tAT\tBT\tCT\tTAT\tWT\tRT\n");

    for(i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        i+1, at[i], bt[i], ct[i], tat[i], wt[i], rt[i]);
    }

    printf("\nAverage turnaround time: %.6fms\n", avg_tat/n);
    printf("\nAverage waiting time: %.6fms\n", avg_wt/n);

    return 0;
}
