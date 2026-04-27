#include <stdio.h>
#include <stdbool.h>
#include <string.h>
struct Process {
 int pid, at, bt, priority, ct, tat, wt;
 bool done;
};
int main() {
 int n;
 printf("Enter number of processes: ");
 scanf("%d", &n);
 struct Process p[n];
 for (int i = 0; i < n; i++) {
 p[i].pid = i + 1;
 p[i].done = false;
 printf("Enter AT, BT and Priority for P%d: ", i + 1);
 scanf("%d %d %d", &p[i].at, &p[i].bt, &p[i].priority);
 }
 int time = 0, completed = 0;
 float totalWT = 0, totalTAT = 0;
 char ganttLabel[100][10];
 int ganttTime[100], gIdx = 0;
 ganttTime[0] = 0;
 while (completed < n) {
 int idx = -1;
 int minPriority = 1e9;
 for (int i = 0; i < n; i++) {
 if (!p[i].done && p[i].at <= time && p[i].priority < minPriority) {
 minPriority = p[i].priority;
 idx = i;
 }
 }
 if (idx == -1) {
 if (gIdx > 0 && strcmp(ganttLabel[gIdx - 1], "IDLE") == 0) {
 time++;
 ganttTime[gIdx] = time;
 } else {
 strcpy(ganttLabel[gIdx], "IDLE");
 time++;
 gIdx++;
 ganttTime[gIdx] = time;
 }
 } else {
 sprintf(ganttLabel[gIdx], "P%d", p[idx].pid);
 time += p[idx].bt;

 p[idx].ct = time;
 p[idx].tat = p[idx].ct - p[idx].at;
 p[idx].wt = p[idx].tat - p[idx].bt;
 totalWT += p[idx].wt;
 totalTAT += p[idx].tat;
 p[idx].done = true;
 completed++;
 gIdx++;
 ganttTime[gIdx] = time;
 }
 }
 printf("\nPID\tAT\tBT\tPri\tCT\tTAT\tWT\n");
 for (int i = 0; i < n; i++) {
 printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
 p[i].pid, p[i].at, p[i].bt, p[i].priority, p[i].ct, p[i].tat, p[i].wt);
 }
 printf("\nAverage Waiting Time = %.2f", totalWT / n);
 printf("\nAverage Turnaround Time = %.2f\n", totalTAT / n);
 printf("\nGantt Chart:\n");
 for (int i = 0; i < gIdx; i++) printf("-------");
 printf("\n");
 for (int i = 0; i < gIdx; i++) {
 printf("| %-4s ", ganttLabel[i]);
 }
 printf("|\n");
 for (int i = 0; i < gIdx; i++) printf("-------");
 printf("\n");
 for (int i = 0; i <= gIdx; i++) {
 printf("%-7d", ganttTime[i]);
 }
 printf("\n");
 return 0;
}
