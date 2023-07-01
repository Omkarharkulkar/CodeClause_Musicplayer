#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int findClosestRequest(const vector<int>& requests, int currentPosition) {
    int closestRequest = -1;
    int minDistance = INT_MAX;

    for (int i = 0; i < requests.size(); i++) {
        int distance = abs(requests[i] - currentPosition);
        if (distance < minDistance) {
            minDistance = distance;
            closestRequest = requests[i];
        }
    }

    return closestRequest;
}

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

    vector<int> sortedRequests = requests; // Create a copy for sorting
    sort(sortedRequests.begin(), sortedRequests.end());

    vector<int> scheduledOrder;
    int currentPosition = initialHeadPosition;

    while (!sortedRequests.empty()) {
        int closestRequest = findClosestRequest(sortedRequests, currentPosition);
        scheduledOrder.push_back(closestRequest);

        // Update current position and remove the processed request
        currentPosition = closestRequest;
        sortedRequests.erase(find(sortedRequests.begin(), sortedRequests.end(), closestRequest));
    }

    // Calculate the total seek time
    int totalSeekTime = abs(initialHeadPosition - scheduledOrder[0]);
    for (int i = 1; i < numRequests; i++) {
        totalSeekTime += abs(scheduledOrder[i] - scheduledOrder[i - 1]);
    }

    cout << "Scheduled order: ";
    for (int i = 0; i < numRequests; i++) {
        cout << scheduledOrder[i] << " ";
    }
    cout << endl;

    cout << "Total seek time: " << totalSeekTime << endl;
    cout << "Average seek time: " << static_cast<double>(totalSeekTime) / numRequests << endl;

    return 0;
}

