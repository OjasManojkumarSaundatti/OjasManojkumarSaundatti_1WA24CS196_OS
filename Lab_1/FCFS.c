#include <stdio.h>

int main() {
    int n, i, j;

    printf("Enter total number of processes: ");
    scanf("%d", &n);

    int pid[n], arrival[n], burst[n];
    int completion[n], turnaround[n], waiting[n];

    for(i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("\nProcess %d\n", pid[i]);

        printf("Arrival Time: ");
        scanf("%d", &arrival[i]);

        printf("Burst Time: ");
        scanf("%d", &burst[i]);
    }
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(arrival[i] > arrival[j]) {
                int temp;

                temp = arrival[i];
                arrival[i] = arrival[j];
                arrival[j] = temp;

                temp = burst[i];
                burst[i] = burst[j];
                burst[j] = temp;

                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;
            }
        }
    }

    int current_time = 0;
    float totalTAT = 0, totalWT = 0;


    for(i = 0; i < n; i++) {

        if(current_time < arrival[i]) {
            current_time = arrival[i];
        }

        completion[i] = current_time + burst[i];

        turnaround[i] = completion[i] - arrival[i];

        waiting[i] = turnaround[i] - burst[i];

        current_time = completion[i];

        totalTAT += turnaround[i];
        totalWT += waiting[i];
    }

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], arrival[i], burst[i],
               completion[i], turnaround[i], waiting[i]);
    }

    printf("\nAverage Turnaround Time = %.2f", totalTAT / n);
    printf("\nAverage Waiting Time = %.2f\n", totalWT / n);

    return 0;
}
