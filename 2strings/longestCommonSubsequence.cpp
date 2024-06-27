#include <iostream>
#include <vector>
#include <string>
using namespace std;

int findLcs(string &s1,string &s2,int n,int m){
    if (m==0 || n==0) {
        return 0;
    }
    if (s1[n-1]==s2[m-1]) {
        return 1+findLcs(s1, s2, n-1, m-1);
    }
    return max(findLcs(s1, s2, n, m-1),findLcs(s1, s2, n-1, m));
}

int main() {
    string str1="aggtab";
    string str2="gxtxayb";
    int n=str1.length();
    int m=str2.length();
    return 0;
}


