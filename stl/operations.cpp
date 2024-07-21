#include <iostream>
#include <vector>
#include <string>
using namespace std;
// ----------------------------------------xor operation----------------------------------------
// 0 xor n is always n 
// n xor n is always 0
// 
// there is one trick often used in xor operation 
// say after performing xor on arr 
// you got the result as a1 ^ a2
//
// now what would you do to sperate a1 and a2 
//
// to do this we acquire the right most set bit of the result(a1^a2)
// set bit=x& ~(x-1)
//
// now divide the array elements into two groups  using the set bit
// in which one group contains a1 and and another group contains a2
// binary_search/AndSorting/repeatingAndMissing.cpp 
//
int main() {
    int n=45;
    std::cout<<(0^n)<<std::endl;
    return 0;
}


