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
    std::cout<<findWinner(n,x,y) <<std::endl;
    return 0;
}



//  function to determine if Player A will win the game
