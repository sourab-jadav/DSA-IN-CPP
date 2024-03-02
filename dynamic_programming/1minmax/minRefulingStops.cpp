#include <algorithm>
#include <queue>
#include <climits>
#include <iostream>
#include <string>
#include <vector>

// https://leetcode.com/problems/minimum-number-of-refueling-stops/description/

using namespace std;

// Input: target = 100, startFuel = 10, stations =
// [[10,60],[20,30],[30,30],[60,40]] Output: 2 Explanation: We start with 10
// liters of fuel. We drive to position 10, expending 10 liters of fuel.  We
// refuel from 0 liters to 60 liters of gas. Then, we drive from position 10 to
// position 60 (expending 50 liters of fuel), and refuel from 10 liters to 50
// liters of gas.  We then drive to and reach the target. We made 2 refueling
// stops along the way, so we return 2.

// recursion
// class Solution {
//     public:
//         int solve(int target, int startFuel, vector<vector<int>> &stations,
//         int i) {
//             // three things can happen
//             // 1. we reach the target
//             // 2. we run out of fuel
//             // 3. we reach the end of the stations
//             // if we reach the target, we return 0 when startFuel is greater than or equal to target
//             // we will run out of fuel when startFuel is less than target and i is equal to stations.size()
//             // we will subtract the fuel from startFuel only when startFuel is greater than or equal to stations[i][0]
//                 if (startFuel >= target) {
//                 return 0;
//             }
//             if (i == stations.size()) {
//                 return INT_MAX-1;
//             }
//             int ans = INT_MAX-1;
//             if (startFuel >= stations[i][0]) {
//                 ans = min(ans,
//                         1 + solve(target, startFuel + stations[i][1],
//                         stations, i + 1));
//             }
//             ans = min(ans, solve(target, startFuel, stations, i + 1));
//             return ans;
//         }
//
//         int minRefuelStops(int target, int startFuel, vector<vector<int>>
//         &stations) {
//             int result=solve(target, startFuel, stations, 0);
//             if (result==INT_MAX-1) {
//                 return -1;
//             }else {
//                 return  result;
//             }
//         }
// };

// dp solution for the same problem
// memoizating the result of the recursive solution
//

// memoization  //not helpful
// class Solution {
//     public:
//         int solve(int target, int startFuel, vector<vector<int>> &stations,
//         int i,
//                 vector<vector<int>> &dp) {
//             if (startFuel >= target) {
//                 return 0;
//             }
//             if (i == stations.size()) {
//                 return INT_MAX-1;
//             }
//             if (dp[i][startFuel] != -1) {
//                 return dp[i][startFuel];
//             }
//             int ans = INT_MAX-1;
//             if (startFuel >= stations[i][0]) {
//                 ans = min(ans, 1 + solve(target, startFuel + stations[i][1],
//                 stations, i + 1, dp));
//             }
//             ans = min(ans, solve(target, startFuel, stations, i + 1, dp));
//             return dp[i][startFuel] = ans;
//         }
//         int minRefuelStops(int target, int startFuel, vector<vector<int>>
//         &stations) {
//             vector<vector<int>> dp(stations.size(), vector<int>(target + 1,
//             -1)); int result = solve(target, startFuel, stations, 0, dp);
//             return result == INT_MAX-1 ? -1 : result;
//         }
// };

class Solution {
    public:
        int minRefuelStops(int target, int startFuel, vector<vector<int>>
        &stations) {
            int n = stations.size();
            vector<long> dp(n + 1, 0);
            dp[0] = startFuel;
            for (int i = 0; i < n; i++) { // here we are iterating through the stations and for each station, 
                for (int t = i; t >= 0; t--) { // here we are iterating through the 1D array
                    if (dp[t] >= stations[i][0]) { // here we are checking if we have enough fuel to reach the station
                        dp[t + 1] = max(dp[t + 1], dp[t] + stations[i][1]); // here we are updating the maximum fuel we can have at each station
                    }
                }
            }
            for(int i=0;i<n;i++){
                std::cout<<dp[i]<<" "<<std::endl;
            }
            for (int i = 0; i <= n; i++) {
                if (dp[i] >= target) {
                    return i;
                }
            }
            return -1;
        }
};
// in the dp solution, we are using a 1D array to store the maximum fuel we can
// have at each station // this is important because we can't go back to a
// station once we have passed it we are iterating through the stations and for
// each station, we are iterating through the 1D array and updating the maximum
// fuel we can have at each station we are returning the index of the 1D array
// where the maximum fuel is greater than or equal to the target if we don't
// find any such index, we return -1 its time complexity is O(n^2) and space
// complexity is O(n) we can optimize the space complexity to O(n) by using a 1D
// array instead of a 2D array we can also optimize the time complexity to
// O(nlogn) by using a priority queue

// solution using priority queue
// class Solution {
//     public:
//         int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations) {
//             int n = stations.size();
//             priority_queue<int> pq;
//             int i = 0, res;
//             for (res = 0; startFuel < target; res++) {
//                 while (i < n && stations[i][0] <= startFuel)
//                     pq.push(stations[i++][1]);
//                 if (pq.empty())
//                     return -1;
//                 startFuel += pq.top(), pq.pop();
//             }
//             return res;
//         }
// }; //  you have some fuel what is the maximum distance you can reach from here
//      in the priority queue solution, we are using a priority queue to store
//      the maximum fuel we can have at each station we are iterating through
//      the stations and for each station, we are pushing the fuel of the
//      station into the priority queue we are returning the number of times we
//      have refueled the car if we don't find any such index, we return -1 its
//      time complexity is O(nlogn) and space complexity is O(n)

int main() {
    Solution s;
    vector<vector<int>> vec = {{10, 60}, {20, 30}, {30, 30}, {60, 40}};
    cout << s.minRefuelStops(100, 10, vec);
    return 0;
}
