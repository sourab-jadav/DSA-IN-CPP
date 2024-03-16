#include <iostream>
#include <vector>
#include <string>
// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/
using namespace std;
//explaination
//for the above solution we are using binary search to find the minimum number of days to make m bouquets with k flowers in each bouquet
//first we will check if we can make m bouquets with k flowers in each bouquet
//if we can make m bouquets with k flowers in each bouquet then we will check for the left half of the array
//if we can't make m bouquets with k flowers in each bouquet then we will check for the right half of the array
//we will keep on doing this until we find the minimum number of days to make m bouquets with k flowers in each bouquet
//if we can't make m bouquets with k flowers in each bouquet then we will return -1
//time complexity is O(nlogn)
class Solution { // here the runtime is more due to right is 1e9 we can optimize it by using the max element in the array
public:
    // check if we can make m bouquets with k flowers in each bouquet
    bool canMake(vector<int>& bloomDay, int m, int k, int mid) {
        int n = bloomDay.size();
        int count = 0;
        int flowers = 0;
        for (int i = 0; i < n; i++) {
            if (bloomDay[i] <= mid) {
                flowers++;
                if (flowers == k) {
                    count++;
                    flowers = 0;
                }
            } else {
                flowers = 0;
            }
        }
        return count >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (n < m * k) return -1;
        int left = 1, right = 1e9;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canMake(bloomDay, m, k, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
        
    }
};
int main() {
    Solution s;
    vector<int> bloomDay = {1,10,3,10,2};
    int m = 3;
    int k = 1;
    cout << s.minDays(bloomDay, m, k) << endl;
    return 0;
}
// here we are using binary search to find the minimum number of days to make m bouquets with k flowers in each bouquet



// the error we are facing
//   int minDays(vector<int>& A, int m, int k) {
//         int n = A.size(), left = 1, right = 1e9;
//         if (m * k > n) return -1; // here is here m*k to resolve it do (long)m*(long)k
//         while (left < right) {
//             int mid = (left + right) / 2, flow = 0, bouq = 0;
//             for (int j = 0; j < n; ++j) {
//                 if (A[j] > mid) {
//                     flow = 0;
//                 } else if (++flow >= k) {
//                     bouq++;
//                     flow = 0;
//                 }
//             }
//             if (bouq < m) {
//                 left = mid + 1;
//             } else {
//                 right = mid;
//             }
//         }
//         return left;
//     }
//
//
// //i am getting this error 
// Line 7: Char 15: runtime error: signed integer overflow: 89945 * 32127 cannot be represented in type 'int' (solution.cpp)
// SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior prog_joined.cpp:16:15
