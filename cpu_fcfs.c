#include <stdio.h>
#include <string.h>

struct Process {
 int pid, at, bt, ct, tat, wt;
};

int main() {
 int n;
 printf("Enter number of processes: ");
 scanf("%d", &n);
 struct Process p[n];
 for (int i = 0; i < n; i++) {
 p[i].pid = i + 1;
 printf("Enter AT and BT for P%d: ", i + 1);
 scanf("%d %d", &p[i].at, &p[i].bt);
 }
 for (int i = 0; i < n - 1; i++) {
 for (int j = 0; j < n - i - 1; j++) {
 if (p[j].at > p[j + 1].at) {
 struct Process temp = p[j];
 p[j] = p[j + 1];
 p[j + 1] = temp;
 }
 }
 }
 int time = 0;
 float totalWT = 0, totalTAT = 0;
 char ganttLabel[100][10];
 int ganttTime[100], gIdx = 0;
 ganttTime[0] = 0;
 for (int i = 0; i < n; i++) {
 if (time < p[i].at) {
 strcpy(ganttLabel[gIdx], "IDLE");
 time = p[i].at;
 gIdx++;
 ganttTime[gIdx] = time;
 }
 sprintf(ganttLabel[gIdx], "P%d", p[i].pid);
 time += p[i].bt;
 p[i].ct = time;
 p[i].tat = p[i].ct - p[i].at;
 p[i].wt = p[i].tat - p[i].bt;
 totalWT += p[i].wt;
 totalTAT += p[i].tat;
 gIdx++;
 ganttTime[gIdx] = time;
 }
 printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
 for (int i = 0; i < n; i++) {
 printf("P%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
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
