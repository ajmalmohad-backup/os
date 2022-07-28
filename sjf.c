#include <stdio.h>

void waiting_time(int bt[],int wt[], int n){
    wt[0]=0;
    for (int i = 1; i < n; i++) wt[i] = wt[i-1] + bt[i-1];
}

void turnaround_time(int bt[],int wt[], int tat[], int n){
    for (int i = 0; i < n; i++) tat[i] = wt[i] + bt[i];
}

void average_time(int bt[],int wt[], int tat[], int n, int sp[]){
    int total_wt=0, total_tat=0;
    waiting_time(bt,wt,n);
    turnaround_time(bt,wt,tat,n);
    printf("Process ID \t Burst Time \t Waiting Time \t Turn Around Time\n");
    for (int i = 0; i < n; i++){
        total_wt += wt[i];
        total_tat += tat[i];
        printf("\t%d\t\t%d\t\t%d\t\t%d\n",sp[i],bt[i],wt[i],tat[i]);
    }
    printf("\n\n Average Waiting Time: %f", (float)total_wt/(float)n);
    printf("\n\n Average Turnaround Time: %f",(float)total_tat/(float)n);
}

void swap(int *x, int *y) { 
    int temp = *x; 
    *x = *y; 
    *y = temp; 
}

int main(){
    int n;
    printf("Enter Number of Processes: ");
    scanf("%d", &n);
    int bt[n],wt[n],tat[n],sbt[n],sp[n];
    for (int i = 0; i < n; i++){
        printf("Enter Burst Time of Process %d: ", i+1);
        scanf("%d", &bt[i]);
        sp[i]=i+1;
    }
    int i, j, min_idx; 
    for (i = 0; i < n-1; i++) { 
        min_idx = i; 
        for (j = i+1; j < n; j++) if (bt[j] < bt[min_idx]) min_idx = j; 
        swap(&bt[min_idx], &bt[i]); 
        swap(&sp[min_idx], &sp[i]); 
    } 
    average_time(bt,wt,tat,n,sp);
}