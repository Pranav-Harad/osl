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
 int n, head, disk_size, move, total_seek_count = 0;
 printf("SCAN (ELEVATOR) DISK SCHEDULING\n");
 printf("-------------------------------\n");
 printf("Enter the number of requests: ");
 scanf("%d", &n);
 int queue[n + 1];
 printf("Enter the requests:\n");
 for (int i = 0; i < n; i++) {
 scanf("%d", &queue[i]);
 }
 printf("Enter initial head position: ");
 scanf("%d", &head);
 printf("Enter total disk size (e.g., 200): ");
 scanf("%d", &disk_size);
 printf("Enter head movement direction (1 for High, 0 for Low): ");
 scanf("%d", &move);
 sort(queue, n);
 int index;
 for (int i = 0; i < n; i++) {
 if (head < queue[i]) {
 index = i;
 break;
 }
 }
 printf("\n%-10s | %-15s | %-15s | %-15s\n", "Step", "Current", "Target", "Distance");
 printf("------------------------------------------------------------------\n");
 int current_head = head;
 int step = 1;
 if (move == 1) {
 for (int i = index; i < n; i++) {
 int dist = abs(queue[i] - current_head);
 total_seek_count += dist;
 printf("%-10d | %-15d | %-15d | %-15d\n", step++, current_head, queue[i], dist);
 current_head = queue[i];
 }

 int dist_to_end = abs((disk_size - 1) - current_head);
 total_seek_count += dist_to_end;
 printf("%-10d | %-15d | %-15d | %-15d (Boundary)\n", step++, current_head, disk_size - 1,
dist_to_end);
 current_head = disk_size - 1;
 for (int i = index - 1; i >= 0; i--) {
 int dist = abs(queue[i] - current_head);
 total_seek_count += dist;
 printf("%-10d | %-15d | %-15d | %-15d\n", step++, current_head, queue[i], dist);
 current_head = queue[i];
 }
 }
 else {
 for (int i = index - 1; i >= 0; i--) {
 int dist = abs(queue[i] - current_head);
 total_seek_count += dist;
 printf("%-10d | %-15d | %-15d | %-15d\n", step++, current_head, queue[i], dist);
 current_head = queue[i];
 }

 int dist_to_start = abs(current_head - 0);
 total_seek_count += dist_to_start;
 printf("%-10d | %-15d | %-15d | %-15d (Boundary)\n", step++, current_head, 0, dist_to_start);
 current_head = 0;
 for (int i = index; i < n; i++) {
 int dist = abs(queue[i] - current_head);
 total_seek_count += dist;
 printf("%-10d | %-15d | %-15d | %-15d\n", step++, current_head, queue[i], dist);
 current_head = queue[i];
 }
 }
 printf("------------------------------------------------------------------\n");
 printf("Total Seek Distance: %d\n", total_seek_count);
 printf("Average Seek Length: %.2f\n", (float)total_seek_count / n);
 return 0;
}
