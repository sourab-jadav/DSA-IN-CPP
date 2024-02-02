#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
// we recurse the shit
int findShortest(std::vector<std::vector<int>>&vec,int k,int j){
    if (k<(int)vec.size()) {
        int n=(int)vec[k].size();
        for(int i=j;i<n;i++){
            return std::min(vec[k][i]+findShortest(vec, k+1, j),vec[k][i]+findShortest(vec, k+1, j+1)); // need for refactoring
        }
    }
    return 0;
}
// my approach 
// class Solution {
// public:
//     int solve(vector<vector<int>>&traingle,int k,int i){
//         if (k<traingle.size()) {
//             return traingle[k][i]+min(solve(traingle, k+1, i),solve(traingle, k+1, i+1));
//         }
//         return 0;
//     }
//     void minimumTotal(vector<vector<int>>& triangle) {
//         int result={};
//         result=solve(triangle,0,0);
//         std::cout<<result<<std::endl;
//     }
// };

// we memoize the shit
// we memoize the shit
// int findShortest(std::vector<std::vector<int>>&vec,int k,int j,std::vector<std::vector<int>>memo){
//     if (k<(int)vec.size()) {
//         if(memo[k][j]!=-1){
//             return memo[k][j];
//         }
//         int n=(int)vec[k].size();
//         for(int i=j;i<n;i++){
//             return memo[k][j]=std::min(vec[k][i]+findShortest(vec, k+1, j,memo),vec[k][i]+findShortest(vec, k+1, j+1,memo)); // need for refactoring
//         }
//     }
//     return 0;
// }


// we will tabulize the shit
// void findShortest(std::vector<std::vector<int>>&vec){
//     int n=vec.size();
//     //think about the base case
//     std::vector<std::vector<int>>dp(n,std::vector<int>(n,-1));
//     // if the triangle is of length 1 then for that k+1 j that value is the solution
//     for(int i=0;i<vec[n-1].size();i++){
//         dp[n-1][i]=vec[n-1][i];
//     }
//     // now you have the basecase done think about the problem in a recursive way
//     // traversing from last second row as we have the base case ready
//     for(int j=n-2;j>=0;j--){
//         for(int k=0;k<(int)vec[j].size();k++){
//             dp[j][k]=std::min(vec[j][k]+dp[j+1][k],vec[j][k]+dp[j+1][k+1]);
//         }
//     }
//     std::cout<<"solution to the problem is "<<dp[0][0]<<std::endl;
// }

int main() {
    std::vector<std::vector<int>>vec{{2},{3,4},{6,5,7},{4,1,8,3}};
    // std::vector<std::vector<int>>vec{{-1},{2,3},{1,-1,-3}};
    std::vector<std::vector<int>>memo(vec.size(),std::vector<int>(vec.size(),-1));
    // findShortest(vec, 0,0,memo);
    std::cout<<findShortest(vec, 0, 0)<<std::endl;
}
