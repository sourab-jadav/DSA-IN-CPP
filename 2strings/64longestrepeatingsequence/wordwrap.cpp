#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int solveWordWrapUsingMemo(int words[], int n, int length, int wordIndex, int remLength, vector<vector<int>> memo);
int square(int n) { return n * n; }
// int solveWordWrap(int words[],int n,int k,int wordIndex,int remLength){
//     // what we can do 
//     // we can pick a current word 
//     // if the remLength==k we have to pick the current word
//     int result1=0;
//     if (wordIndex==n-1) {
//         return 0;
//     }
//     if (remLength>words[wordIndex]) { // if the word at i is subtractable
//         // why (remLength==k)? condition 
//         // when this condition satisfies you must select the word
//         if (remLength==k) {
//             // minimum of make the linebrake or don't make the linebreak
//             // when you make the linebreak the remLength resets to k value
//             // if you don't make the linebreak 
//             return square(k-words[wordIndex])+solveWordWrap(words, n, k, wordIndex+1, k);
//         }else {
//
//         }
//     }
//     // if the remaining length is less than k 
//     // then you have two options you either pick it 
//     // or add a break to the line by resetting the remaining length
//     // in solving these two subproblems you have to get the minimum result
//
//
// }

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
//
//
// int solveWordWrapUsingMemo(int words[], int n, int length, int wordIndex, int remLength, vector<vector<int>> memo) {
//     if (memo[wordIndex][remLength] != -1) { // wordIndex 
//         return memo[wordIndex][remLength];
//     }
//     memo[wordIndex][remLength] = solveWordWrapUtil(words, n, length, wordIndex, remLength, memo);
//     return memo[wordIndex][remLength];
// }
//
//
// int solveWordWrap(int words[], int n, int k) {
//     vector<vector<int>> memo(n, vector<int>(k + 1, -1)); // creating a memo array of size K+1 
//     return solveWordWrapUsingMemo(words, n, k, 0, k, memo); // 
// }


int main() {
    int words[] = {3, 2, 2, 5};
    int n = sizeof(words) / sizeof(words[0]);
    int k = 6;
    cout << solveWordWrap(words, n, k);
    return 0;
}
/* This Code is contributed by Tapesh (tapeshdua421) */
