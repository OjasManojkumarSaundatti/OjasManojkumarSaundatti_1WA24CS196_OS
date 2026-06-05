#include <stdio.h>

int main() {
    int n, i;

    printf("Enter total number of processes: ");
    scanf("%d",&n);

    int at[n], bt[n], ct[n], tat[n], wt[n];
    float avg_tat = 0, avg_wt = 0;

    for(i=0;i<n;i++) {
        printf("\nProcess [%d]\n", i+1);

        printf("Arrival time: ");
        scanf("%d",&at[i]);

        printf("Burst time: ");
        scanf("%d",&bt[i]);
    }

    ct[0] = at[0] + bt[0];

    for(i=1;i<n;i++) {
        if(ct[i-1] < at[i])
            ct[i] = at[i] + bt[i];
        else
            ct[i] = ct[i-1] + bt[i];
    }

    for(i=0;i<n;i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        avg_tat += tat[i];
        avg_wt += wt[i];
    }

    avg_tat = avg_tat / n;
    avg_wt = avg_wt / n;

    printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");

    for(i=0;i<n;i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
        i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Turnaround Time: %.2f", avg_tat);
    printf("\nAverage Waiting Time: %.2f", avg_wt);

    return 0;
}
