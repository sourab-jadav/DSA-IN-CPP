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

// the problem is you are given number of floors
// and number of eggs
// say 36 floors starting from floor 1(ground) to floor 36(top) and 2 eggs 
// you have to find min floor no. dropping from which the egg breaks 
// you might think you start with floor 1 and try to drop egg at ith floor if the egg breaks 
// you written that floor value 
//
// but there is constraint on the number of eggs you can use and you have to solve the problem in 
// as minimum checks as possible
//
// say eggs is equal to 2 and floors = 100
// let the total number of checks in the worst case possible are x by checking 
//  xth floor     (if breaks total checks are x here) 1+x-1 else
//  x+x-1th floor (if breaks total checks are x here) 1+1+x-2 else(here +x-1 because we don't want to exceed the checks more than x-1)
//  x+x-1+x-2th floor (if breaks total checks are x here) 1+1+1+x-3  and so on..
//
//
// 
//
// the recursive approach for the problem could be 
// constructing the optimal substructure:
// at a given floor x if the egg breaks:
//  then we only need to check for the floors lower than x (as some floors exist lower than x in which the egg does not break)
//  func(e-1,f-1);
// at a given floor x if the egg does not break
//  then we only need to check for the floors higher than x reducing the problem to 
//  func(e,k-f)
//
// for each floor we take the worst case possiblity from floor 1 to f and get the 
// minimum of all the result values obtained at each floor


// recursive solution
int solve_recur(int f,int e){
    // think about the base case
    // when the f=1 the worst case number of checks is 1 
    // when the f=0 then the worst case number of checks is 0
    //
    // when the number of eggs is 1 then the worst case number of checks is f
    if (f==1 or f==0) return f;
    if (e==1) {
        return f;
    }
    int result=INT_MAX;
    // traverse through all the floors 
    // and for a given floor get it's worst case number of checks i.e max(breaks,doesn't break)
    for(int i=1;i<=f;i++){
        int temp=max(solve_recur(i-1, e-1),solve_recur(f-i, e));
        if (temp<result) {
            result=temp;
        }
    }
    return result+1;
}

int solve_dp(int f,int e){
    int dp[f+1][e+1];
    memset(dp, 0, sizeof(dp));
    // think about the base case 
    // when f is 1 or 0 return f 
    for(int i=1;i<=f;i++){
        dp[i][1]=i;
    }
    for(int i=2;i<=e;i++){
        dp[0][i]=0;
        dp[1][i]=1;
    }
    int result=INT_MAX;
    for(int j=2;j<=e;j++){
        for(int i=2;i<=f;i++){
            dp[i][j]=INT_MAX;
            for(int x=1;x<=i;x++){
                int res=1+max(dp[x-1][j-1],dp[i-x][j]);
                if (res<dp[i][j]) {
                    dp[i][j]=res;
                }
            }
        }
    }
    return dp[f][e];
}
int main() {
    // std::cout<<solve_recur(10, 2)<<std::endl;
    std::cout<<solve_dp(36, 2)<<std::endl;
    return 0;
}
