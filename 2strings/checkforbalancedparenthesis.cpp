#include <iostream>
#include <stack>
#include <string>

// obeservations:
// closing brace will only appear after opening brace
// open brackets must  be closed in the correct order 
//
// ()[({)}]   -- this is not valid
//
// explaination:
// since it is given that open brackets must be closed in the order 
// meaning the recently opened bracket must be closed first
// 
//      to solve this we can make use of stack container and compare each closing bracket with recently opened bracket
//      in each comparision with the closing bracket if they found to be different bracket type then the order is incorrect and you return false
//
//      else they must be same type and you pop the opening bracket from the stack 
//
//      
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
