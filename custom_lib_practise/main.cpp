#include <iostream>
#include <user_definations.h>
#include <vector>

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::vector<int>vec=genV(10);
    for (auto x : vec) {
    std::cout<<x<<" ";
    }
    std::cout<<std::endl;
    return 0;
}


