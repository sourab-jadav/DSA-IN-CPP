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

// we can count all the possible subseq using the first approach 
// discussed in this problem
// dynamic_programming/longest_palindromic_subsequence.cpp
// recurrence relation can be defined as 
// if i==j then only one character we return 1
// else if i!=j and str[i]==str[j] then we check for the rest subseq i+1 ,j and i ,j-1
// else when they are not equal we don't consider subseq starting with i and ending with j 
//  ( so i+1 ,j ) + (i,j-1)  => here each recursive call also covers subseq of (i+1,j-1) so they are counted twice
//  hence we do (i+1,j)+(i,j-1)-(i+1,j-1)
//
// int solveRecursive(string str,int i,int j){
//     if (i<j) {
//         if (i==j) {
//             return 1;
//         }
//         if (str[i]==str[j]) {
//             return 1+solveRecursive(str, i+1, j-1);
//         }else {
//             return solveRecursive(str, i+1, j)+solveRecursive(str, i, j-1);
//         }
//     }
//     return 0;
// }

int solveRecursive(string str,int i,int j){
    // when there is only one character
    if (i<=j ) {
        if (i==j) {
            return 1;
        }
        if (str[i]==str[j]) {
            return 1+solveRecursive(str, i+1, j)+solveRecursive(str, i, j-1); 
            // understanding why we are not doing -solveRecursive(i+1,j-1) is required here
            // as they are part of the palindrome
        }else {
            // now if the element at i and j does not match
            // we recur towards right by doing i+1 
            // or we recur towards left by doing j-1
            // 
            // this below line is calculating the result of f(i+1,j-1) two times 
            // this recursion call is not adding any value to the result
            // and going down we are getting the value of i+1 and j-1 two times
            return solveRecursive(str, i+1, j)+solveRecursive(str, i, j-1)-solveRecursive(str, i+1, j-1);
        }
    }
    return 0;
}

// can we tabulize the above solution
// see if we can tabulize the above solution
int dpsolve(string str){
    int n=str.length();
    int cps[n+1][n+1];
    // each character is a palindrome in it self
    // problem for length 1 is solved
    for(int i=0;i<n;i++){
        cps[i][i]=1;
    }
    // 
    // for palindrome of length 2 we try to calculate recursively
    for(int l=2;l<=n;l++){
        for(int i=0;i<=n-l;i++){
            int k=i+l-1;
            if (str[i]==str[k]) {
                cps[i][k]=cps[i+1][k]+cps[i][k-1]+1;
            }else {
                cps[i][k]=cps[i+1][k]+cps[i][k-1]-cps[i+1][k-1];
            }
        }
    }
    return cps[0][n-1];
}
int main() {
    string str="abcd";
    std::cout<<solveRecursive(str, 0, (int)str.length()-1)<<std::endl;
    return 0;
}

