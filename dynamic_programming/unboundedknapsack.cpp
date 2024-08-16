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

// 
// dynamic_programming/1minmax/4coinchange.cpp
int unboundedKnapsack(int weight,int wt[],int val[],int n){
    if (weight==0 or n==0) {
        return 0;
    }
    int take=0;
    if (weight-wt[n-1]>=0) {
        take=val[n-1]+unboundedKnapsack(weight-wt[n-1], wt, val, n);
    }
    int notake=unboundedKnapsack(weight, wt, val, n-1);

    return max(take,notake);
}


int main() {
    int W = 100;
    int val[] = { 10, 30, 20 };
    int wt[] = { 5, 10, 15 };
    int n = sizeof(val) / sizeof(val[0]);
    cout << unboundedKnapsack(W, wt, val, n - 1);
    return 0;
    return 0;
}


