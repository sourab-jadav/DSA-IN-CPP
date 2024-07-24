#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

// you are given values as follows
// T -> number of testcases
// N -> number of lines -> each line has [A B] // denoting the range
// Q -> number of lines -> each line has value k //for finding kth smallest
//
//
// take all the range lines and put it into the set
// take each k value from the Q lines and get the kth smallest from the set
