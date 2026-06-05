#include <stdio.h>

int main() {
    int pages[50], frames[10];
    int n, f, i, j, k;

    int pageFaults = 0;
    int found, pos, farthest, index;

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
    }

    printf("\n--- Optimal Page Replacement ---\n");

    for(i = 0; i < n; i++) {

        found = 0;

        for(j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                found = 1;
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
            }
            else {

                farthest = -1;
                index = -1;

                for(j = 0; j < f; j++) {

                    int foundFuture = 0;

                    for(k = i + 1; k < n; k++) {
                        if(frames[j] == pages[k]) {

                            if(k > farthest) {
                                farthest = k;
                                index = j;
                            }

                            foundFuture = 1;
                            break;
                        }
                    }

                    if(foundFuture == 0) {
                        index = j;
                        break;
                    }
                }

                frames[index] = pages[i];
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

    printf("\nTotal Page Faults (Optimal): %d\n", pageFaults);

    return 0;
}