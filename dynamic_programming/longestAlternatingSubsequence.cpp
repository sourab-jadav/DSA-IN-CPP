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
int solveRecursive(int arr[],int i,int prev,int n,bool less_than,bool greater_than){


    int res1=0;
    int res2=0;
    if (prev==-1) {
        return max(1+solveRecursive(arr, i+1, arr[i], n, true, false),1+solveRecursive(arr,i+1,arr[i],n,false,true));
    }else if (less_than) {
        if (arr[i] > prev ) {
            res1=max(1+solveRecursive(arr, i+1, arr[i], n, false,true),solveRecursive(arr, i+1, prev, n, less_than, greater_than));
        }else {
            res2=solveRecursive(arr, i+1, prev, n, less_than, greater_than);
        }
    }
    

}

 


int main() {
    int arr[] = {10, 22, 9, 33, 49, 50, 31, 60};
    int n=sizeof(arr)/sizeof(arr[0]);
    int result;
    std::cout<<result<<std::endl;
    return 0;
}
