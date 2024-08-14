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

int solve(int arr[],int i,int j,int k,int n){
    if (i==n or j<0) {
        return 0;
    }
    if (arr[j]-arr[i]<=k) {
        return 0;
    }
    return min(1+solve(arr, i+1, j, k,n),1+solve(arr, i, j-1, k,n));
}
// https://www.geeksforgeeks.org/minimum-removals-array-make-max-min-k/
int main() {
    // int a[] = {1, 3, 4, 9, 10, 11, 12, 17, 20}, k = 4 ;
int a[] = {1, 5, 6, 2, 8}, k=2;
    int n=sizeof a/sizeof a[0];
    sort(a,a+n);
    printarray(a, n);
    int result =solve(a, 0, n-1, k, n);
    std::cout<<result <<std::endl;
    return 0;
}
