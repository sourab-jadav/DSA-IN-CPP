#include <algorithm>
#include <climits>
#include <cstdlib>
#include <cstring>
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

//https://www.geeksforgeeks.org/optimal-binary-search-tree-dp-24/
// identifying the subproblems before solving this question
// the question is you are given two arrays 
// freq array and key array (in ascending order)
// your task is to compute the minimum cost
// cost is defined as the the sum of product of freq of the key value and it's depth in the original binary search tree
//
// for the cost to be minimum the cost of the subtrees should be minimum 
// the idea is for a given sub array from r=i to j make the key at r as root 
// and recurse for the left subtree of the root and find the minimum cost 
// and recur for the right subtree of the root and find the minimum cost
// add the minimum cost of the left subtree and the right subtree and compare with the current minimum
// this approach is only possible if the key array is sorted!!!
int sumthis(int freq[],int i,int j){
    int sum=0;
    for(int k=i;k<=j;k++){
        sum+=freq[k];
    }
    return sum;
}
// int optCost(int freq[],int i,int j){
//     if (j<i) {
//         return 0;
//     }
//     if (i==j) {
//         return freq[i];
//     }
//     int fsum=sumthis(freq,i,j);
//     int current_cost=INT_MAX;
//     for(int r=i;r<=j;r++){
//         int cost=optCost(freq, i, r-1)+optCost(freq, r+1, j);
//         if (cost<current_cost) {
//             current_cost=cost;
//         }
//     }
//     return current_cost+fsum;
// }
// int optimalSearchTree(int keys[],int fre[],int n){
//     return optCost(fre, 0, n-1);
// }

int optCost(int freq[],int n){ // not working 
    int cost[n][n];
    memset(cost, 0, sizeof(cost));
    for(int i=0;i<n;i++){
        cost[i][i]=freq[i];
    } // done with the base values i.e gap=0
      // dynamic_programming/optimal_strategy_for_game.cpp // tabulation reference
    // for(int gap=1;gap<n;gap++){ // working approach
    //     for(int i=0,j=gap;j<n;i++,j++){
    //         cost[i][j]=INT_MAX;
    //         int offset_sum=sumthis(freq, i, j);
    //         for(int r=i;r<=j;r++){
    //             int x=(r-1>=0)?cost[i][r-1]:0;
    //             int y=(r+1<n)?cost[r+1][j]:0;
    //             cost[i][j]=min(cost[i][j],x+y+offset_sum);
    //         }
    //     }
    // }
    // or you can also use concept of length
    // i.e solving the all the subproblems of len 2,3 and so on

    for(int l=2;l<=n;l++){ 
        for(int i=0;i<=n-l+1;i++){
            int j=i+l-1;
            // we have our i and j set 
            cost[i][j]=INT_MAX;
            int offset_sum=sumthis(freq, i, j);
            for(int r=i;r<=j;r++){
                int x=(r>i)?cost[i][r-1]:0; // here (r>i) is more intuitive than using (r-1>=0) as used above
                int y=(r<j)?cost[r+1][j]:0;
                cost[i][j]=min(cost[i][j],x+y+offset_sum);
            }
        }
    }

    return cost[0][n-1];
}
int main() {
    int keys[] = {10, 12, 20}; 
    int freq[] = {34, 8, 50}; 
    int n = sizeof(keys) / sizeof(keys[0]); 
    // cout << "Cost of Optimal BST is "
    //      << optimalSearchTree(keys, freq, n); 
    std::cout<<optCost(freq, n)<<std::endl;
    return 0;
}
