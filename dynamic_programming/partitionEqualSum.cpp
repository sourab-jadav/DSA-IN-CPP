#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
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
using namespace std;
// this function takes total sum of array elements and checks if a partition is possible or not
// bool solve(int arr[],int curr_sum,int target,int n){ // i don't know how to tabulize this recursion
//     if (n<1) return false;
//     if (curr_sum==target) return true;
//     return solve(arr, curr_sum+arr[n-1], target-arr[n-1], n-1) || solve(arr, curr_sum, target, n-1);
// }

// this function takes sum/2 and n array elements
// and checks if a subsequenc is possible with it
bool solveSumby2(int arr[],int n,int sum){
    if (n<1) {
       return false;
    }
    if (sum==0) {
        return true;
    }
    if (sum-arr[n-1]<0) {
        return solveSumby2(arr, n-1, sum);
    }else {
        return solveSumby2(arr, n-1, sum-arr[n-1]) || solveSumby2(arr, n-1, sum);
    }
}




int main() {
int arr[]{2,3,3,3,4,5};
// int arr[]{4,6};
int n=sizeof arr/sizeof arr[0];
int sum=0;
for_each(arr,arr+n,[&sum](int x){
        sum+=x;
        });
// recursive approach for the given sum
// if (sum%2==0) {
//     std::cout<<solveSumby2(arr, n, sum/2)<<std::endl;
// }else {
//     std::cout<<"it is not possible"<<std::endl;
// }



// this approach failed becuase you did not handle
// base cases for n=0 and n=1;
// if (sum%2==0) {
//     int sum=sum/2;
//     // int dp[n+1][sum+1];
//
//   vector<vector<bool>> dp(n+1, vector<bool>(sum + 1, false));
//     // memset(dp, 0, sizeof dp);
//     for(int i=2;i<=n;i++){
//         dp[i][0]=true;
//     }
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=sum;j++){
//             if (j-arr[i-1]<0) {
//                 dp[i][j]=dp[i-1][j];
//             }else {
//                 dp[i][j]=dp[i-1][j-arr[i-1]]or dp[i-1][j];
//             }
//         }
//     }
//     std::cout<<"The result is "<<dp[n][sum]<<std::endl;
// }else {
//     std::cout<<"the solution is not possible"<<std::endl;
// }


// dp version two;
if (sum%2==0) {
    sum=sum/2;
    int dp[n+1][sum+1];
    memset(dp, 0, sizeof(dp));
    // check the base cases when n=0 
    // for all the sum values the result is 0
    for(int i=0;i<=sum;i++){
        dp[0][i]=0;
    }

    // when sum is zero irrespective of the value of zero 
    // the result is 1
    for(int i=1;i<=n;i++){
        dp[i][0]=1;
    }

    // when n value is 1 and if there exist an element which results 
    // in zero on subtraction then for that sum value the result is 1
    for(int s=1;s<=sum;s++){
        for(int i=0;i<n;i++){
            if (s-arr[i]==0) {
                dp[i+1][s]=1;
            }
        }
    }
    // here above instead of initializing for the whole table we can just
    // inititalize first row based on the first element of the array
    if (arr[0]<=sum) {
        dp[1][arr[0]]=1;
    }
    printxyz(dp, n+1, sum+1);
    // now do the recursive implementation
    for(int i=2;i<=n;i++){
        for(int s=1;s<=sum;s++){
            if (s-arr[i-1]<0) {
                dp[i][s]=dp[i-1][s];
            }else{
                dp[i][s]=dp[i-1][s-arr[i-1]] or dp[i-1][s];
            }
        }
    }
    printxyz(dp, n+1, sum+1);
    std::cout<<"the result is "<<dp[n][sum]<<std::endl;

    
}else {
    std::cout<<"not possible"<<std::endl;
}



return 0;
}
