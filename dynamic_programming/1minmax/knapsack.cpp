#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
// recusrive approach
int knapSack(int profit[],int weight[],int W,int n){ // [ own ]
    if (n==0 || W==0) {
        return 0;
    }
    if (weight[n-1]>W) {
        return knapSack(profit, weight, W, n);
    }
    else {
        return max(profit[n-1]+knapSack(profit, weight, W-weight[n-1], n-1),knapSack(profit, weight, W, n-1));
    }
}
// here we are playing with weight value 
// same as we played with sum value in the coinchange problem

// int knapsackmemo(int profit[],int weight[],int memo[][],int W,int n){ // here size needs to be specified if
//                                                                       // here you are using multi dimensional
//                                                                       array
int knapsackmemo(int profit[],int weight[],int **memo,int W,int n){ // [ own ]
    // you forgot to write the base case
    if (n==0) {
        return 0;
    }
    if (memo[n][W]!=-1) {
        return memo[n][W];
    }
    if (W<weight[n-1]) {
        return memo[n][W]=knapsackmemo(profit, weight, memo, W, n-1);
    }else{
        return memo[n][W]=max(profit[n-1]+knapsackmemo(profit, weight, memo, W-weight[n-1], n-1),knapsackmemo(profit, weight, memo, W, n-1));
    }
}

    // memoization for the problem
    // int** memo; // allocating the memory dynamically
    // 
    // // int* temp=new int[5]; // here temp is a pointer that is pointing to first block 
    // //                       // index 
    //
    // memo=new int*[n+1]; // n rows are created
    // if (!memo) {
    //     std::cout<<"rows creation failed"<<std::endl;
    //     return 1;
    // }
    // for(int i=0;i<n+1;i++){
    //     memo[i]=new int[W+1];
    //     if (!memo[i]) {
    //         std::cout<<"column creation failed"<<std::endl;
    //         return 1;
    //     }
    //     // memset(memo[i], -1, sizeof(*memo[i])); // this is wrong
    //     memset(memo[i], -1, (W+1)*sizeof(int));
    // }
    // std::cout<<knapsackmemo(profit,weight,memo,W,n)<<std::endl;

// // dynamic programming solution for the above problem
// int dpknapsack(int profit[],int weight[],int W,int n){ // [ own ]
//     int dp[n+1][W+1];
//     dp[0][0]=0;
//     memset(dp, 0, sizeof(dp)); // this is important
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=W;j++){
//             if (j<weight[i-1]) {
//                 dp[i][j]=dp[i-1][j];
//             }else {
//                 dp[i][j]=max(profit[i-1]+dp[i-1][j-weight[i-1]],dp[i-1][W]);
//             }
//         }
//     }
//     return dp[n][W];
// }
// // since we are only considering 
//
// int main() {
//     int profit[] = { 60, 100, 120 };
//     int weight[] = { 10, 20, 30 };
//     int W = 50;
//     int n = sizeof(profit) / sizeof(profit[0]);
//     std::cout<<dpknapsack(profit, weight, W, n)<<std::endl;
//     return 0;
// }




// now there are three major areas we have to look at inorder to optimize the 
// 
// 1 optimizing space 
// - we can maintain two arrays of size W+1 prev and current 
// - initially prev has all the zeroes we calculate the current array 
//   and push the value into the prev for the next index
// 
// - or we can use only one array initially has all 0's 
// - and for a given i we want dp[i-1][j-weight[i-1]] // which is present on the left side
//
//


// https://www.notion.so/knapsack-68bae09d9f1848ddb12bba044b3765ee?pvs=4#3d171f8079a340e49d14a2cc9d279f69
int knapSackdpOptimized(int W, int weight[], int profit[], int n) {
    int dp[W+1];
    memset(dp, 0, sizeof(dp));
    for(int i=1;i<=n;i++){
        for(int j=W;j>0;j--){
            if (j>=weight[i-1]) {
                dp[j]=max(dp[j],profit[i-1]+dp[j-weight[i-1]]);
            }
        }
    }
    return dp[W];
}
// Driver code
int main()
{
    int profit[] = { 60, 100, 120 };
    int weight[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(profit) / sizeof(profit[0]);
    cout << knapSackdpOptimized(W, weight, profit, n);
    return 0;
}
