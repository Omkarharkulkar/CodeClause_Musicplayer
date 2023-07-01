#include <iostream>
#include <vector>
#include <algorithm>

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

    sort(requests.begin(), requests.end());

    int startPos = initialHeadPosition;
    int endPos = requests.back();
    int currentIndex = 0;
    int totalSeekTime = 0;

    cout << "Scheduled order: ";

    while (requests[currentIndex] < startPos) {
        currentIndex++;
    }

    // Traverse from current position to the end
    while (currentIndex < numRequests) {
        cout << requests[currentIndex] << " ";
        totalSeekTime += abs(startPos - requests[currentIndex]);
        startPos = requests[currentIndex];
        currentIndex++;
    }

    // Traverse from the beginning to the last request before the starting position
    currentIndex = 0;
    while (requests[currentIndex] < endPos) {
        cout << requests[currentIndex] << " ";
        totalSeekTime += abs(startPos - requests[currentIndex]);
        startPos = requests[currentIndex];
        currentIndex++;
    }

    cout << endl;

    cout << "Total seek time: " << totalSeekTime << endl;
    cout << "Average seek time: " << static_cast<double>(totalSeekTime) / numRequests << endl;

    return 0;
}

