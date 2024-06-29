#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <stack>
// https://www.geeksforgeeks.org/recursively-remove-adjacent-duplicates-given-string/
using namespace std;
int main() {
    // this below approach is fine but the code quality is not good
    // while(true){
    //     bool isPresent=false;
    //     for(int i=0;i<str.size()-1;i++){
    //         if(str[i]==str[i+1]){
    //             isPresent=true;
    //             int j=i+1;
    //             while(j<n&& str[j]==str[i]){
    //                 j++;
    //             }
    //             str.erase(i,j-i);
    //         }
    //     }
    //     if(!isPresent){
    //         break;
    //     }
    // }
    // std::cout<<str<<std::endl;
     // let's try the recursive approach
     // 
     // i think we can solve this problem using recursion as well // let's see this some other time and let's use stack for now
     // now i remember i did this question with stacks


     // this solution will not work 
//
//     string str="yzxxzzy";
//     int n=str.size();
//     stack<char> stk;
//     stk.push(str[0]);
//     for(int i=1;i<str.length();){
//         if (stk.top()==str[i]) {
//             while (i<n&&  str[i]==stk.top()) { // wrong thought process here it will fail for geeksforgeeg
//                 i++;
//             }
//             stk.pop();
//         }
//         if (i<n) {
//             stk.push(str[i]);
//             i++;
//         }
//     }
// string result;
//     while (!stk.empty()) {
//         char c=stk.top();
//         result+=c;
//         stk.pop();
//     }
//     reverse(result.begin(),result.end());
//
//     std::cout<<result<<std::endl;
//



// okay we got some logic here // this is a working solution 
    string str="azxxzy";
    int n=str.size();
    stack<char>stk;
    stk.push(str[0]);

    for(int i=1;i<n;){
        while (i<n && !stk.empty()&&  stk.top()==str[i]) {
            while (i<n && str[i]==stk.top()) {
                i++;
            }
            stk.pop();
        }
            if (i<n) {
                stk.push(str[i]);
                i++;
            }
    }

    string result;
    while (!stk.empty()) {
        result+=stk.top();
        stk.pop();
    }
    reverse(result.begin(),result.end());
    std::cout<<result<<std::endl;







 

    return 0;
}


