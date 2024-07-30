#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// after solving this one solve the knapsack problem

// // why this code is failing
// // for sum=1  => 1 - 1
// // for sum=2  => 1,1 - 2
// // for sum=3  => [ 1,1,1 ] [ 1,2 ] [ 2,1 ] [ 3,0 ] - 4
// // for sum=4  => [ 1,1,1,1 ] [ 1,1,2 ] [ 1,2,1 ] [ 1,3 ]
// //               [ 2,1,1 ] [ 2,2 ] 
// //               [ 3,1 ]  - 7
//
// desired output: - {1, 1, 1, 1}, {1, 1, 2}, {2, 2}, {1, 3} -4
//
//
//
// int solve(vector<int>vec,int sum){
//     if (sum==0) {
//         return 1;
//     }
//     int result=0;
//     for(int i=0;i<vec.size();i++){
//         if (sum-vec[i]>=0) {
//             result+=solve(vec, sum-vec[i]);
//         }
//     }
//     std::cout<<"for sum "<<sum<<" result is "<<result<<std::endl;
//     return result;
// }
//

// this is the right approach
int solve(vector<int>vec,int n,int sum){

    // for each value you either select it or you don't select it

    // if you select it you decrease the sum by that value
    // now at some point the sum becomes zero 
    //      then that recursive path is choosen by returning 1
    // if the n value becomes zero and sum >0 then that path is not feasable 
    //      so we don't include that recursive path and return 0
    if (sum==0) {
        return 1;
    }
    if (sum<0 or n==0) {
        return 0;
    }
    return solve(vec, n, sum-vec[n-1])+solve(vec, n-1, sum);
}
// 
// let's try to implement dynamic progarmming solution
// for sum=0 it's value is 0
int dp(vector<int>vec,int n,int sum){
    int arr[n+1][sum+1];
    memset(arr, 0, sizeof(arr));
    arr[0][0]=1; // when sum is 0 only 1 way is select no coin
                 // here in the above recursive solution 
                 // by including the current element and 
                 // no inluding the current element

    //this approach cannot be possible
    // for(int i=1;i<=sum;i++){
    //     for(int j=0;j<n;j++){
    //         if (i-) {
    //         
    //         }
    //     }
    //
    // }

    for(int idx=1;idx<=n;idx++){
        for(int s=0;s<=sum;s++){
            arr[idx][s]+=arr[idx-1][s];
            if (s-vec[idx-1]>=0) {
                arr[idx][s]+= arr[idx][s-vec[idx-1]];
            }
        }
    }
    return arr[n][sum];
}
int main() {
vector<int>coins = {1,2,3};
// int result=solve(coins, coins.size(),4);
// std::cout<<result<<std::endl;
int result=dp(coins, coins.size(), 5);
std::cout<<result<<std::endl;
    return 0;
}
