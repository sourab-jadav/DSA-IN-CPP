#include <iostream>
#include <iterator>
#include <vector>
#include <string>
using namespace std;
// printing all subsequence of an array
void printSub(int arr[], int n, vector<int> v,int i) {
    if (i==n) { // you don't need i here 
        for (auto x : v) {
            std::cout<<x<<" ";
        }
        std::cout<<std::endl;
        return;
    }
    v.push_back(arr[i]);
    printSub(arr, n, v, i+1);
    v.pop_back();
    printSub(arr, n, v, i+1);
}
int main() {
    int arr[]{5,8,3,12};
    int n=sizeof(arr)/sizeof(arr[0]);
   vector<int>v;
    printSub(arr, n, v, 0);

    return 0;
}


