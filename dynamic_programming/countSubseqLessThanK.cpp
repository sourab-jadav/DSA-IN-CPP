#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define printxyz(arr, rows, cols)                      \
    do {                                               \
        std::cout<<std::endl;                          \
        for (int i = 0; i < rows; ++i) {               \
            for (int j = 0; j < cols; ++j) {           \
                std::cout << arr[i][j] << " ";         \
            }                                          \
            std::cout << std::endl;                    \
        }                                              \
        std::cout<<std::endl;                          \
    } while (0)
#define printarray(arr, n)                             \
        std::cout<<std::endl;                          \
        for (int i = 0; i < n; ++i) {                  \
            std::cout<<arr[i]<<" ";                    \
        }                                              \
        std::cout<<std::endl;                          \

// counting all the subsequences that are possible which are less than or equal to k 
// one brute force idea is traverse all the path by including and not including the elements
// on reaching the end of the each path take all the elements and compute it and check if it less 
// than k if yes then do count++;
void solve(int arr[],int i,int n,vector<int>&vec,int &count,int k){
    if (i==n) {
        int result=1;
        for (auto x : vec) {
            result*=x;
        }
        if (result<k and !vec.empty()) {
            ++count;
            std::cout<<count<<std::endl;
        }
        return;
    }
    vec.push_back(arr[i]);
    solve(arr, i+1, n, vec, count, k);
    vec.pop_back();
    solve(arr, i+1, n, vec, count, k); 
}
// one problem which i faced was for the input 1,2,3,4 
// the output got was 12 but the actual answer was 11 
// later realized that it is considering the the emtpy vector as well
// to solve this added constraint !vec.empty()
int main() {
    int arr[]{1,2,3,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    int count=0;
    vector<int>vec;
    solve(arr, 0, n, vec, count,10);
    std::cout<<"the result is "<<count<<std::endl;
    return 0;
}


