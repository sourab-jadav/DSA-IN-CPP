#include <iostream>
#include <stack>
#include <string>
class BrowserHistory {
    private:
        std::stack<std::string> current_stack;
        std::stack<std::string> forward_stack;
    public:
        BrowserHistory(std::string homepage) {
            current_stack.push(homepage);
        }

        void visit(std::string url) {
            current_stack.push(url);
            forward_stack = std::stack<std::string>();
        }

        std::string back(int steps) {
            while (steps > 0 && current_stack.size() > 1) {
                forward_stack.push(current_stack.top());
                current_stack.pop();
                steps--;
            }
            return current_stack.top();
        }

        std::string forward(int steps) {
            while (steps > 0 && forward_stack.size() > 0) {
                current_stack.push(forward_stack.top());
                forward_stack.pop();
                steps--;
            }
            return current_stack.top();
        }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    BrowserHistory* obj = new BrowserHistory("leetcode.com");
    obj->visit("google.com");
    obj->visit("facebook.com");
    obj->visit("youtube.com");
    std::cout<<obj->back(4)<<std::endl;
    return 0;
}


