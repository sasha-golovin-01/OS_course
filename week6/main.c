#include <stdio.h>

void findWaitingTime(int processes[], int n, int bt[], int wt[], int at[]) {
    int service_time[n];
    service_time[0] = at[0];
    wt[0] = 0;

    for (int i = 1; i < n ; i++) {
        service_time[i] = service_time[i-1] + bt[i-1];

        wt[i] = service_time[i] - at[i];

        if (wt[i] < 0)
            wt[i] = 0;
    }
}
void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n ; i++)
        tat[i] = bt[i] + wt[i];
}

void findavgTime(int processes[], int n, int bt[], int at[]) {
    int wt[n], tat[n];

    findWaitingTime(processes, n, bt, wt, at);

    findTurnAroundTime(processes, n, bt, wt, tat);

    printf("P#\tAT\tBT\tCT\tTAT\tWT\n\n");
    int total_wt = 0, total_tat = 0;

    for (int i = 0; i < n; i++) {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        int compl_time = tat[i] + at[i];
        printf("P%d\t",(i+1));
        printf("%d\t", at[i] );
        printf("%d\t", bt[i] );
        printf("%d\t", compl_time );
        printf("%d\t", tat[i] );
        printf("%d\n", wt[i] );
    }

    float s=(float)total_wt / (float)n;
    float t=(float)total_tat / (float)n;
    printf("\nAverage Turnaround Time = %f\n",t);
    printf("Average WT = %f\n",s);
    printf("\n");

}

int main()
{
    int processes[] = {1, 2, 3, 4};
    int n = sizeof processes / sizeof processes[0];

    int burst_time[] = {2, 4, 5, 1};
    
    int arrival_time[] = {1, 4, 6, 7};

    findavgTime(processes, n, burst_time, arrival_time);

    return 0;
}