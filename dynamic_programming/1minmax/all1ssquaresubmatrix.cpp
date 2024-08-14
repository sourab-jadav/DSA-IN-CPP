#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define R 6
#define C 5

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

int printMaxSubSquare(bool M[R][C]){
    int result[R][C];
    memset(result, 0, sizeof(result));
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            result[i][j]=M[i][j];
        }
    }
    bool flag=true;
    int res=1;
    for(int i=1;i<R;i++){
        for(int j=1;j<C;j++){
            if (M[i-1][j-1]==1 and M[i-1][j]==1 and M[i][j-1]==1) {
                int x=min(result[i-1][j-1],min(result[i-1][j],result[i][j-1]));
                result[i][j]=x+1;
                if (x+1>res) {
                    res=x+1;
                }
            }
        }
    }
    printxyz(result, R, C);
    return res;
}
int main()
{
    
    bool M[R][C] = { { 0, 1, 1, 0, 1 }, { 1, 1, 0, 1, 0 },
                     { 0, 1, 1, 1, 0 }, { 1, 1, 1, 1, 0 },
                     { 1, 1, 1, 1, 1 }, { 0, 0, 0, 0, 0 } };
 
    int result=printMaxSubSquare(M);
    std::cout<<"the max square is of order "<<result<<std::endl;
}
