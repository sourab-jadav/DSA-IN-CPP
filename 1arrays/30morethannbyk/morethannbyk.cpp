#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    int arr[] = {3, 1, 2, 2, 1, 2, 3, 3}, k = 4;
    int n = sizeof(arr) / sizeof(arr[0]);

    // how do we proceed with the soultion
    // we follows morres voting algorithm
    //
    // it says at max there can be k-1 elements present in an array
    // which appears more then n/k times so there will be k-1 condidate keys
    std::cout << "counting more than n / k occurences that can be possible" << std::endl;
    

    int temp[k-1];




    return 0;
}
