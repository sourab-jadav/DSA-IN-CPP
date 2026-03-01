#include <iostream>
#include <stack>
#include <string>
#include <utility>

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::string str = "deeedbbcccbdaa";
    int k = 3;
    std::stack<std::pair<char, int>> stk;
    for (auto c : str) {
        if (stk.empty()) {
            stk.push({c, 1});
        } else if (stk.top().first == c) {
            stk.top().second++;
        } else {
            stk.push({c, 1});
        }
        if (stk.top().second == k) {
            stk.pop();
        }
    }
    std::string result = "";
    while (!stk.empty()) {
        int count = stk.top().second;
        for (int i = 0; i < count; i++) {
            result += stk.top().first;
        }
        stk.pop();
    }
    std::cout << result << std::endl;

    return 0;
}
