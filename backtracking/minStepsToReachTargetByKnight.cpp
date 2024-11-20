#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define printxyz(arr, rows, cols)                      \
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

// here the night is moving from one point to the another point
// is feasable function is required here
// is feasable checks for a given coardinate is possible or not
bool isFeasable(int x,int y,int N){
    if (x>=0 && x<N && y>=0 && y<N) {
        return true;
    }else {
        return false;
    }
}
int recursive_sol(int kX,int kY,int tX,int tY,int dx[],int dy[],int N){
    if (kX==tX && kY==tY) {
        // return 1; // problem here as it counts reaching the target as a single move
        return 0;
    }
    int next_x;
    int next_y;
    int result=INT_MAX;
    for(int i=0;i<N;i++){ // the recursive call inside the this loop does not correctly  handle the visited states
        next_x=kX+dx[i];
        next_y=kY+dy[i];
        if (isFeasable(next_x, next_y,  N) && recursive_sol(next_x, next_y, tX,tY,dx, dy, N)) { // calling the recursive 
                                                                                                // call twice leading to 
                                                                                                // redundant calculations
        // this algorithm lacks the mechanism to prevent revisiting the same cell
            result=min(result,1+recursive_sol(next_x, next_y, tX, tY, dx, dy, N));
        }
    }
    if (result!=INT_MAX) {
        return result;
    }else {
        return 0;
    }
}

int calculateSteps(int knightPos[],int targetPos[],int N){
    int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 };
    int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
    return recursive_sol(knightPos[0], knightPos[1], targetPos[0], targetPos[1], dx, dy, N);
}


int main() {
    // we have knight and we have the target
   int N=30;
   int knightPos[]{0,0};
   int targetPos[]{29,29};
   int result=calculateSteps(knightPos, targetPos, N);
   std::cout<<result<<std::endl;
    return 0;
}
