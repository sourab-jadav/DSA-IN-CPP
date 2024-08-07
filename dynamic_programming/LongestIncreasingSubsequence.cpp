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




int solveRecursive(int arr[],int n,int i,int prev){
    if (i==n) {
        return 0;
    }
    int include=0;
    if (arr[i]>prev) {
       include=1+solveRecursive(arr, n, i+1, arr[i]);
    }
    int exclude=solveRecursive(arr, n, i+1, prev);
    return max(include,exclude);
}
// tabulation solution
int solveDP(int arr[],int n){
    int dp[n];
     // the idea here to 
     // get lis ending with the given element
    memset(dp, 0, sizeof dp);
    dp[0]=1;
    // finding the element smaller than the current value on the 
    // left side
    int result=0;
    for(int i=1;i<n;i++){
        int j;
        bool flag=false;
        for(j=i-1;j>=0;j--){
            if (arr[j]<=arr[i]) {
                flag=true;
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        if (!flag) {
            dp[i]=1;
        }
        result=max(result,dp[i]);
    }
    return result;
}


int main() {
    // int arr[]{3,10,2,1,20};
    int arr[]{0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15};
    // int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int n=sizeof(arr)/sizeof(arr[0]);
    // int result=solveRecursive(arr, n, 0, INT_MIN);
    // std::cout<<result<<std::endl;
    std::cout<<solveDP(arr, n)<<std::endl;
    return 0;
}
