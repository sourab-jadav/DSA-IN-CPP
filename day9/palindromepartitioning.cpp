#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
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
    for(int i=start;i<=end;i++){ // here = is the reason for code dumped
        current=palindromic_partitioning(str, start, i)+palindromic_partitioning(str, i+1, end)+1;
        result=min(result,current);
    }
    return result;
}
int minPalPartion(string String, int i, int j)
{
    // Base case: If the substring is empty or a palindrome,
    // no cuts needed
    if (i >= j || ispalindrome(String, i, j))
        return 0;
 
    int ans = INT_MAX, count;
 
    // Iterate through all possible partitions and find the
    // minimum cuts needed
    for (int k = i; k < j; k++) {
        count = minPalPartion(String, i, k)
                + minPalPartion(String, k + 1, j) + 1;
        ans = min(ans, count);
    }
 
    return ans;
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

    std::string str="ababbbabbababa";
    int result=palindromic_partitioning(str, 0, str.length()-1);
    // int result2=minPalPartion(str, 0, str.length()-1);
    // std::cout<<result2<<std::endl;
    std::cout<<result<<std::endl;

}
