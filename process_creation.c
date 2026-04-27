#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]) {
                temp = arr[j]; arr[j] = arr[j + 1]; arr[j + 1] = temp;
            }
}

void selectionSort(int arr[], int n) {
    int i, j, min, temp;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min]) min = j;
        temp = arr[min]; arr[min] = arr[i]; arr[i] = temp;
    }
}

int main() {
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements: ");
    for (i = 0; i < n; i++) scanf("%d", &arr[i]);

    pid_t pid = fork();

    if (pid > 0) {
        printf("\n[PARENT] Sorting now (Bubble)...\n");
        bubbleSort(arr, n);
        printf("[PARENT] Sorted: ");
        for(i=0; i<n; i++) printf("%d ", arr[i]);
        printf("\n");

        printf("[PARENT] Waiting for child to finish...\n");
        wait(NULL);
        printf("[PARENT] Child is done. Exiting.\n");
    } 
    else if (pid == 0) {
        printf("\n[CHILD] Child process started (PID: %d)...\n", getpid());
        printf("[CHILD] Sorting now (Selection)...\n");
        selectionSort(arr, n);
        printf("[CHILD] Sorted: ");
        for(i=0; i<n; i++) printf("%d ", arr[i]);
        printf("\n");
        exit(0);
    }
    return 0;
}
