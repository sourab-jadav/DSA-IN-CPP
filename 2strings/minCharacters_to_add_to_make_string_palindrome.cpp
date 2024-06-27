#include <iostream>
#include <numeric>
#include <vector>
#include <string>
using namespace std;
//https://www.geeksforgeeks.org/minimum-characters-added-front-make-string-palindrome/ 
bool checkpalindrome(string str){
    int n=str.length();
    for(int i=0,j=n-1;i<=j;i++,j--){
        if (str[i]!=str[j]) {
            return false;
        }
    }
    return true;
}
int main() {
    string str="tcitkg";
    // while (str.length()>0) {
    //     if (checkpalindrome(str)) {
    //         break;
    //     }else {
    //         str.erase(str.length()-1); // removing the last character
    //         count++;
    //     }
    // }

    int count=0; // if you take the example of AACECAAAA you might think it is correct
                 // but if you take the exaple of tcitkg this approach is going to fail
    // int start=0;
    // int end=str.length()-1;
    // while (start<end) {
    //     if (str[start]==str[end]) {
    //         start++;
    //         end--;
    //     }else {
    //         end--;
    //         count++;
    //     }
    // }
    //
    // int n=str.length();
    // int start=0;
    // int end=n-1;
    //
    // int result=0;
    // while (start<end) {
    //
    //     if (str[start]==str[end]) {
    //         start++;
    //         end--;
    //     }else {
    //         result++;
    //         start=0;
    //         end=n-1-result;
    //     }
    //     
    // }
    // std::cout<<result<<std::endl;



}


