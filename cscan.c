#include <stdio.h>
#include <stdlib.h>
void sort(int arr[], int n) {
 int temp;
 for (int i = 0; i < n - 1; i++) {
 for (int j = 0; j < n - i - 1; j++) {
 if (arr[j] > arr[j + 1]) {
 temp = arr[j];
 arr[j] = arr[j + 1];
 arr[j + 1] = temp;
 }
 }
 }
}
int main() {
 int n, head, disk_size, total_seek_count = 0;
 printf("C-SCAN (CIRCULAR SCAN) SIMULATION\n");
 printf("----------------------------------\n");
 printf("Enter number of requests: ");
 scanf("%d", &n);
 int queue[n];
 printf("Enter the requests:\n");
 for (int i = 0; i < n; i++) {
 scanf("%d", &queue[i]);
 }
 printf("Enter initial head position: ");
 scanf("%d", &head);
 printf("Enter total disk size (e.g., 200): ");
 scanf("%d", &disk_size);
 sort(queue, n);
 int index = 0;
 while (index < n && head > queue[index]) {
 index++;
 }
 printf("\n%-10s | %-15s | %-15s | %-15s\n", "Step", "Current", "Target", "Distance");
 printf("------------------------------------------------------------------\n");
 int current_head = head;
 int step = 1;
 for (int i = index; i < n; i++) {
 int dist = abs(queue[i] - current_head);
 total_seek_count += dist;
 printf("%-10d | %-15d | %-15d | %-15d\n", step++, current_head, queue[i], dist);
 current_head = queue[i];
 }
 int to_end = (disk_size - 1) - current_head;
 total_seek_count += to_end;
 printf("%-10d | %-15d | %-15d | %-15d (End)\n", step++, current_head, disk_size - 1, to_end);
 current_head = disk_size - 1;
 int jump = (disk_size - 1) - 0;
 total_seek_count += jump;
 printf("%-10d | %-15d | %-15d | %-15d (Jump to 0)\n", step++, current_head, 0, jump);
 current_head = 0;
 for (int i = 0; i < index; i++) {
 int dist = abs(queue[i] - current_head);
 total_seek_count += dist;
 printf("%-10d | %-15d | %-15d | %-15d\n", step++, current_head, queue[i], dist);
 current_head = queue[i];
 }
 printf("------------------------------------------------------------------\n");
 printf("Total Seek Distance: %d\n", total_seek_count);
 printf("Average Seek Length: %.2f\n", (float)total_seek_count / n);
 return 0;
}
