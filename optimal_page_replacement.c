#include <stdio.h>

int main() {
    int n, totalPages, pageFaults = 0;

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
            int pos = -1;
            for (int j = 0; j < n; j++) {
                if (frames[j] == -1) {
                    pos = j;
                    break;
                }
            }

            if (pos == -1) {
                int farthest = i, index = -1;
                for (int j = 0; j < n; j++) {
                    int k;
                    for (k = i + 1; k < totalPages; k++) {
                        if (frames[j] == pages[k]) break;
                    }
                    if (k == totalPages) {
                        index = j;
                        break;
                    }
                    if (k > farthest) {
                        farthest = k;
                        index = j;
                    }
                }
                pos = (index == -1) ? 0 : index;
            }
            frames[pos] = pages[i];
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
