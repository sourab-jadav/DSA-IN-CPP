#include <algorithm>
#include <iostream>
// https://leetcode.com/problems/last-stone-weight-ii/description/
// before approaching this problem 
// dynamic_programming/minmax/prereq/closest_sum.cpp  is a good problem to solve
// https://leetcode.com/problems/last-stone-weight-ii/solutions/653550/trying-to-explain-a-bit-logic-behind-trick/ //  solution is nice to have

#include <bits/stdc++.h>
#include <numeric>
#include <vector>

using namespace std;
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        //we have to the stones we need to find the sum
        int sum=accumulate(stones.begin(),stones.end(),0);
        int newSum=sum/2;
        std::cout<<"sum is "<< sum<<std::endl;
        // std::cout<<newSum<<std::endl;
        // with this new sum we need to find the max subarray with this sum
        int n=stones.size();
        int m=sum/2;
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=0;j<=m;j++){
                if (j>=stones[i-1]) {
                    dp[i][j]=max(dp[i-1][j],dp[i-1][j-stones[i-1]]+stones[i-1]);
                }else {
                    dp[i][j]=dp[i-1][j];
                }
            }
            // here dp n,m will have the max subarray sum
            // we need to find the difference between the sum and the max subarray sum
            // the difference will be the answer
        }
        return sum-2*dp[n][m];
    }
};
int main() {
    Solution s;
    vector<int>stones = {2,7,4,1,8,1};
    std::cout<<s.lastStoneWeightII(stones)<<std::endl;
}
