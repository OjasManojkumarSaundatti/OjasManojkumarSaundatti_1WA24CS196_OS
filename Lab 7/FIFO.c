#include <stdio.h>

int main() {
    int pages[50], frames[10];
    int n, f, i, j;
    int pageFaults = 0;
    int next = 0;
    int found;

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

    printf("\n--- FIFO Page Replacement ---\n");

    for(i = 0; i < n; i++) {

        found = 0;

        for(j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if(found == 0) {
            frames[next] = pages[i];
            next = (next + 1) % f;
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

    printf("\nTotal Page Faults (FIFO): %d\n", pageFaults);

    return 0;
}