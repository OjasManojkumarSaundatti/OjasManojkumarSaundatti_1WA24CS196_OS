#include <stdio.h>
#include <limits.h>

int main()
{
    int n, i;
    int pid[20], arrival[20], burst[20];
    int remaining[20], completion[20], turnaround[20], waiting[20];
    int finished[20];

    int current_time = 0, completed = 0;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        pid[i] = i + 1;
        finished[i] = 0;

        printf("\nProcess %d\n", pid[i]);

        printf("Arrival Time: ");
        scanf("%d", &arrival[i]);

        printf("Burst Time: ");
        scanf("%d", &burst[i]);

        remaining[i] = burst[i];
    }

    while(completed < n)
    {
        int shortest = -1;
        int min = INT_MAX;

        for(i = 0; i < n; i++)
        {
            if(arrival[i] <= current_time && finished[i] == 0 && remaining[i] < min)
            {
                min = remaining[i];
                shortest = i;
            }
        }

        if(shortest == -1)
        {
            current_time++;
            continue;
        }

        remaining[shortest]--;
        current_time++;

        if(remaining[shortest] == 0)
        {
            finished[shortest] = 1;
            completed++;

            completion[shortest] = current_time;
            turnaround[shortest] = completion[shortest] - arrival[shortest];
            waiting[shortest] = turnaround[shortest] - burst[shortest];

            avg_wt += waiting[shortest];
            avg_tat += turnaround[shortest];
        }
    }

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], arrival[i], burst[i],
               completion[i], turnaround[i], waiting[i]);
    }

    printf("\nAverage Waiting Time: %.2f", avg_wt/n);
    printf("\nAverage Turnaround Time: %.2f\n", avg_tat/n);

    return 0;
}
