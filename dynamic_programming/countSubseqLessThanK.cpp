#include <cstring>
#include <iostream>
#include <variant>
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

// counting all the subsequences that are possible which are less than or equal to k 
// one brute force idea is traverse all the path by including and not including the elements
// on reaching the end of the each path take all the elements and compute it and check if it less 
// than k if yes then do count++;

// one problem which i faced was for the input 1,2,3,4 
// the output got was 12 but the actual answer was 11 
// later realized that it is considering the the emtpy vector as well
// to solve this added constraint !vec.empty()
void solve(int arr[],int i,int n,vector<int>&vec,int &count,int k){
    if (i==n) {
        int result=1;
        for (auto x : vec) {
            result*=x;
        }
        if (result<k and !vec.empty()) {
            ++count;
        }
        return;
    }
    vec.push_back(arr[i]);
    solve(arr, i+1, n, vec, count, k);
    vec.pop_back();
    solve(arr, i+1, n, vec, count, k); 
}

// standard implementation found online
int solver(int arr[],int n,int i,int k ,int prod){
    // now construct a base case 
    // if we reached the end and the product is < k we return 1
    if (i==n and prod>0 and prod<k) {
        return 1;
    }else if (i>=n or prod >=k) {
        return 0;
    }
    // i think the same funda of including and not including
    return solver(arr, n, i+1, k, prod)+solver(arr, n, i+1, k, prod<0?arr[i]:prod*arr[i]);
}

// we can also traverse from right to left recursively to solve this problem
int solve_r_to_l(int arr[],int n,int k,int prod){
    if (n==0 and prod>0 and prod<k) {
        return 1;
    }else if (n< 1 or prod>k) {
        return 0;
    }
    return solve_r_to_l(arr, n-1, k, prod)+solve_r_to_l(arr, n-1, k, prod==0?arr[n-1]:prod*arr[n-1]);
}


// not working solution
int solve_dp(int arr[],int n,int k){
    int dp[k+1][n+1];
    memset(dp, 0, sizeof dp);
    for(int i=1;i<=k;i++){
        int prod=0;
        for(int j=1;j<=n;j++){
            if (prod==0) {
                if (arr[j-1]<i) {
                    prod=arr[j-1];
                    dp[i][j]=1;
                }else {
                    dp[i][j]=0;
                }
            }else {
                if (prod*arr[j-1]<i) {
                    prod*=arr[j-1];
                    dp[i][j]=1+dp[i][j-1];
                }else {
                    dp[i][j]=dp[i][j-1];
                }
            }
        }
    }
    return dp[k][n];
}
// this above code solve_dp does not work [ wrong thought process ]
// here above you are you are starting from product 0 it doesn't have any which does not have any sub problems to solve 
//
// start solving the problem from prod equal to 1 to prod equal to k 

// working dp solution
int solveDP(int arr[],int k,int n){
    int dp[k+1][n+1];
    memset(dp, 0, sizeof dp);
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=dp[i][j-1];
            if (arr[j-1]<=i && arr[j-1]>0) {
                dp[i][j]+=dp[i/arr[j-1]][j-1]+1;
            }
        }
    }
    return dp[k][n];
}
int main() {
    int arr[]{1,2,3,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    int count=0;
    vector<int>vec;
    // solve(arr, 0, n, vec, count,10);
    // std::cout<<"the result is "<<count<<std::endl;
    // std::cout<<solver(arr, n, 0, 10, -1)<<std::endl;
    // int result=solve_r_to_l(arr, n, 10, 0);
    // std::cout<<result<<std::endl;
    std::cout<<solveDP(arr,10,n)<<std::endl;
    return 0;
}
