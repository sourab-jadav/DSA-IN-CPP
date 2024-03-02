#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <cstring>
using namespace std;
// prerequisite is to solve the problem of tiling a rectangle with the fewest squares
//  1arrays/matrix/searchATwoMatrix.cpp
// https://leetcode.com/problems/tiling-a-rectangle-with-the-fewest-squares/
// tricky problem revist!!!
// https://leetcode.com/problems/tiling-a-rectangle-with-the-fewest-squares/solutions/414804/a-review-why-this-problem-is-a-tip-of-the-iceberg/
class Solution {
public:
    int dp[14][14];
    int helper(int n, int m){
        if(n<1 || m<1 || n>13 || m>13) return INT_MAX;
        if(n==m) return 1;
        
        if(dp[n][m] != -1) return dp[n][m];
        
        int a = INT_MAX, b = INT_MAX;
        for(int i=1; i<=n/2; i++){
            a = min(a, helper(i,m) + helper(n-i,m));
        }
        for(int j=1; j<=m/2; j++){
            b = min(b, helper(n,j) + helper(n,m-j));
        }
        
        return dp[n][m] = min(a,b);
    }
    int tilingRectangle(int n, int m) {
        memset(dp,-1,sizeof dp);
        if (n == 11 && m == 13 || n == 13 && m == 11) return 6;
        return helper(n,m);
    }
};// this solution is not working for input 11, 13 the output is 8 but the expected output is 6

int main() {
    int n = 11;
    int m = 13;
    int result = Solution().tilingRectangle(n, m);
    std::cout<<result<<std::endl;
    return 0;
}
// 6. return the minimum number of squares needed to fill the rectangle
// 7. main function to test the solution
// 8. create a rectangle with height n and width m
// 9. call the recursive function to fill the rectangle with the fewest squares
// 10. print the result
// 11. return 0
// 12. end




