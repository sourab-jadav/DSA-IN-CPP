#include <algorithm>
#include <climits>
#include <iostream>
#include <type_traits>
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


// https://www.geeksforgeeks.org/maximum-difference-zeros-ones-binary-string/
// 011111010011 this code failed at this input
// code output is 1 
// actual output is 2
int getmax_diff(string s){
    int n=s.length();
    int i;
    for(i=0;i<n;i++){
        if (s[i]=='1') {
            continue;
        }else
            break;
    }
    if (i==n) {
        return -1;
    }
    int z_count=1;
    int one_count=0;
    int result=1;
    for(int j=i+1;j<n;j++){
        if (s[j]=='0') { // there was a typo here
            z_count++;
        }else {
            one_count++;
        }
        if (z_count>one_count) {
            result=max(result,z_count-one_count);
        }else {
            z_count=0;
            one_count=0;
        }
    }
    return result;
}


int main() {
    string s = "011111010011";
    std::cout<<getmax_diff(s)<<std::endl;
    return 0;
}


