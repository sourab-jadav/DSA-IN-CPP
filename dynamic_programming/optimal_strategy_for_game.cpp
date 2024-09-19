#include <algorithm>
#include <iostream>
#include <map>
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
// dynamic_programming/coin_game_winner_3_coins.cpp


//  when we think about the recursion we think about the sub problem
//  in the given problem first turn is A's turn 
//  when you call the subproblem the turn goes to B 
//  since B is playing as smartly as A 
//  it is going to select in such a way that minimum value sum comes to A
//
//  now say leftmost coins are vi and vi+1 
//  and rightmost coins are vj
//  
//  if A pick vi then options left for B are vi+1 and vj 
//  if B picks vi+1 then the range of options left for A will be vi+2 to vj 
//  if B picks vj then the range of options left for A will be vi+1 to vj-1
//  since B is playing as smart as A ,B will pick in such a way that the sum of coins A gets is minimum
//
//  if A picks vj then options left for B are from vi to vj-1
//  if B picks vi then the range of options left for A will be vi+1 to vj-1
//  if B picks vj-1 then the range of options left for A will be vi to vj-2
//
//
map<vector<int>, int>memo;

// int max_value(int arr[],int start,int end,int n){ // working solution
//     // the base cases can be 
//     // when there is only one coin
//     if (start==n || end <0) {
//         return 0;
//     }
//     if (start==end) {
//         return arr[start];
//     }else if (start+1 ==end) {
//         return max(arr[start],arr[end]);
//     }
//     vector<int>k{start,end};
//     if (memo[k]!=0) {
//         return memo[k];
//     }
//     // let A picks vi
//     // and minimum of B picking vi+1 and B picking vj
//     int pick_left=arr[start]+min(max_value(arr, start+2, end, n),max_value(arr, start+1, end-1, n));
//     // let A picks vj 
//     // and minimum of B picking vj-1  and B picking vi
//    int pick_right=arr[end]+min(max_value(arr, start, end-2, n),max_value(arr, start+1, end-1, n));
//    return memo[k]=max(pick_left,pick_right);
// }


// tabulizing the solution
int max_value(int arr[],int start,int end,int n){ // working solution
    int table[n][n];
    for(int gap=0;gap<n;++gap){
        for(int i=0,j=gap;j<n;i++,j++){
            // here x is value of f(i+2,j)
            // and y is value of f(i+1,j-1)
            // and z is value of f(i,j-2)
            //
            int x=((i+2)<=j)?table[i+2][j]:0;
            int y=((i+1)<=(j-1))?table[i+1][j-1]:0;
            int z=(i<=(j-2))?table[i][j-2]:0;
            table[i][j]=max(arr[i]+min(x,y),arr[j]+min(y,z));
        }
    }
    return table[0][n-1];
}

int main() {
//     int arr[]{
// 5182,4596,4284,3795,6756,5167,5484,634,9364,137,776,7467,9023,4808,9384,5803,2573,9776,882,3018,7742,8307,7963,4387,9402,2827,5742,5685,4144,3668,8156,4452,9808,4571,1296,2437,6246,8771,8950,8695,8126,9865,9954,5347,3211,3067,5645,7663,6679,2691,2796
// }; 
    int arr[]{5,3,7,10};
    // int arr[]{20,30,2,2,2,10};
    // int arr[]{2,2,2,2}; 
    int n=sizeof(arr)/sizeof(arr[0]);
    int result=max_value(arr,0,n-1,n);
    std::cout<<result<<std::endl;

}
