#include <iostream>
#include <queue>

using namespace std;

struct Process {
    int id;
    int burstTime;
};

void roundRobinScheduling(Process processes[], int n, int timeQuantum) {
    queue<Process> readyQueue;
    int currentTime = 0;

    for (int i = 0; i < n; i++) {
        readyQueue.push(processes[i]);
    }

    while (!readyQueue.empty()) {
        Process currentProcess = readyQueue.front();
        readyQueue.pop();

        // Process execution
        if (currentProcess.burstTime <= timeQuantum) {
            currentTime += currentProcess.burstTime;
            cout << "Process " << currentProcess.id << " executed for " << currentProcess.burstTime << " units." << endl;
        } else {
            currentTime += timeQuantum;
            cout << "Process " << currentProcess.id << " executed for " << timeQuantum << " units." << endl;

            // Update remaining burst time
            currentProcess.burstTime -= timeQuantum;

            // Add the process back to the queue
            readyQueue.push(currentProcess);
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    Process processes[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter burst time for Process " << i + 1 << ": ";
        cin >> processes[i].burstTime;
        processes[i].id = i + 1;
    }

    int timeQuantum;
    cout << "Enter the time quantum: ";
    cin >> timeQuantum;

    cout << "Executing processes using Round Robin Scheduling..." << endl;
    roundRobinScheduling(processes, n, timeQuantum);

    return 0;
}

