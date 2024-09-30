#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int solveWordWrapUsingMemo(int words[], int n, int length, int wordIndex, int remLength, vector<vector<int>> memo);
int square(int n) { return n * n; }
int solveWordWrapUtil(int words[], int n, int length, int wordIndex, int remLength, vector<vector<int>> memo) {
    // base case for last word
    if (wordIndex == n - 1) {
        // if we reach the end of the word
        // if the remaining length is greater than lastword size then we ignore the word and return 0
        // else if the remaining length is <= lastword size then we increase the remaining length by its square
        memo[wordIndex][remLength] = words[wordIndex] < remLength ? 0 : square(remLength);
        return memo[wordIndex][remLength];
    }
    int currWord = words[wordIndex];
    // if word can fit in the remaining line
    // we are playing with remaining length here
    if (currWord < remLength) {
        // two cases here:
        // if it is the first word of the line i.e remaininglength==k then we just decrease the size of the line by current word size
        // else if it is the word appearing after the first word has appeared we decrease the line size by wordsize and 1(for the space b/w current word and prev word)
        return min(solveWordWrapUsingMemo(words, n, length, wordIndex + 1, remLength == length ? remLength - currWord : remLength - currWord - 1, memo),
                square(remLength) + solveWordWrapUsingMemo(words, n, length, wordIndex + 1, length - currWord, memo));
    } else {
        // if word is kept on next line
        return square(remLength) + solveWordWrapUsingMemo(words, n, length, wordIndex + 1, length - currWord, memo);
    }
}

int main() {
    int words[] = {3, 2, 2, 5};
    int n = sizeof(words) / sizeof(words[0]);
    int k = 6;
    // cout << solveWordWrap(words, n, k);
    vector<vector<int>>memo(n,vector<int>(k+1,-1));
    std::cout<<solveWordWrapUtil(words, n, k, 0, k, memo)<<std::endl;
    return 0;
}
/* This Code is contributed by Tapesh (tapeshdua421) */
