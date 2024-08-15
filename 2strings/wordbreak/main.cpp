#include <algorithm>
#include <bits/stdc++.h>
#include <cstring>
#include <unordered_set>

using namespace std;
// 
// the qeustion is you are given an input string you have to find out if a given string can be segmented 
// into a space seperated sequence of disctonary of words 

// using above logic"applexyzpenapple" this string returns true which is clearly not correct
// bool wordBreak(string s, unordered_set<string> &dict) {
//     std::cout<<s.length()<<std::endl;
//     std::cout<<"it's size is "<<s.size()<<std::endl;
//     if (dict.size() == 0)
//         return false;
//     vector<bool> dp(s.size() + 1, false);
//     dp[0] = true;
//     for (int i = 1; i <= s.size(); i++) {
//         for (int j = i - 1; j >= 0; j--) {
//             if (dp[j]) {
//                 string word = s.substr(j, i - j);
//                 if (dict.find(word) != dict.end()) {
//                     dp[i] = true;
//                     break; // next i
//                 }
//             }
//         }
//     }
//     int i=0;
//     for (auto x : dp) {
//         std::cout<<i<<" "<<x<<std::endl;
//         i++;
//     }
//
//     return dp[s.size()];
// }

// another implementation of word break problem
// bool wordBreak(string s,unordered_set<string>words){ // working solution
//     int n=s.length();
//     // what we can do is we traverse through the string from i=0 to len-1 
//     // and we maintain dp of size of the string 
//     // for each i you traverse from j=i-1 and extract substr of size i-j 
//     // and see if that substr is present in the dict as implemented in the above solution
//     // using above logic"applexyzpenapple" this string returns true which is clearly not correct
//      // one way is by modifying the string
//     string str=s;
//     // one brute force solution with manupulating the string
//     while (!str.empty()) {
//         int n=str.length();
//         bool flag=false;
//         for(int i=n-1;i>=0;i--){
//             for(int j=i;j>=0;j--){
//                 if (words.find(str.substr(j,i-j+1))!=words.end()) {
//                     str.erase(j,i-j+1);
//                     flag=true;
//                 }
//             }
//             if (flag) {
//                 break;
//             }
//         }
//         if (!flag) {
//             break;
//         }
//     }
//     if (str.empty()) {
//         std::cout<<"the string value is empty and the answer is true"<<std::endl;
//     }else{ 
//         std::cout<<str<<std::endl;
//         std::cout<<"the string is not empty and the word break is not possible"<<std::endl;
//     }
//     return str.empty();
// }



// recursive implementation the idea is 
// we consider each prefix and search for it in the dictionary and 
// we recur for the rest of the string(suffix ) if the recursive call returns 
// true we return true or else we return false
bool wordbreak(string s,unordered_set<string>d){
    if (s.empty()) {
        return true;
    }
    for(int i=1;i<=s.length();i++){
        string prefix=s.substr(0,i);
        if (find(d.begin(),d.end(),prefix)!=d.end() and wordbreak(s.substr(i), d)) {
           return true; 
        }
    }
    return false;
}
int main() {
    string s= "iiiiiiii";
    unordered_set<string> words = {"mobile", "samsung", "sam", 
          "sung", "man", "mango", "icecream", "and", "go", 
          "i", "like", "ice", "cream"};
    bool result=wordbreak(s, words);
    std::cout<<result<<std::endl;
    return 0;
}
