#include <bits/stdc++.h>
#include <climits>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
// https://leetcode.com/problems/minimum-number-of-refueling-stops/solutions/2452236/c-recursion-memoization-max-heap/ //nice sol
class Solution {
    public:
        // int minRefuelStops(int target, int startFuel, vector<vector<int>>
        // &stations) {
        //     //using priority queue
        //     // if the startFuel is greater than the target then return 0
        //     // if the startFuel is less than the target and the stations are empty
        //     then return -1
        //
        //     if (startFuel >= target) {
        //         return 0;
        //     }
        //     if (stations.empty()) {
        //         return -1;
        //     }
        //     // if the startFuel is less than the target and the stations are not
        //     empty
        //     // then we need to find the max fuel that can be added to the startFuel
        //     // we can use the priority queue to find the max fuel that can be added
        //     to the startFuel priority_queue<int> pq; int n = stations.size(); int i
        //     = 0; int ans = 0; while (startFuel < target) {
        //         while (i < n && stations[i][0] <= startFuel) {
        //             pq.push(stations[i][1]);
        //             i++;
        //         }
        //         if (pq.empty()) {
        //             return -1;
        //         }
        //         startFuel += pq.top();
        //         pq.pop();
        //         ans++;
        //     }
        //     return ans;
        // }
        // using recursive approach
        //
        int solve(vector<vector<int>> &stations, int startFuel, int target, int n, int prev_stop,int i) {
            // think of the base cases possible
            if (i== stations.size()) {
                return INT_MAX-1;
            }

            // we have the fuel if the fuel is not enough we return INT_MAX-1
            if (startFuel<stations[i][0]) {
                return INT_MAX-1;
            }


        }
        int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations) {
            int n = (int)stations.size();
            return solve(stations, startFuel, target, n, 0);
        }
};
int main() {
    int target = 100, startFuel = 10;
    vector<vector<int>> stations = {{10, 60}, {20, 30}, {30, 30}, {60, 40}};
    Solution s;
    cout << s.minRefuelStops(target, startFuel, stations) << endl;
    return 0;
}
