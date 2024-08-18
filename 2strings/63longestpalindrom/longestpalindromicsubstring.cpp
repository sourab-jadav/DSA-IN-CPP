// // A C++ dynamic programming solution for longest palindrome
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
// // Function to print a substring str[low..high]
// void printSubStr(string str, int low, int high) {
//     for (int i = low; i <= high; ++i)
//         cout << str[i];
// }
//
// // try this problem as a prerequisite
// // dynamic_programming/countAllPalindromicSubseq.cpp // this might seem difficult but common it's easy
// // let's try to write a recursive solution for the problem
//
//
// // this recurence relation is not currect
// // int longestPalindrome_recursion(string str,int i,int j){
// //     if (i<=j) {
// //         if (i==j) {
// //             return 1;
// //         }
// //         if (str[i]==str[j] and longestPalindrome_recursion(str, i+1, j-1)) {
// //             return longestPalindrome_recursion(str, i+1, j-1)+2;
// //         }else {
// //             return max(longestPalindrome_recursion(str, i+1, j),longestPalindrome_recursion(str, i, j-1));
// //         }
// //     }
// //     return 0;
// // }
//
//
//
//
//
// // This function prints the longest palindrome substring It also returns the length of the longest palindrome
// // subproblems are identified based on the length from length 1(center) and expanding towards left and right
// int longestPalSubstr(string str) {
//     // get length of input string
//     int n = str.size();
//     // table[i][j] will be false if substring  str[i..j] is not palindrome.Else table[i][j] will be true
//     bool table[n][n];
//     memset(table, 0, sizeof(table));
//     // All substrings of length 1 are palindromes
//     int maxLength = 1;
//     for (int i = 0; i < n; ++i)
//         table[i][i] = true;
//     // check for sub-string of length 2.
//     int start = 0;
//     for (int i = 0; i < n - 1; ++i) {
//         if (str[i] == str[i + 1]) {
//             table[i][i + 1] = true;
//             start = i;
//             maxLength = 2;
//         }
//     }
//     // Check for lengths greater than 2.
//     // k is length of substring
//     for (int k = 3; k <= n; ++k) {
//         // Fix the starting index
//         for (int i = 0; i < n - k + 1; ++i) {
//             // Get the ending index of substring from
//             // starting index i and length k
//             int j = i + k - 1;
//             // checking for sub-string from ith index to
//             // jth index if str[i+1] to str[j-1] is a
//             // palindrome
//             if (table[i + 1][j - 1] && str[i] == str[j]) {
//                 table[i][j] = true;
//                 if (k > maxLength) {
//                     start = i;
//                     maxLength = k;
//                 }
//             }
//         }
//     }
//     cout << "Longest palindrome substring is: ";
//     printSubStr(str, start, start + maxLength - 1);
//     // return length of LPS
//     return maxLength;
// }
// // you can also do expansion from the center 
// // Driver Code
// int main()
// {
//     string str = "forgeeksskeegfor";
//     // cout << "\nLength is: "
//     //      << longestPalSubstr(str);
//     // std::cout<<longestPalindrome_recursion(str, 0, (int)str.length()-1)<<std::endl;
//     return 0;
// }
//
//

// Recursive function to find the longest palindromic substring
// string longestPalindromeRecursive(const string& s, int left, int right, unordered_map<string, string>& memo) {
//     if (left > right) {
//         return "";
//     }
//
//     // Form a unique key for memoization
//     string key = to_string(left) + "," + to_string(right);
//
//     if (memo.find(key) != memo.end()) {
//         return memo[key];
//     }
//
//     if (isPalindrome(s, left, right)) {
//         memo[key] = s.substr(left, right - left + 1);
//         return memo[key];
//     }
//
//     // Case 1: Exclude the current left character and solve for the rest
//     string palindrome1 = longestPalindromeRecursive(s, left + 1, right, memo);
//
//     // Case 2: Exclude the current right character and solve for the rest
//     string palindrome2 = longestPalindromeRecursive(s, left, right - 1, memo);
//
//     // Return the longer palindrome
//     string result = (palindrome1.length() > palindrome2.length()) ? palindrome1 : palindrome2;
//     memo[key] = result;
//     return result;
// }

// string longestPalindrome(const string& s) {
//     unordered_map<string, string> memo;
//     return longestPalindromeRecursive(s, 0, s.length() - 1, memo);
// }
//
// Example usage
int main() {
    string s = "forgeeksskeegfor";
    cout << "Longest Palindromic Substring: " << longestPalindrome(s) << endl;
    return 0;
}
