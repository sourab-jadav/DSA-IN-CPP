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
// int max_value(int arr[],int start,int end,int n){ // not working 
//     if (start==n || end<0) {
//         return 0;
//     }
//     if (start==end) {
//         return arr[start];
//     }
//
//     if (arr[start]+max_value(arr, start+1, end,n) > max_value(arr, start+1, end,n)) {
//         return arr[start]+max_value(arr, start+1, end,n);
//     }
//
//     if (arr[end]+max_value(arr, start, end-1,n)> max_value(arr, start, end-1,n)) {
//         return arr[end]+max_value(arr, start, end-1,n);
//     }
//     return 0;
// }
long long  max_value(int arr[],int start,int end,int n,bool isA){
    if (start==n || end <0) {
        return 0;
    }
    if (start==end) {
        if (isA) {
            return arr[start];
        }else {
            return 0;
        }
    }
    long long  result1=0;
    long long result2=0;
    long long isA_result=0;
    if (isA) {
            result1=(arr[start]+max_value(arr, start+1, end, n,false));
            result2=arr[end]+max_value(arr, start, end-1, n,false);
            isA_result=max(result1,result2);
    }else {
        if (arr[start]>arr[end]) { // this if else logic is not correct and got failed for some input stl/fileInput.txt
                                   // all though below mentioned tc's passed. here you have not handled the case of B 
                                         // is playing as smartly as A,very well
            return max_value(arr, start+1, end, n, true);
        }else {
            return max_value(arr, start, end-1, n, true);
        }
    }
    return isA_result;
}





int main() {
//     int arr[]{
// 5182,4596,4284,3795,6756,5167,5484,634,9364,137,776,7467,9023,4808,9384,5803,2573,9776,882,3018,7742,8307,7963,4387,9402,2827,5742,5685,4144,3668,8156,4452,9808,4571,1296,2437,6246,8771,8950,8695,8126,9865,9954,5347,3211,3067,5645,7663,6679,2691,2796
// }; // failed
    int arr[]{5,3,7,10};// passed
    // int arr[]{20,30,2,2,2,10};// passed
    // int arr[]{2,2,2,2}; // passed
    int n=sizeof(arr)/sizeof(arr[0]);
    int result=max_value(arr,0,n-1,n,true);
    std::cout<<result<<std::endl;

}
