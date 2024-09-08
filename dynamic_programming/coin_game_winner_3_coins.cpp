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


bool solve(int x,int y,int n,bool isA){
    if (n<0) {
        return false;
    }
    if (n==1) {
        if (isA) {
            return true;
        }else{
            return false;
        }
    }
    if (n-x==0 or n-y==0) {
        if (isA) {
            return true;
        }else {
            return false;
        }
    }
    bool res1=false;
    bool res2=false;
    bool res3=false;
    if (n-x>0) {
        res1=solve(x, y, n-x, !isA);
    }
    if (n-y>0) {
        res2=solve(x, y, n-y, !isA);
    }
    if (n-x <0 and n-y <0) {
        res3=solve(x, y, n-1, !isA);
    }
    return res1 or res2 or res3;
}
int solveProblem(int x,int y,int n){
    if (n-x<0 and n-y<0) {
        if (solve(x, y, n-1, false)) {
            return 1;
        }else {
            return 0;
        }
    }
    else if (solve(x, y, n-x, false) or solve(x, y, n-y, false)) {
        return 1;
    }else {
        return 0;
    }
}


int main() {
    int n=2;
    int x=3;
    int y=1;
    // given 5 coins every player can pick 1 or 3 or 4 coins on his or her turn 
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
