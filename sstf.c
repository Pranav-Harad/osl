#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int main() {
 int n, head, total_seek_count = 0;
 printf("SSTF DISK SCHEDULING SIMULATION\n");
 printf("-------------------------------\n");
 printf("Enter the number of disk requests: ");
 scanf("%d", &n);
 int queue[n];
 int visited[n];
 printf("Enter the %d requests (track numbers):\n", n);
 for (int i = 0; i < n; i++) {
 printf("Request %d: ", i + 1);
 scanf("%d", &queue[i]);
 visited[i] = 0;
 }
 printf("Enter the initial disk head position: ");
 scanf("%d", &head);
 printf("\nIncoming Request Queue: [ ");
 for (int i = 0; i < n; i++) printf("%d ", queue[i]);
 printf("]\n\n");
 int current_head = head;
 printf("%-10s | %-15s | %-15s | %-15s\n", "Step", "Current Track", "Target Track", "Seek Distance");
 printf("------------------------------------------------------------------\n");
 for (int i = 0; i < n; i++) {
 int min_distance = INT_MAX;
 int index = -1;
 for (int j = 0; j < n; j++) {
 if (!visited[j]) {
 int d = abs(queue[j] - current_head);
 if (d < min_distance) {
 min_distance = d;
 index = j;
 }
 }
 }
 visited[index] = 1;
 int target = queue[index];

 printf("%-10d | %-15d | %-15d | %-15d\n", i + 1, current_head, target, min_distance);

 total_seek_count += min_distance;
 current_head = target;
 }
 float avg_seek_length = (float)total_seek_count / n;
 printf("------------------------------------------------------------------\n");
 printf("Total Seek Distance: %d\n", total_seek_count);
 printf("Average Seek Length: %.2f\n", avg_seek_length);
 return 0;
}
