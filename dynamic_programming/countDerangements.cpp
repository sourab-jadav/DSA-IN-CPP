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


// https://www.geeksforgeeks.org/count-derangements-permutation-such-that-no-element-appears-in-its-original-position/
// ## PERMUTATION
//
// How does above recursive relation work? 
//
// There are n – 1 way for element 0 (this explains multiplication with n – 1). 
// Let 0 be placed at index i. There are now two possibilities, depending on whether or not element i is placed at 0 in return. 
//
//     i is placed at 0: This case is equivalent to solving the problem for n-2 elements as two elements have just swapped their positions.
//     i is not placed at 0: This case is equivalent to solving the problem for n-1 elements as now there are n-1 elements, n-1 positions and every element has n-2 choices
int solve(int n){
    // if the n==1 then derangements possible are 0;
    // if n==2 then derangements possible are 1;
    if (n==1) {
        return 0;
    }else if (n==2) {
        return 1;
    }
    return (n-1)*(solve(n-2)+solve(n-1));
}
int main() {
    int n;
    cin>>n;
    std::cout<<solve(n )<<std::endl;
    return 0;
}


