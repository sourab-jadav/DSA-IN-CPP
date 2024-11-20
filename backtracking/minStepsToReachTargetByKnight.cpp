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
        return 1;
    }
    int next_x;
    int next_y;
    int result=INT_MAX;
    for(int i=0;i<N;i++){
        next_x=kX+dx[i];
        next_y=kY+dy[i];
        if (isFeasable(next_x, next_y,  N) && recursive_sol(next_x, next_y, tX,tY,dx, dy, N)) {
            // the problem here is due to the base case here at line 46 extra 1 is coming 
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
}


int main() {
    // we have knight and we have the target
   int n=30;
   int knightPos[]{0,0};
   int targetPos[]{29,29};
   int matrix[30][30];
   memset(matrix, 0, sizeof(matrix));
    return 0;
}
