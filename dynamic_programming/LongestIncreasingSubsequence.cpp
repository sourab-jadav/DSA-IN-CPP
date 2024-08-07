#include <algorithm>
#include <climits>
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
int solveRecursive(int arr[],int n,int i,int prev){
    if (i==n) {
        return 0;
    }
    int include=0;
    if (arr[i]>prev) {
       include=1+solveRecursive(arr, n, i+1, arr[i]);
    }
    int exclude=solveRecursive(arr, n, i+1, prev);
    return max(include,exclude);
}
int main() {
    // int arr[]{3,10,2,1,20};
     int arr[]{0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15};
    int n=sizeof(arr)/sizeof(arr[0]);
    int result=solveRecursive(arr, n, 0, INT_MIN);
    std::cout<<result<<std::endl;
    return 0;
}


