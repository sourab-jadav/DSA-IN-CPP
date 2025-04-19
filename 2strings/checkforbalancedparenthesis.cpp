#include <iostream>
#include <stack>
#include <string>

// obeservations:
// closing brace will only appear after opening brace
// open brackets must  be closed in the correct order 
//
// ()[({)}]   -- this is not valid
bool check_para(std::string &str){
    // checking if the parenthesis is valid or not
    std::stack<char>stk;
    for(auto x :str){
        if (x=='(' || x=='[' || x=='{') {
            stk.push(x);
        }else {
            if (stk.empty() ||
                stk.top()=='[' && x != ']' ||
                stk.top()=='{' && x != '}' ||
                stk.top()=='(' && x != ')' 
                    ) return false;
            stk.pop();
        }
    }
  return true;
}
int main() {
    std::string str="()[{}()]";
    std::cout<<check_para(str)<<std::endl;
}
