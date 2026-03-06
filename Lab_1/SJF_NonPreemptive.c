#include <stdio.h>

int main() {
    int n, i;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[n], arrival[n], burst[n], ct[n], tat[n], wt[n], finished[n];

    for(i = 0; i < n; i++) {
        pid[i] = i + 1;
        finished[i] = 0;

        printf("\nProcess %d\n", pid[i]);

        printf("Arrival Time: ");
        scanf("%d", &arrival[i]);

        printf("Burst Time: ");
        scanf("%d", &burst[i]);
    }

    int completed = 0, current_time = 0;
    float total_tat = 0, total_wt = 0;

    while(completed < n) {
        int idx = -1;
        int min_bt = 9999;

        for(i = 0; i < n; i++) {
            if(arrival[i] <= current_time && finished[i] == 0) {
                if(burst[i] < min_bt) {
                    min_bt = burst[i];
                    idx = i;
                }
            }
        }

        if(idx != -1) {
            ct[idx] = current_time + burst[idx];
            tat[idx] = ct[idx] - arrival[idx];
            wt[idx] = tat[idx] - burst[idx];

            current_time = ct[idx];
            finished[idx] = 1;
            completed++;

            total_tat += tat[idx];
            total_wt += wt[idx];
        }
        else {
            current_time++;
        }
    }

    printf("\nSJF Scheduling Result\n");
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], arrival[i], burst[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Turnaround Time = %.2f", total_tat/n);
    printf("\nAverage Waiting Time = %.2f\n", total_wt/n);

    return 0;
}
