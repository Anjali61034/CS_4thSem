#include <iostream>

using namespace std;

void findWaitingTime(int processes[], int n, int bt[], int wt[]) {
    wt[0] = 0;
    for (int i = 1; i < n; i++) {
        wt[i] = bt[i - 1] + wt[i - 1];
    }
}

void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }
}

void findAvgTime(int processes[], int n, int bt[]) {
    int wt[n], tat[n];
    float total_wt = 0, total_tat = 0;

    findWaitingTime(processes, n, bt, wt);
    findTurnAroundTime(processes, n, bt, wt, tat);
    
    cout << "Processes  Burst time  Waiting time  Turnaround time\n";
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        cout << " " << processes[i] << "\t\t" << bt[i] << "\t    " << wt[i] << "\t\t    " << tat[i] << endl;
    }

    // Print average waiting time and turnaround time
    cout << "\nAverage Waiting Time = " << (total_wt / n) << endl;
    cout << "Average Turnaround Time = " << (total_tat / n) << endl;
}

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;
    int processes[n], bt[n];
    
    for (int i = 0; i < n; i++) {
        processes[i] = i + 1;
        cout << "Enter burst time for process " << processes[i] << ": ";
        cin >> bt[i];
    }
    
    findAvgTime(processes, n, bt);
    return 0;
}
