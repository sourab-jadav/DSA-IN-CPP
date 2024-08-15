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
    // return min(1+solve(arr, i+1, j, k,n),1+solve(arr, i, j-1, k,n));
    return 1+min(solve(arr, i+1, j, k,n),solve(arr, i, j-1, k,n));
}
// https://www.geeksforgeeks.org/minimum-removals-array-make-max-min-k/
// applying binary search to solve this problem

// binary search based approach
// the idea is you start traversing from left 
// for a given i value you get the equivalent right most j value so that a[j]-a[i]<=k 
// get the minimum possible value of (n-(j-i+1))

int findj(int arr[],int key,int i,int n,int k ){
    int low=i+1;
    int high=n-1;
    int result=-1;
    std::cout<<low <<" "<<high<<std::endl;
    while (low<=high) {
        int mid=low+(high-low)/2;
        if (arr[mid]-key<=k) {
            result=mid;
            low=mid+1;
        }else {
            high=mid-1; // keeping high=mid creates problem for input  int a[] = {10,11,15,16,18}, k = 3 ;
        }
    }
    return result;
}
int removals(int arr[],int n,int k){
    // traverse and for a given i get the equivalent j value
    int result=INT_MAX;
    sort(arr,arr+n);
    for(int i=0;i<n;i++){
        int j=findj(arr, arr[i], i, n, k);
        if (j!=-1) {
            result=min(result,(n-(j-i+1)));
        }
    }
    return result;
}
int main() {
    int a[] = {10,11,15,16,18}, k = 3 ;
    // int a[] = {1, 5, 6, 2, 8}, k=2;
    int n=sizeof a/sizeof a[0];
    int result =solve(a, 0, n-1, k, n);
    std::cout<<result <<std::endl;
    // std::cout<<removals(a, n, k)<<std::endl;
    return 0;
}
