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

// this solution works as well 
// the lesson is in the if condition 
// avoid using or operator 
// the function is checking for a path which leads to winning of A
int solve(int x,int y,int n,bool isA){
    if (n==0) {
        if (isA) {
            return false;
        }else {
            return true;
        }
    }
    if (n==1 || n-x==0 || n-y==0) {
        if (isA) {
            return true;
        }else {
            return false;
        }
    }
bool pick1 = false, pickx = false, picky = false;
   if (n-1>=0) {
       pick1=solve(x, y, n-1, !isA);
   } 
   if (n-x>=0) {
       pickx=solve(x, y, n-x, !isA);
   } 
   if (n-y>=0) {
       picky=solve(x, y, n-y, !isA);
   } 
   return pick1 || pickx || picky;
    // main is you can subtract it from 1 or from x or from y
}


// working solution but time limit exceeded
bool findWinner(int n,int x, int y ) {
    // Base cases
    if (n == 0) // If no coins are left, Player A loses
        return false;
    if (n == 1) // If 1 coin is left, Player A wins
        return true;
    // If any move leads to a position where the opponent loses, Player A wins
    if (n - 1 >= 0 && !findWinner(n-1,x, y )) // Picking 1 coin
        return true;
    if (n - x >= 0 && !findWinner(n - x,x, y )) // Picking x coins
        return true;
    if (n - y >= 0 && !findWinner(n - y,x, y)) // Picking y coins
        return true;
    // If no move can force a win, Player A loses
    return false;
}
// 
// dp implementation for the above approach
bool dp(int n,int x,int y){
    bool dp[n+1];
    dp[0]=false; // when no coins are left for a then he loses;
    dp[1]=true; //when one coin is left for a then he wins;
    for(int i=2;i<=n;i++){
        if (i-1>=0 && !dp[i-1]) {
            dp[i]=true;
        }else if (i-x>=0 && !dp[i-x]) {
            dp[i]=true;
        }else if (i-y>=0 && !dp[i-y]) {
            dp[i]=true;
        }else {
            dp[i]=false;
        }
    }
    return dp[n];
}


// bool solve(int x, int y, int n, bool isA) {
//     // Base cases
//     if (n == 0) {
//         // If no coins are left, the current player loses
//         return !isA; // Return true if it's Player B's turn, false otherwise
//     }
//     if (n == 1) {
//         // If 1 coin is left, the current player wins if it's Player A's turn
//         return isA; // Return true if it's Player A's turn, false otherwise
//     }
//
//     // Recursive cases
//     // Check each possible move: picking 1, x, or y coins
//     if (n - 1 >= 0 && !solve(x, y, n - 1, !isA)) 
//         return true;  // If the next player loses, the current player wins
//     if (n - x >= 0 && !solve(x, y, n - x, !isA))
//         return true;  // If the next player loses, the current player wins
//     if (n - y >= 0 && !solve(x, y, n - y, !isA))
//         return true;  // If the next player loses, the current player wins
//
//     // If none of the moves lead to a win, the current player loses
//     return false;
// }



int main() {
    int n=2;
    int x=3;
    int y=4 ;
    // int n=82;
    // int x=18;
    // int y=40 ;
    // int n=5;
    // int x=3;
    // int y=4;
    // int n=9;
    // int x=1;
    // int y=8;
    // std::cout<<findWinner(n,x,y) <<std::endl;

    if (solve(x, y, n, true)) {
        std::cout<<1<<std::endl;
    }else {
        std::cout<<0<<std::endl;
    }
    return 0;
}
