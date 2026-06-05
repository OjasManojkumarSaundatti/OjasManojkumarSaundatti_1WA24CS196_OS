#include <stdio.h>

int main()
{
    int n, choice;
    int pid[20], pr[20], at[20], bt[20], rt[20];
    int ct[20], tat[20], wt[20];
    int completed = 0, current_time = 0;
    int i, selected, best_priority;

    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter priorities (1 for higher number means higher priority, 2 for lower number means higher priority): ");
    scanf("%d", &choice);

    printf("Enter priorities:\n");
    for(i=0;i<n;i++)
        scanf("%d",&pr[i]);

    printf("Enter arrival times:\n");
    for(i=0;i<n;i++)
        scanf("%d",&at[i]);

    printf("Enter burst times:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);
        rt[i] = bt[i];
        pid[i] = i+1;
    }

    while(completed < n)
    {
        selected = -1;

        if(choice == 2)
            best_priority = 9999;
        else
            best_priority = -1;

        for(i=0;i<n;i++)
        {
            if(at[i] <= current_time && rt[i] > 0)
            {
                if(choice == 2)
                {
                    if(pr[i] < best_priority)
                    {
                        best_priority = pr[i];
                        selected = i;
                    }
                }
                else
                {
                    if(pr[i] > best_priority)
                    {
                        best_priority = pr[i];
                        selected = i;
                    }
                }
            }
        }

        if(selected == -1)
        {
            current_time++;
        }
        else
        {
            rt[selected]--;
            current_time++;

            if(rt[selected] == 0)
            {
                ct[selected] = current_time;
                tat[selected] = ct[selected] - at[selected];
                wt[selected] = tat[selected] - bt[selected];

                avg_tat += tat[selected];
                avg_wt += wt[selected];

                completed++;
            }
        }
    }

    printf("\nPriority Scheduling (Pre-Emptive):\n");
    printf("PID\tPrior\tAT\tBT\tCT\tTAT\tWT\tRT\n");

    for(i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        pid[i], pr[i], at[i], bt[i], ct[i], tat[i], wt[i], wt[i]);
    }

    printf("\nAverage turnaround time: %.6f\n", avg_tat/n);
    printf("Average waiting time: %.6f\n", avg_wt/n);

    return 0;
}
