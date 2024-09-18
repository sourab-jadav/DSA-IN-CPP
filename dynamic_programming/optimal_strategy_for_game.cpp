#include <algorithm>
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
// dynamic_programming/coin_game_winner_3_coins.cpp
// 
// two players 
// coins are arranged in a row 
// a player can pick leftmost or rightmost coin and remove it from the row
// you start the game first.
// determine the max value you can make by selecting the leftmost or rightmost coin first and win the game
// int max_value(int arr[],int start,int end){ // not working
//     // what if there is only one coin
//     if (start==end) {
//         return arr[start];
//     }
//     // what if there is two or more coins
//     // max of max value we can get by selecting the leftmost coin or 
//     // selecting the rightmost coin
//     return max(arr[start]+max_value(arr, start+1, end),arr[end]+max_value(arr, start, end-1)); // doing nothing 
//                                                                                                // just finding the sum of
//                                                                                                // all the elements
//                                                                                                // max(25,25);
// }
int max_value(int arr[],int start,int end,int n){
    if (start==n || end<0) {
        return 0;
    }
    if (start==end) {
        return arr[start];
    }

    if (arr[start]+max_value(arr, start+1, end,n) > max_value(arr, start+1, end,n)) {
        return arr[start]+max_value(arr, start+1, end,n);
    }

    if (arr[end]+max_value(arr, start, end-1,n)> max_value(arr, start, end-1,n)) {
        return arr[end]+max_value(arr, start, end-1,n);
    }
    return 0;

}
int main() {
    int arr[]{5,3,7,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    int result=max_value(arr,0,n-1,n);
    std::cout<<result<<std::endl;

}
