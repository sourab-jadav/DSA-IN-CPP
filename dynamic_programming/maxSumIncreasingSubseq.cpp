#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define printxyz(arr, rows, cols)                      \
    do {                                               \
        std::cout<<std::endl;                          \
        for (int i = 0; i < rows; ++i) {               \
            for (int j = 0; j < cols; ++j) {           \
                std::cout << arr[i][j] << " ";         \
            }                                          \
            std::cout << std::endl;                    \
        }                                              \
        std::cout<<std::endl;                          \
    } while (0)
#define printarray(arr, n)                             \
        std::cout<<std::endl;                          \
        for (int i = 0; i < n; ++i) {                  \
            std::cout<<arr[i]<<" ";                    \
        }                                              \
        std::cout<<std::endl;                          \

// prerequisite
// dynamic_programming/LongestIncreasingSubsequence.cpp
int solve(int arr[],int n,int prev_idx,int idx){
    // now the base case when the idx reaches n
    if (idx==n) {
        return 0;
    }
    // don't take 
    int notTake=solve(arr, n, prev_idx, idx+1);
    int take=INT_MIN;
    if (prev_idx==-1 || arr[idx]>arr[prev_idx]) {
        take=arr[idx]+solve(arr, n, idx, idx+1);
    }
    return max(take,notTake);
}

// let's do the dynamic programming solution
int solveDP(int arr[],int n){
    int dp[n];
    memset(dp, 0, sizeof(dp));
    dp[0]=arr[0];

    for(int i=1;i<n;i++){
        dp[i]=arr[i];
        for(int j=i-1;j>=0;j--){
            if (arr[j]<=arr[i] and dp[j]+arr[i]>dp[i]) {
                dp[i]=dp[j]+arr[i];
            }
        }
    }
    int max=0;
    for(int i=0;i<n;i++){
        if (dp[i]>max) {
        max=dp[i];
        }
    }
    return max;
}

int main() {
    int arr[]={1, 101, 2, 3, 100, 4, 5};
    int n=sizeof arr/sizeof arr[0];
    std::cout<<solve(arr, n, -1, 0)<<std::endl;
    return 0;
}
