#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define printxyz(arr, rows, cols)                      \
    do {                                               \
        std::cout<<std::endl;                          \
        for (int i = 0; i < rows; ++i) {               \
            for (int j = 0; j < cols; ++j) {           \
                std::cout << arr[i][j] << " ";         \
            }                                          \
            std::cout << std::endl;                    \
        }                                              \
        std::cout<<std::endl;                          \
    } while (0)
#define printarray(arr, n)                             \
        std::cout<<std::endl;                          \
        for (int i = 0; i < n; ++i) {                  \
            std::cout<<arr[i]<<" ";                    \
        }                                              \
        std::cout<<std::endl;                          \

std::vector<std::string>result;
void printPermute(std::string str,int i){
    if(i==str.length()){
        std::cout<<str<<std::endl;
        result.push_back(str);
    }
    for(int j=i;j<str.length();j++){
        std::swap(str[i],str[j]);
        printPermute(str, i+1);
        std::swap(str[i],str[j]);
    }
}
// palindrome partitioning
// the idea could be we take two end points i and j 
// if the subtring from i to j is a palindrome then we return 0 for that 
// else we have two cases we take min of i+1,j and i,j-1
bool ispalindrome(string str,int start,int end){
    while (start<end) {
        if (str[start]!=str[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}
// int palindromic_partitioning(string str,int start,int end){ // not working solution
//     if (start==str.length() || end <0 || ispalindrome(str, start, end)) {
//         return 0;
//     }
//     else {
//         return min(1+palindromic_partitioning(str, start+1, end),1+palindromic_partitioning(str, start, end-1));
//     }
// }
// ababbbabbababa -> a|babbbab|b|ababa
// to minimize the number of cuts 
// we traverse through the loop and make cut after every single character and see the cut made till that part 
// is a palindrome or not 
// we make the cut by dividing the big string into two parts 0 to i and i+1 n-1 and add +1(since we made a cut)
int palindromic_partitioning(string str,int start,int end){ // core dumped
    if ( start>=end ||ispalindrome(str, start, end)) {
        return 0;
    }
    int result=INT_MAX;
    int current=0;
    for(int i=start;i<end;i++){
        current=palindromic_partitioning(str, start, i)+palindromic_partitioning(str, i+1, end)+1;
        result=min(result,current);
    }
    return result;
}
// since recursion is involved in the above problem can we apply dynamic programming inorder to solve the problem
// yes we can
int solvedp(string str){ // dp not worked
    int n=str.length();
    // now can we approach the problem 
    int count[n][n];
    bool pal[n][n];
    memset(pal, false, sizeof(pal));
    memset(count, 0, sizeof(count));
    for(int i=0;i<n;i++){
        pal[i][i]=true;
    }
    // palindrome of length one
    for(int gap=1;gap<n;gap++){
        for(int i=0,j=gap;j<n;i++,j++){
            // we have i and j set here

            // now check if it is a palindrome or not
            if (j-i+1==2) {
                //  check palindrome of length 2 
                pal[i][j]=str[i]==str[j];
            }else {
                pal[i][j]=(str[i]==str[j]) && pal[i+1][j-1];
            }

            if (pal[i][j]) {
                count[i][j]=0;
            }else {
                count[i][j]=INT_MAX;
                for(int r=i;r<j;r++){
                    count[i][j]=min(count[i][j],count[i][r]+count[r+1][j]+1);
                }
            }
        }
    }
    return count[0][n-1];
}
int main() {
    // std::string str="abcdaabd";
    // std::cout<<"printing possible substrings of specified length"<<std::endl;
    // int n;
    // std::cin>>n;
    // std::vector<std::string>temp;
    // for(int i=0;i<=(int)str.length()-n;i++){
    //     std::string str_temp=str.substr(i,n);
    //     temp.push_back(str_temp);
    // }
    // for (auto st : temp) {
    //     std::cout<<st<<" ";
    // }
    // std::cout<<std::endl;
    // return 0;
    // // std::string str="123";
    // // printPermute(str, 0);
    //

    // std::string str="ababbbabbababa";
    string str="ababbbabbababa";
    // int result=palindromic_partitioning(str, 0, str.length()-1);
    // int result2=minPalPartion(str, 0, str.length()-1);
    // std::cout<<result2<<std::endl;
    std::cout<<solvedp(str)<<std::endl;
}
