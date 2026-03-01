#include <iostream>
#include <stack>
#include <climits>
class Stack{
    private:
    std::stack<int>stk;
    int minimum;
    public:
    void push(int n){
        if (stk.empty()) {
            stk.push(n);
            minimum=n;
        }else {
            if (n>=minimum) {
                stk.push(n);
            }else{
                int val=2*n-minimum;
                stk.push(val);
                minimum=n;
            }
        }
    }
    void pop(){
        // if (stk.top()>minimum) {
        //     stk.pop();
        // }else{
        //      // change it to the next minimum
        //     minimum=2*minimum-stk.top(); 
        // }
        if (stk.empty()) {
            return;
        }
        int el=stk.top();
        stk.pop();
        if (el<minimum) {
            minimum=2*minimum-el;
        }
    }
    int getMin(){
        return minimum;
    }
    int top(){
        if (stk.empty()) {
            return -1;
        }
        if (stk.top()<minimum) {
            return minimum;
        }else{
            return stk.top();
        }
    }
};

int main() {
    Stack s;

    s.push(7);
    s.push(5);
    s.pop();
    std::cout<<s.getMin()<<std::endl;
    return 0;
}

// https://www.notion.so/stacks-adf9420c96c546d9a521e953e3b7ef21?pvs=4#260f0f3390b24d32b26be7840a3341f1
