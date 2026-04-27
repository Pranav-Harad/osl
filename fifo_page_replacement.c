#include <stdio.h>

int main() {
    int n, totalPages, pageFaults = 0, front = 0;

    printf("Enter number of frames: ");
    scanf("%d", &n);
    printf("Enter number of pages: ");
    scanf("%d", &totalPages);

    int frames[n], pages[totalPages];
    printf("Enter the reference string: ");
    for (int i = 0; i < totalPages; i++) scanf("%d", &pages[i]);

    for (int i = 0; i < n; i++) frames[i] = -1;

    printf("\nStep\tPage\tFrames\t\tResult\n");
    for (int i = 0; i < totalPages; i++) {
        int hit = 0;
        for (int j = 0; j < n; j++) {
            if (frames[j] == pages[i]) {
                hit = 1;
                break;
            }
        }

        if (!hit) {
            frames[front] = pages[i];
            front = (front + 1) % n;
            pageFaults++;
        }

        printf("%d\t%d\t", i + 1, pages[i]);
        for (int j = 0; j < n; j++) printf("%d ", frames[j]);
        printf("\t%s\n", hit ? "HIT" : "FAULT");
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);
    printf("Fault Ratio: %.2f%%\n", (float)pageFaults / totalPages * 100);
    return 0;
}
