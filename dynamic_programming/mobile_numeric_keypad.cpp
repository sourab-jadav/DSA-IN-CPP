#include <cstring>
#include <iostream>
#include <stdexcept>
#include <utility>
#include <variant>
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

// https://www.geeksforgeeks.org/mobile-numeric-keypad-problem/

// wrong throught process
// given a number n 
// find the all possible sequences of length n that we can create by pressing the buttons
//  we can start from any digit
//
//
// to solve this problem we can think of backtrackig here 
// maintain a visited array 
// if the value is not visited 
//      go to it's appropriate direction and visited the value 
//      call the recursive function for the next digit in the sequence [ this completes the sequence ]
//      keep the visited as false 
//
//  make a flag if all the nodes are visited then print the sequence
//
// void getsequences(bool visited[],int n,int j,vector<int>&v1){
//     if (n==1) {
//         visited[j]=true;
//         v1.push_back(j);
//         return ;
//     }
//     bool flag=false;
//     for(int i=0;i<n;i++){
//         if (!visited[i]) {
//             visited[i]=true;
//             getsequences(visited, n-1, i, vector<int> &v1)
//         }
//     }
// }



// in the above process you thought interms of value 
// i.e if we are at 0 then we can only move to 8 in the next recursive call you only visit 8 
// and recursively visit the values horizontally and vertically
// to think in this way we can make use of array list 


// not working solution
// void solvesequences(vector<int>arr[],bool visited[],int length,int j,vector<int> &q){
//     if (visited[j]) {
//         return;
//     }
//     bool flag=true;
//     if (length==1) {
//         visited[j]=true;
//         for(auto x:q){
//             std::cout<<x<<" ";
//         }
//         std::cout<<std::endl;
//         return;
//     }else {
//         for(auto x:arr[j]){
//             if (!visited[x]) {
//                 flag=false;
//                 visited[j]=true;
//                 q.push_back(x);
//                 solvesequences(arr, visited, length-1, x,q);
//                 q.pop_back();
//             }
//         }
//         q.pop_back();
//     }
//     return ;
// }


// 1 2 3
// 4 5 6
// 7 8 9
//   0

//working solution to the problem
// //given length of seq,
// //      visited array
// //      array list 
// //
// //  counting the sequnces of length n 
// //  mobile keyboard is a rectangular keyboard of 4*3 columns you can apply recursion on this matrix 
// //  by handling the boundry conditions to the i and j and cells like (3,0) and (3,2);
// // working solution to the problem
// int getsequencesUtil(int i,int j,int length){
//     //handling the boundry conditions
//     if (i<0 || i>3 || j<0 || j>2 || (i==3 && j==0) || (i==3 && j==2)) {
//         return 0;
//     }
//     else {
//         vector<pair<int, int>>dist{
//             {-1,0},{1,0},{0,1},{0,-1},{0,0}
//         };
//
//         int result{};
//         if (length==1) {
//            return 1; 
//         }else {
//            for(auto x:dist){
//                result+=getsequencesUtil(i+x.first, j+x.second, length-1);
//            } 
//         }
//         return result;
//     }
// }
// int getsequences(int length){
//
//     int result{};
//     for(int i=0;i<4;i++){
//         for(int j=0;j<3;j++){
//             result+=getsequencesUtil(i, j, length);
//         }
//     }
//     return result;
// }

// optimizing the above working solution
// keypad
// matrix of 4*3 
// length is n 
// keypad[length][4][3]

// int dpsol(int keypad[][4][3],int n){
    //we have the keyboard 
    //for each length value there is a matrix of size 4*3
    //
    //turning the above recursive approach to tabulation based

//     for(int i=0;i<4;i++){
//         for(int j=0;j<3;j++){
//             keypad[1][i][j]=1;
//         }
//     }
//     keypad[1][3][0]=0;
//     keypad[1][3][2]=0;
//     for(int k=2;k<=n;k++){
//         for(int i=0;i<4;i++){
//             for(int j=0;j<3;j++){
//                 vector<pair<int, int>>dir{{0,-1},{0,1},{-1,0},{1,0},{0,0}};
//                 if (i==3 && (j==0 || j==2)) {
//                     continue;
//                 }
//                 for (auto t : dir) {
//                     // if (i+x.first<0 || i+x.second<0 || j+x.first<0 or j+x.second<0 || (i+x.first==3 && j+x.first==0) || (i+x.first==3 && j+x.first==2)) {
//                     //     continue;
//                     // }
//                     // keypad[k][i][j]+=keypad[k][i+x.first][j+x.second];
//                     int x=i+t.first;
//                     int y=j+t.second;
//                     if (x>=0 && x<4 && y>=0 && y<3) {
//                         keypad[k][i][j]+=keypad[k-1][x][y];//here you only need the last keypad value hence we can opitimize it further
//                     }
//                 }
//             }
//         }
//     }
//     int result=0;
//     for(int i=0;i<4;i++){
//         for(int j=0;j<3;j++){
//             result+=keypad[n][i][j];
//         }
//     }
//     return result;
// }



//further optimizing the solution using two 4*3 matrix 
int dpsol(int n){
    vector<vector<int>>prev(4,vector<int>(3,1));
    prev[3][0]=0;
    prev[3][2]=0;
    vector<vector<int>>curr(4,vector<int>(3));
    vector<pair<int, int>>dir{{0,1},{0,-1},{0,0},{1,0},{-1,0}};
    //now that we have the two matrix
    for(int k=2;k<=n;k++){
        for(int i=0;i<4;i++){
            for(int j=0;j<3;j++){
                curr[i][j]=0;
                if (i==3 && (j==0 || j==2)) {
                    continue;
                }
                for(auto t:dir){
                    int x=i+t.first;
                    int y=j+t.second;
                    if (x>=0 && x<4 && y>=0 && y<3) {
                        curr[i][j]+=prev[x][y];
                    }
                }
            }
        }
        for(int i=0;i<4;i++){
            for(int j=0;j<3;j++){
                prev[i][j]=curr[i][j];
            }
        }
    }
    int result{};
    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            result+=prev[i][j];
        }
    }
    return  result;;
}


int main() {
    std::cout<<"enter the length you want"<<std::endl;
    int length;
    cin>>length;
    int keypad[length+1][4][3];
    memset(keypad, 0, sizeof(keypad));
    // std::cout<<dpsol(keypad, length)<<std::endl;
    std::cout<<dpsol(length)<<std::endl;
}
