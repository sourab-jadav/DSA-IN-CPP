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

// the naive idea of approaching this problem is construction the 
// path by selecting and not selecting the character from 0 to len-1 
// when you reach the end of the string length see that the string obtained is palindrome 
// if it is a palindrome compare it's length with the max length so far
bool check(string str){
    int low=0;
    int high=str.length()-1;
    while (low<high) {
        if (str[low]!=str[high]) {
            return false;
        }
        low++;
        high--;
    }
    return true;
}
int result=INT_MIN;
void solveLPS(string str,string curr,int i){
    if (i==str.length()) {
        if (check(curr)) {
            result=max(result,(int)curr.length());
            // result=max(result,curr.size()); // this line has error
                                            // here curr.size() returns number of size_t type
        }
        return;
    }
    solveLPS(str, curr+str[i], i+1);
    solveLPS(str, curr, i+1);
}
int main() {
    string str="BBABCBCAB";
    // string str="banana";
    solveLPS(str,"",0);
    std::cout<<result<<std::endl;
    return 0;
}
