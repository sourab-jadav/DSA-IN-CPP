#include <algorithm>
#include <climits>
#include <cstring>
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

// taken from internet
// int lasEndingHere(vector<int>& arr, int i, bool isPositive) {
//     if (i == 0) return 1;
//     int maxLength = 1;
//     for (int j = 0; j < i; j++) {
//         if (isPositive && arr[j] < arr[i]) {
//             maxLength = max(maxLength, 1 + lasEndingHere(arr, j, !isPositive));
//         } else if (!isPositive && arr[j] > arr[i]) {
//             maxLength = max(maxLength, 1 + lasEndingHere(arr, j, !isPositive));
//         }
//     }
//
//     return maxLength;
// }
//
// int longestAlternatingSubsequence(vector<int>& arr) {
//     int maxLength = 1;
//     for (int i = 0; i < arr.size(); i++) {
//         maxLength = max(maxLength, lasEndingHere(arr, i, true));
//         maxLength = max(maxLength, lasEndingHere(arr, i, false));
//     }
//     return maxLength;
// }
//

int longestAlternatingSubsequence(vector<int>arr){
    int n=arr.size();
    std::cout<<"dynamic programming based solution to the problem"<<std::endl;
    int las[n][2];
    memset(las, 0, sizeof(las));
    // las[i][0] this computes length of the longest alternating subsequence ending at index i 
    // and the last element is greater than it's previous element

    // las[i][1] this computes the length of the longest alternating subsequence ending at index i 
    // and the last element is less than it's previous element
    for(int i=0;i<n;i++){
        las[i][0]=las[i][1]=1;
    }
    int res=INT_MIN;

    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if (arr[j]<arr[i] and las[i][0] < las[j][1]+1) {
                las[i][0]=las[j][1]+1;
            }
            if (arr[j]>arr[i] and las[i][1] < las[j][0]+1) {
                las[i][1]=las[j][0]+1;
            }
            if (res<max(las[i][0],las[i][1])) {
                res=max(las[i][0],las[i][1]);
            }
        }
    }
    return res;
}


int main() {
    vector<int> arr = { 10, 22, 9, 33, 49, 50, 31, 60 };
    cout << "Length of Longest Alternating Subsequence: " << longestAlternatingSubsequence(arr) << endl;
    return 0;
}
