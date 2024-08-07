#include <algorithm>
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

// https://www.geeksforgeeks.org/lcs-longest-common-subsequence-three-strings/
int lcsOf3(string s1,string s2,string s3,int m,int n,int o){
    int dp[m+1][n+1][o+1];
    memset(dp, 0, sizeof(dp));
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=o;k++){
                // if (s1[i-1]==s2[j-1]==s3[k-1]) { // this is wrong 
                if (s1[i-1]==s2[j-1]and s2[j-1]== s3[k-1]) {
                    dp[i][j][k]=1+dp[i-1][j-1][k-1];
                }else {
                    dp[i][j][k]=max(dp[i-1][j][k],max(dp[i][j-1][k],dp[i][j][k-1]));
                }
            }
        }
    }
    return dp[m][n][o];
}
int main()
{
    string X = "AGGT12";
    string Y = "12TXAYB";
    string Z = "12XBA";
 
    int m = X.length();
    int n = Y.length();
    int o = Z.length();
 
    cout << "Length of LcS is " << lcsOf3(X, Y, Z, m, n, o);
 
    return 0;
}
