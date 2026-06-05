#include <stdio.h>

int main() {
    int pages[50], frames[10], time[10];
    int n, f, i, j;
    int pageFaults = 0;
    int counter = 0;
    int found, pos, min;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++) {
        frames[i] = -1;
        time[i] = 0;
    }

    printf("\n--- LRU Page Replacement ---\n");

    for(i = 0; i < n; i++) {

        found = 0;

        for(j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                found = 1;
                counter++;
                time[j] = counter;
                break;
            }
        }

        if(found == 0) {

            pos = -1;

            for(j = 0; j < f; j++) {
                if(frames[j] == -1) {
                    pos = j;
                    break;
                }
            }

            if(pos != -1) {
                frames[pos] = pages[i];
                counter++;
                time[pos] = counter;
            }
            else {
                min = 0;

                for(j = 1; j < f; j++) {
                    if(time[j] < time[min]) {
                        min = j;
                    }
                }

                frames[min] = pages[i];
                counter++;
                time[min] = counter;
            }

            pageFaults++;
        }

        printf("Page %d -> [", pages[i]);

        for(j = 0; j < f; j++) {
            if(frames[j] != -1)
                printf("%d", frames[j]);
            else
                printf(" ");

            if(j != f - 1)
                printf(" ");
        }

        printf("]\n");
    }

    printf("\nTotal Page Faults (LRU): %d\n", pageFaults);

    return 0;
}