    #include <stdio.h>
    #include <math.h>

    int gcd(int a, int b) {
        while (b != 0) {
            int t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

    int lcm(int a, int b) {
        return (a * b) / gcd(a, b);
    }

    int main() {
        printf("Name:Ojas Manojkumar Ssundatti\n" "USN:1WA24CS196\n" "PRG:Rate monotonic scheduling (RMS) Algorithm\n");
        int n, i;

        printf("Enter the number of processes:");
        scanf("%d", &n);

        int bt[n], p[n];

        printf("Enter the CPU burst times:\n");
        for (i = 0; i < n; i++) {
            scanf("%d", &bt[i]);
        }

        printf("Enter the time periods:\n");
        for (i = 0; i < n; i++) {
            scanf("%d", &p[i]);
        }

        int hyper = p[0];
        for (i = 1; i < n; i++) {
            hyper = lcm(hyper, p[i]);
        }

        printf("LCM=%d\n\n", hyper);

        printf("Rate Monotone Scheduling:\n");
        printf("PID\tBurst\tPeriod\n");
        for (i = 0; i < n; i++) {
            printf("%d\t%d\t%d\n", i + 1, bt[i], p[i]);
        }

        float U = 0;
        for (i = 0; i < n; i++) {
            U += (float)bt[i] / p[i];
        }

        float bound = n * (pow(2, (float)1/n) - 1);

        printf("\n%f <= %f => %s\n",
            U, bound, (U <= bound) ? "true" : "false");

        printf("Scheduling occurs for %d ms\n", hyper);

        int rem[n];
        for (i = 0; i < n; i++)
            rem[i] = 0;

        printf("\n");

        int prev = -2;

        for (int time = 0; time < hyper; time++) {

            for (i = 0; i < n; i++) {
                if (time % p[i] == 0) {
                    rem[i] = bt[i];
                }
            }

            int selected = -1;

            for (i = 0; i < n; i++) {
                if (rem[i] > 0) {
                    if (selected == -1 || p[i] < p[selected]) {
                        selected = i;
                    }
                }
            }

            if (selected != prev) {
                if (selected == -1)
                    printf("%dms onwards: CPU is idle\n", time);
                else
                    printf("%dms onwards: Process %d running\n", time, selected + 1);
            }

            if (selected != -1) {
                rem[selected]--;
            }

            prev = selected;
        }

        return 0;
    }