#include <iostream>
#include <vector>
#include <string>
using namespace std;
// function to check if any substring of mid contains all the characters of the pattern
bool check(string str,string pat,int n){
    // to check if there is a window of size n which contains the pattern str
    int count[256]={0};
    for(auto c:pat){
        count[c]++;
    }
}
int main() {
    string str1="this is a test string";
    string pattern1="tist";
    return 0;
}


