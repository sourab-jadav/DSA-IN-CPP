#include <iostream>
#include <string>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

// Function to create the smallest N-digit palindrome
string createPalindrome(int N) {
    string half = to_string((int)pow(10, (N + 1) / 2 - 1));
    string palindrome = half;
    reverse(half.begin(), half.end());
    palindrome += half.substr(N % 2);
    return palindrome;
}

// Function to find the smallest N-digit palindrome divisible by 7
long long smallestPalindromeDivisibleBy7(int N) {
    long long start = stoll(createPalindrome(N));
    
    for (long long i = start; ; ++i) {
        string num = to_string(i);
        string rev = num;
        reverse(rev.begin(), rev.end());
        if (num == rev && i % 7 == 0) {
            return i;
        }
    }
}
#include <chrono>

int main() {
    int N;
    cin >> N;

// Add this to your main function
auto start = chrono::high_resolution_clock::now();
cout << smallestPalindromeDivisibleBy7(N) << endl;
auto end = chrono::high_resolution_clock::now();
chrono::duration<double> elapsed = end - start;
cout << "Elapsed time: " << elapsed.count() << " seconds" << endl;

    return 0;
}
// if (N < 1 || N > 100000) {
//     cout << "Invalid input, N should be in the range 1 <= N <= 10^5" << endl;
//     return 1;
// }
//
// cout << smallestPalindromeDivisibleBy7(N) << endl;
