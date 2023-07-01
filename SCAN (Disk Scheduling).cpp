#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int numRequests, initialHeadPosition;
    cout << "Enter the number of disk I/O requests: ";
    cin >> numRequests;

    cout << "Enter the initial head position: ";
    cin >> initialHeadPosition;

    vector<int> requests(numRequests);

    cout << "Enter the disk request queue:\n";
    for (int i = 0; i < numRequests; i++) {
        cin >> requests[i];
    }

    int totalSeekTime = 0;
    int currentPosition = initialHeadPosition;

    cout << "Scheduled order: ";

    for (int i = 0; i < numRequests; i++) {
        cout << requests[i] << " ";
        totalSeekTime += abs(currentPosition - requests[i]);
        currentPosition = requests[i];
    }

    cout << endl;

    cout << "Total seek time: " << totalSeekTime << endl;
    cout << "Average seek time: " << static_cast<double>(totalSeekTime) / numRequests << endl;

    return 0;
}

