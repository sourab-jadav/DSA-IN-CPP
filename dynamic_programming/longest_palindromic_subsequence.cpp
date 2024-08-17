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

// the naive idea of approaching this problem is construction the 
// path by selecting and not selecting the character from 0 to len-1 
// when you reach the end of the string length see that the string obtained is palindrome 
// if it is a palindrome compare it's length with the max length so far
bool check(string str){
    int low=0;
    int high=str.length()-1;
    while (low<high) {
        if (str[low]!=str[high]) {
            return false;
        }
        low++;
        high--;
    }
    return true;
}
int result=INT_MIN;
void solveLPS(string str,string curr,int i){
    if (i==str.length()) {
        if (check(curr)) {
            result=max(result,(int)curr.length());
            // result=max(result,curr.size()); // this line has error
                                            // here curr.size() returns number of size_t type
        }
        return;
    }
    solveLPS(str, curr+str[i], i+1);
    solveLPS(str, curr, i+1);
}
// another way of solving a problem is maintaining two pointers pointing at start and end 
// if the start and end value matches to i+1 and j-1 +2 
// if j-i+1 is 2 and a[i]=a[j] then return 2 
// if the j-i+1 > 2 and the values are not equal return max((i+1,j),(i,j-1))
int solveLPS_recursive(string str,int i,int j){ // in this solution we are only traversing 
                                                // half of the string length
    if (i<j) {
        if (j-i+1==2) {
            if (str[i]==str[j]) {
                return 2;
            }else {
                return 1;
            }
        }else {
            if (str[i]==str[j]) {
                return 1+solveLPS_recursive(str, i+1, j-1);
            }else {
                return 1+max(solveLPS_recursive(str, i+1, j),solveLPS_recursive(str, i, j-1));
            }
        }
    
    }
    return 0;
}
// we can write the dynamic programming based solution for the above approach
int solvedp(string str){
    int n=str.length();
    int dp[n+1][n+1];
    memset(dp, 0, sizeof dp);
// this just doesn't work here we are talking about 
// subsequence and here we are only comparing i and i-1
// hence this will not produce the correct solution
    // for(int i=1;i<n;i++){ 
    //                       
    //                       
    //     if (str[i]==str[i-1]) {
    //         dp[2][i]=dp[2][i-1]=2;
    //     }
    // }
    // for(int len=3;len<=n;len++){
    //     for(int i=0;i<=n-len;i++){
    //         if (str[i]==str[i+len-1]) {
    //             dp[len][i]=1+dp[len-1][i];
    //         }else {
    //         }
    //     }
    //
    // }
    // what if we take two strings 
    // s1 and s2
    // s1 remains as it is 
    // and reverse the s2 
    //
    // now we have i and j pointing the start and end of the string
    string rev=str;
    reverse(rev.begin(),rev.end());
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if (str[i-1]==rev[j-1]) {
                dp[i][j]=1+dp[i-1][j-1];
            }else {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][n];
}
// further optimizing the solutoin

int solve_opt_dp(string str){
    string rev=str;
    reverse(rev.begin(),rev.end());
    int n=str.length();
    vector<int>curr(n+1,0);
    vector<int>prev(n+1,0);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if (str[i-1]==rev[j-1]) {
                curr[j]=1+prev[j-1];
            }else {
                curr[j]=max(curr[j-1],prev[j]);
            }
        }
        prev=curr;
    }
    return curr[n];
}
int main() {
    // string str="BBABCBCAB";
    string str="banana";
    // solveLPS(str,"",0);
    // std::cout<<result<<std::endl;
    // std::cout<<solveLPS_recursive(str, 0, (int)str.length()-1)<<std::endl;
    // std::cout<<solvedp(str)<<std::endl;
    std::cout<<solve_opt_dp(str)<<std::endl;
    return 0;
}
