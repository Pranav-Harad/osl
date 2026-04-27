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
 int n, head, total_seek_count = 0;
 printf("C-LOOK DISK SCHEDULING SIMULATION\n");
 printf("---------------------------------\n");
 printf("Enter number of requests: ");
 scanf("%d", &n);
 int queue[n];
 printf("Enter the requests:\n");
 for (int i = 0; i < n; i++) {
 scanf("%d", &queue[i]);
 }
 printf("Enter initial head position: ");
 scanf("%d", &head);
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
 if (index > 0) {
 int jump = abs(current_head - queue[0]);
 total_seek_count += jump;
 printf("%-10d | %-15d | %-15d | %-15d (Jump to Start)\n", step++, current_head, queue[0],
jump);
 current_head = queue[0];
 for (int i = 1; i < index; i++) {
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
