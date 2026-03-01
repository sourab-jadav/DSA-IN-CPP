#include <algorithm>
#include <iostream>
#include <stack>
#include <utility>
#include <climits>
// this implementation uses o of 2n extra space
class Stack{
    private:
        std::stack<std::pair<int, int>>stk;
        int minimum;
    public:
        Stack():minimum(INT_MAX){ }
        void push(int n){
            minimum=std::min(minimum,n);
            stk.push({n,minimum});
        }
        int pop(){
            int popped_element=stk.top().first;
            stk.pop();
            return popped_element;
        }
        int getminimum(){
            int element=stk.top().second;
            return element;
        }
        int getTop(){
            return stk.top().first;
        }
};
int main() {
    Stack s;
    s.push(-2);
    s.push(0);
    s.push(-3);
    s.push(5);
    s.push(6);
    std::cout<<s.getminimum()<<std::endl;
    std::cout<<"top element: "<<s.getTop()<<std::endl;
    return 0;
}
