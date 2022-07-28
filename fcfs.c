#include <stdio.h>

// WT(n) = WT(n-1) + BT(n-1)
// TAT(n) = WT(n) + BT(n)
// Average WT = Total WT / n
// Average TAT = Total TAT / n
void waiting_time(int bt[],int wt[], int n){
    wt[0]=0;
    for (int i = 1; i < n; i++) wt[i] = wt[i-1] + bt[i-1];
}

void turnaround_time(int bt[],int wt[], int tat[], int n){
    for (int i = 0; i < n; i++) tat[i] = wt[i] + bt[i];
}

void average_time(int bt[],int wt[], int tat[], int n){
    int total_wt=0, total_tat=0;
    waiting_time(bt,wt,n);
    turnaround_time(bt,wt,tat,n);
    printf("Process ID \t Burst Time \t Waiting Time \t Turn Around Time\n");
    for (int i = 0; i < n; i++){
        total_wt += wt[i];
        total_tat += tat[i];
        printf("\t%d\t\t%d\t\t%d\t\t%d\n",i+1,bt[i],wt[i],tat[i]);
    }
    printf("\n\n Average Waiting Time: %f", (float)total_wt/(float)n);
    printf("\n\n Average Turnaround Time: %f",(float)total_tat/(float)n);
}

int main(){
    int n;
    printf("Enter Number of Processes: ");
    scanf("%d", &n);
    int bt[n],wt[n],tat[n];
    for (int i = 0; i < n; i++){
        printf("Enter Burst Time of Process %d: ", i+1);
        scanf("%d", &bt[i]);
    }
    average_time(bt,wt,tat,n);
}