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
// recursive solution for the problem
// function signature should take 
// value that include:
// station time a 
// crossing time t 
// number of stations 
// current position i,j 
// ending time of each line x1,x2
int recursive_soln(vector<vector<int>>a,vector<vector<int>>t,int n,int i,int j,int x1,int x2){
     // base case is when we reach the ending station 
     if (j==n-1) {
        if (i==0) {
            return x1;
        }else {
            return x2;
        }
     }
    // now from the given i,j we consumed the time taken at station i,j
    // we have two options here 
    // we move forward that i,j+1
    //      when we move forward 
    // or we move diagonally that is i+1,j+1

    // 
    // here we are adding the value based on next decision we are going to take
     int straight=recursive_soln(a, t, n, i, j+1, x1, x2)+a[i][j+1];
     int diff=recursive_soln(a, t, n, !i, j+1, x1, x2)+a[!i][j+1]+t[i][j+1];
     return min(straight,diff);
}

// let's write dynamic programming solution
int solve_dp(vector<vector<int>>a,vector<vector<int>>t,int e1,int e2,int x1,int x2,int n){

    // we need a two dimensional array of two rows and a[0].size() columns
    int c=a[0].size();
    int dp[2][c];
    memset(dp, 0, sizeof dp);
    // 
    // writing the base case
    dp[0][c-1]=x1;
    dp[1][c-1]=x2;
    for(int i=c-2;i>=0;i--){
        // now for a given i 
        // if we are at 0
        // we can move straight by adding the time of next straight value 
        // or we can move diagonally by adding diagonal time(t) + station time
        int straight,diagonal;
        straight=dp[0][i+1]+a[0][i+1];
        diagonal=dp[1][i+1]+t[0][i+1]+a[1][i+1];
        // std::cout<<"diagonal "<<diagonal<<" straight "<<straight<<std::endl;
        dp[0][i]=min(straight,diagonal);
        // std::cout<<"dp[0][i] "<<dp[0][i]<<std::endl;

        straight=dp[1][i+1]+a[1][i+1];
        diagonal=dp[0][i+1]+t[1][i+1]+a[1][i+1];
        dp[1][i]=min(straight,diagonal);
        // std::cout<<"diagonal "<<diagonal<<" straight "<<straight<<std::endl;
        // std::cout<<"dp[1][i] "<<dp[1][i]<<std::endl;
    }
    return min(dp[0][0]+e1+a[0][0],dp[1][0]+a[1][0]+e2);
}


int main() {
    int n = 4; // number of statin 
               // a[i][j] represents the time taken by a station j on the line i
               //  t[i][j] reprsent time taken by station j-1 to 
               //  to station j on other line 
    vector<vector<int> > a 
        = { { 4, 5, 3, 2 },
            { 2, 10, 1, 4 } }; 
    vector<vector<int> > t 
        = { { 0, 7, 4, 5 },
            { 0, 9, 2, 8 } }; 
    int e1=10;
    int e2=12;
    int x1=18;
    int x2=7;
    int rows=a.size();
    int m=a[0].size();
    // let's start from station 1 and get the value
    // int station1value=recursive_soln(a, t, n, 0, 0, x1, x2)+a[0][0]+e1;
    // int station2value=recursive_soln(a, t, n, 1, 0, x1, x2)+a[1][0]+e2;
    // std::cout<<min(station1value,station2value)<<std::endl;
    int result=solve_dp(a, t, e1, e2, x1, x2, n);
    std::cout<<result<<std::endl;
    return 0;
}
