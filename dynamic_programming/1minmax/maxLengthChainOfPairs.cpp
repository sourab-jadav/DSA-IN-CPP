#include <algorithm>
#include <climits>
#include <filesystem>
#include <iostream>
#include <utility>
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

int recursiveSol(vector<pair<int, int>>vec,int i,int prev){
    if (i==vec.size()) {
        return 0;
    }
    int include=0;
    if (vec[i].first>prev) {
        include=1+recursiveSol(vec, i+1, vec[i].second);
    }
    int exclude=recursiveSol(vec, i+1, prev);
    return max(include,exclude);
}
int main() {
    // this is problem is based on 
    // dynamic_programming/LongestIncreasingSubsequence.cpp
    vector<pair<int, int>>vec{{5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90} };
    int result=recursiveSol(vec, 0, INT_MIN);
    std::cout<<result<<std::endl;

    return 0;

}


