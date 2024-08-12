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

// the problem is you are given number of floors
// and number of eggs
// say 36 floors starting from floor 1(ground) to floor 36(top) and 2 eggs 
// you have to find min floor no. dropping from which the egg breaks 
// you might think you start with floor 1 and try to drop egg at ith floor if the egg breaks 
// you written that floor value 
//
// but there is constraint on the number of eggs you can use and you have to solve the problem in 
// as minimum checks as possible
//
// Eg: say Eggs=2 and number of floors are 36
// you try to drop the egg from the 12th floor if it breaks actual floor is towards bottom and only one egg left so ans=11+1 checks
// if the egg does not break the answer lies towards up and only one egg left 11+1
//
// how you should you think
// you drop it you don't drop it if you drop it left with n-1 
// or when you drop the egg at a given floor the egg breaks or it doesn't break  // this is right
// 

// recursive approach
int solve(int no_of_floors_left,int no_of_eggs_left){
    if (no_of_eggs_left==1) {
        return no_of_floors_left;
    }
    // when the egg breaks 
    int breaks=1+solve(no_of_floors_left-1, no_of_eggs_left-1);
    int does_not_break=solve(int no_of_floors_left, int no_of_eggs_left)
}





int main() {
    
    return 0;
}
