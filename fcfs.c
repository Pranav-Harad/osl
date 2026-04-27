#include <stdio.h>
#include <stdlib.h>
int main() {
 int n, head, total_seek_count = 0;
 printf("FCFS DISK SCHEDULING SIMULATION\n");
 printf("-------------------------------\n");
 printf("Enter the number of disk requests: ");
 scanf("%d", &n);
 int queue[n];
 printf("Enter the %d requests (track numbers):\n", n);
 for (int i = 0; i < n; i++) {
 printf("Request %d: ", i + 1);
 scanf("%d", &queue[i]);
 }
 printf("Enter the initial disk head position: ");
 scanf("%d", &head);
 printf("\nIncoming Request Queue: [ ");
 for (int i = 0; i < n; i++) {
 printf("%d ", queue[i]);
 }
 printf("]\n\n");
 int current_head = head;
 printf("%-10s | %-15s | %-15s | %-15s\n", "Step", "Current Track", "Target Track", "Seek Distance");
 printf("------------------------------------------------------------------\n");
 for (int i = 0; i < n; i++) {
 int target = queue[i];
 int distance = abs(target - current_head);

 printf("%-10d | %-15d | %-15d | %-15d\n", i + 1, current_head, target, distance);

 total_seek_count += distance;
 current_head = target;
 }
 float avg_seek_length = (float)total_seek_count / n;
 printf("------------------------------------------------------------------\n");
 printf("Total Seek Distance: %d\n", total_seek_count);
 printf("Average Seek Length: %.2f\n", avg_seek_length);
 return 0;
}
