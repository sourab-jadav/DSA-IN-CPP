#include <cstring>
#include <iostream>
#include <vector>
#include <string>
    // ncr + ncr-1 = n+1cr
    // or
    // we will use property : ncr=n-1cr-1+(n-1)cr;
    // 
    //
using namespace std;
// let's come to the fundamentals 
// what are the ways of selecting the combinations
// we are allowed to select at most r items out of n items
// for a particular item we can select it or neglect it
// 
// when r = 0 you reached the result so you return 1
//  r > n return 0;
int solvencr(int n,int r){ // [ own ]
    if (r>n) {
        return 0;
    }
    if (r==0 ) { 
        return 1;
    }
    return solvencr(n-1, r-1)+solvencr(n-1, r);
}
// using dynamic programming to optimize it

int solvedp(int n,int r){ // [ own ]
    int dp[n+1][r+1];
    memset(dp, 0, sizeof(dp));
    for(int i=0;i<n+1;i++){
        dp[i][0]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=r;j++){
            dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
        }
    }
    return dp[n][r];
}


// further optimizing it using only one array
int solveoptdp(int n,int r){ // this worked surprisingly // [ own ]
    int dp[r+1];
    memset(dp, 0, sizeof(dp));
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=r;j>0;j--){
            dp[j]=dp[j]+dp[j-1];
        }
    }
    return dp[r];
} // here i followed the same approach as i first did in coin change,knapsack problem
  //


int main() {
    std::cout<<solveoptdp(5, 3)<<std::endl;
    return 0;
}


