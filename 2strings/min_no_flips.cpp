#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
// int min_number_flips(string &str,int n,char previous){
//     if (n==1) {
//         if (str[n-1]==previous) {
//             return 1;
//         }else {
//             return 0;
//         }
//     }
//     if (n<str.length() and str[n-1]==previous) {
//         return 1+min_number_flips(str, n-1, previous=='0'?'1':'0');
//     }else {
//         return min_number_flips(str, n-1, str[n-1]);
//     }
// }
// int main() {
//     string str="100100000111111101010010010011010101110110"; // not worked for this input for somereason
//     int n=str.length();
//     int result=min(min_number_flips(str, n-1, str[n-1]),1+min_number_flips(str, n-1,str[n-1]=='0'?1:'0'));
//     std::cout<<result<<std::endl;
//     return 0;
// }
//
//
// another idea is to get the answer by flipping the odd places and even plces and return th minimum of these two
// we can refactor this code but i don't want to do.
int main(){ // this is the working solution with all the test cases passed
    string str="100100000111111101010010010011010101110110"; // not worked for this input for somereason
    char previous=str[0];
    int n=str.length();
    int result=0;
    for(int i=1;i<n;i++){
        if (str[i]==previous) {
            result++;
            previous=previous=='1'?'0':'1';
        }else {
            previous=str[i];
        }
    }
    int evens=result;
    previous=str[0]=='0'?'1':'0';
    result=1;
    for(int i=1;i<n;i++){
        if (str[i]==previous) {
            result++;
            previous=previous=='1'?'0':'1';
        }else {
            previous=str[i];
        }
    }
    int odds=result;
    int final=min(evens,odds);
    std::cout<<final<<std::endl;
}
