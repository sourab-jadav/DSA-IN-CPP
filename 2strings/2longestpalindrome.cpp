#include <iostream>
#include <string>
#include <vector>
using namespace std;
// void print_palindrome(string str, int low, int high) {
//     for (int i = low; i <= high; i++) {
//         std::cout << str[i];
//     }
// }
// int main() {
//     string str = "forgeeksskeegfor";
//     int n = str.length();
//     // generating all the possible substrings and checking palindrome or not ,if
//     // it is then we are getting the maximum length
//     int maxlength = 1;
//     int start = -1;
//     for (int i = 0; i < n; i++) {
//         for (int j = i; j < n; j++) {
//             bool flag = true;
//             for (int k = 0; k < (j - i + 1) / 2; k++) { // this is important
//                 if (str[i + k] != str[j - k]) {
//                     flag = false;
//                 }
//             }
//             if (flag && (j - i + 1) > maxlength) {
//                 start = i;
//                 maxlength = j - i + 1;
//             }
//         }
//     }
//     print_palindrome(str, start, start + maxlength - 1);
//     return 0;
// }
//
// now considering each element as the middle element or left of the middle element and finding the longest 
// palindrome possible


int main(){
    string str="forgeeksskeegfor"; 
    // traverse the each character of the string as the middle or middle left
    int n=str.length();
    int count=0;
    int result=0;

    for(int i=0;i<n;i++){
        int left=i;
        int right=i+1;
        int count=0;
        while (left>=0 && right<n && str[left]==str[right]) {
            left--;
            right++;
            count++;
        }
        result=max(result,count);
    }
    std::cout<<result<<std::endl;
    // also calculate for the odd length you will have your answer
}
