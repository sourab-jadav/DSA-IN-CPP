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
    if (n==1) {
        if (isA) {
            return true;
        }else {
            return false;
        }
    }
    if (n-x<0 and n-y <0) {
        return solve(x, y, n-1, !isA);
    }else if (n-x==0 or n-y==0) {
        if (isA) {
            return 1;
        }else {
            return 0;
        }
    }else {
        // what if n-y is greater than 0 and n-x <0
        return (n-x>0)?solve(x, y , n-x,!isA):0 or (n-y>0)?solve(x, y, n-y,!isA):0 or solve(x, y, n-1, !isA);
    }
}
int solveProblem(int x,int y,int n){
    // first turn is A's 
    // if n-x is <0 and n-y is <0 then we call for n-1 recursively
    if (n-x<0 and n-y<0) {
        return solve(x, y, n-1, false);
    }else if (n-x==0 or n-y==0) {
        return 1;
    }else {
        // what if n-y is greater than 0 and n-x <0
        return (n-x>0)?solve(x, y , n-x,false):0 or (n-y>0)?solve(x, y, n-y,false):0 or solve(x, y, n-1, false);
    }
}


int main() {
    // int n=2;
    // int x=3;
    // int y=4 ;
    int n=82;
    int x=18;
    int y=40 ;
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
