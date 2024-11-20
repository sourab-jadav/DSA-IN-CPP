#include <algorithm>
#include <cstring>
#include <iostream>
#include <stdexcept>
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


int longestSubseq(string s1,string s2,int m,int n){
    if (m==0 or n==0) {
        return 0;
    }
    if (s1[m-1]==s2[n-1]) {
        return 1+longestSubseq(s1, s2, m-1, n-1);
    }else {
        return max(longestSubseq(s1, s2, m-1, n),longestSubseq(s1, s2, m, n-1));
    }
}

// using dynamic programming to solve the problem
int solvedp(string s1,string s2,int m,int n){
    int dp[m+1][n+1];
    // if any one string size is zero then the result is 0
    memset(dp, 0, sizeof dp);
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if (s1[i-1]==s2[j-1]) {
                dp[i][j]=1+dp[i-1][j-1];
            }else {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}
// 
//
// optimizing the space since we are only concerened with 
// i-1,j-1 i-1,j and i,j-1 we need two containers
int solveOptdp(string s1,string s2,int n,int m){
    vector<int>temp(n+1,0);
    vector<int>curr(m+1,0);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if (s1[i-1]==s2[j-1]) {
                curr[j]=1+temp[j-1];
            }else {
                curr[j]=max(curr[j-1],temp[j]);
            }
        }
        temp=curr; // this is nice feature of cpp
    }
    return curr[m];
}
int main() {
    string s1 = "ABC";
    string s2 = "ACD";
    int m=s1.length();
    int n=s2.length();
    // int result=solvedp(s1, s2, m, n);
    // std::cout<<result<<std::endl;
    std::cout<<solveOptdp(s1, s2, n, m)<<std::endl;
    return 0;
}


