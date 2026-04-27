#include <stdio.h>
#include <stdbool.h>
#include <string.h>
struct Process {
 int pid, at, bt, ct, tat, wt, rt;
 bool inQueue;
};
int main() {
 int n, tq;
 printf("Enter number of processes: ");
 scanf("%d", &n);
 printf("Enter Time Quantum: ");
 scanf("%d", &tq);
 struct Process p[n];
 for (int i = 0; i < n; i++) {
 p[i].pid = i + 1;
 p[i].inQueue = false;
 printf("Enter AT and BT for P%d: ", i + 1);
 scanf("%d %d", &p[i].at, &p[i].bt);
 p[i].rt = p[i].bt;
 }
 int time = 0, completed = 0;
 float totalWT = 0, totalTAT = 0;
 int queue[100], head = 0, tail = 0;

 char ganttLabel[200][10];
 int ganttTime[200], gIdx = 0;
 ganttTime[0] = 0;
 for(int i=0; i<n; i++) {
 if(p[i].at <= time) {
 queue[tail++] = i;
 p[i].inQueue = true;
 }
 }
 while (completed < n) {
 if (head == tail) {
 time++;
 for(int i=0; i<n; i++) {
 if(!p[i].inQueue && p[i].at <= time && p[i].rt > 0) {
 queue[tail++] = i;
 p[i].inQueue = true;
 }
 }
 if (gIdx > 0 && strcmp(ganttLabel[gIdx-1], "IDLE") == 0) {
 ganttTime[gIdx] = time;
 } else {
 strcpy(ganttLabel[gIdx], "IDLE");
 gIdx++;
 ganttTime[gIdx] = time;
 }
 continue;
 }
 int idx = queue[head++];

 int executeTime = (p[idx].rt < tq) ? p[idx].rt : tq;

 sprintf(ganttLabel[gIdx], "P%d", p[idx].pid);
 time += executeTime;
 p[idx].rt -= executeTime;
 gIdx++;
 ganttTime[gIdx] = time;
 for(int i=0; i<n; i++) {
 if(!p[i].inQueue && p[i].at <= time && p[i].rt > 0) {
 queue[tail++] = i;
 p[i].inQueue = true;
 }
 }
 if (p[idx].rt > 0) {
 queue[tail++] = idx;
 } else {
 p[idx].ct = time;
 p[idx].tat = p[idx].ct - p[idx].at;
 p[idx].wt = p[idx].tat - p[idx].bt;
 totalWT += p[idx].wt;
 totalTAT += p[idx].tat;
 completed++;
 }
 }
 printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
 for (int i = 0; i < n; i++) {
 printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
 }
 printf("\nAverage Waiting Time = %.2f\nAverage TAT = %.2f\n", totalWT/n, totalTAT/n);
 printf("\nGantt Chart:\n");
 for (int i = 0; i < gIdx; i++) printf("-------");
 printf("\n");
 for (int i = 0; i < gIdx; i++) printf("| %-4s ", ganttLabel[i]);
 printf("|\n");
 for (int i = 0; i < gIdx; i++) printf("-------");
 printf("\n");
 for (int i = 0; i <= gIdx; i++) printf("%-7d", ganttTime[i]);
 printf("\n");
 return 0;
}
