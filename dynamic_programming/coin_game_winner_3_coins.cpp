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


int solve(int x,int y,int n,bool isA){
    if (n==1) {
        if (isA) {
            return true;
        }else {
            return false;
        }
    }
    if (n==0 ) {
        if (isA) {
            return false;
        }else {
            return true;
        }
    }
    if (n-x==0 or n-y==0 ) {
        if (isA) {
            return true;
        }else {
            return false;
        }
    }
    if (n-x==1 or n-y==1) {
        if (isA) {
            return false;
        }else {
            return true;
        }
    }
    return (n-1>=0)?solve(x, y, n-1, !isA):false or (n-x>=0)?solve(x, y, n-x, !isA):false or (n-y>=0)?solve(x, y, n-y, !isA):false;
    // main is you can subtract it from 1 or from x or from y
}
int solveProblem(int x,int y,int n){
    bool result=solve(x, y, n, true);
    if (result) {
        return 1;
    }else {
        return 0;
    }
}


int main() {
    // int n=2;
    // int x=3;
    // int y=4 ;
    // int n=82;
    // int x=18;
    // int y=40 ;
    int n=5;
    int x=3;
    int y=4;
    // int n=9;
    // int x=1;
    // int y=8;
    // given 5 coins every player can pick 1 or 3 or 4 coins on his turn 
    // the game always starts with A 
    // player who is not able to pick any coin loses the game 
    // 
    // if x or y is not subtractable from the n value then the current chance person reduces the n value by 1 
    //
    // in this problem either A can win or else B can win 
    // if a wins cout << a as the winner 
    // else if b wins cout <<b as the result 
    //
    // the problem starts by a reducing the number by x or y 
    //
    // if reducing the n value x gives the result true we declare a as the winner
    // else we declare b as the winner
    std::cout<<solveProblem(x, y, n) <<std::endl;
    return 0;
}
