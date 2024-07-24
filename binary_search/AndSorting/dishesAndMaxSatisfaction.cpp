#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
// not_yet_solved
// Function to find the maximum satisfaction
int maxSatisfaction(vector<int>& sizes, vector<int>& tastes, int M) {
    int n = sizes.size();
    vector<pair<int, int>> dishes(n);

    // Combine sizes and tastes into a vector of pairs
    for (int i = 0; i < n; ++i) {
        dishes[i] = {tastes[i], sizes[i]};
    }

    // Sort dishes based on taste in descending order
    sort(dishes.rbegin(), dishes.rend());

    // Max heap to maintain the largest sizes
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int sizeSum = 0;
    int maxSatisfaction = 0;

    // Iterate through the sorted dishes
    for (int i = 0; i < n; ++i) {
        int taste = dishes[i].first;
        int size = dishes[i].second;

        // Add current size to the heap and size sum
        minHeap.push(size);
        sizeSum += size;

        // If the heap exceeds M, remove the smallest size
        if (minHeap.size() > M) {
            sizeSum -= minHeap.top();
            minHeap.pop();
        }

        // Calculate satisfaction and update the maximum satisfaction
        if (minHeap.size() <= M) {
            maxSatisfaction = max(maxSatisfaction, sizeSum * taste);
        }
    }

    return maxSatisfaction;
}

int main() {
    vector<int> sizes = {10, 7, 8, 11, 1};
    vector<int> tastes = {3, 5, 1, 6, 9};
    int M = 2;

    cout << "Maximum satisfaction: " << maxSatisfaction(sizes, tastes, M) << endl;

    return 0;
}
