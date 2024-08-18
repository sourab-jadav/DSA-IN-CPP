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
//
// let's try to solve this more intuitively
int solveRecursive(int arr[],int i,int n,bool less_than,bool greater_than){
    if (i==n-1) {
        return 0;
    }
    int result1=0;
    int result2=0;
    if (less_than) {
        if (arr[i]<arr[i+1]) {
            result1=1+solveRecursive(arr, i+1, n, false, true);
        }else {
            result2=1+solveRecursive(arr, i+1, n, true, false);
        }
    }else if (greater_than) {
        if (arr[i]>arr[i+1]) {
            result1=1+solveRecursive(arr, i+1, n, true, false);
        }else {
            result2=1+solveRecursive(arr, i+1, n, false, true);
        }
    }
    return max(result1,result2);
}

int main() {
    int arr[] = {10, 22, 9, 33, 49, 50, 31, 60};
    int n=sizeof(arr)/sizeof(arr[0]);
    int result=solveRecursive(arr, 0, n, true, false);
    std::cout<<result<<std::endl;
    return 0;
}
