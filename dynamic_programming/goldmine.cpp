#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define printxyz(arr, rows, cols)                                              \
  do {                                                                         \
    std::cout << std::endl;                                                    \
    for (int i = 0; i < rows; ++i) {                                           \
      for (int j = 0; j < cols; ++j) {                                         \
        std::cout << arr[i][j] << " ";                                         \
      }                                                                        \
      std::cout << std::endl;                                                  \
    }                                                                          \
    std::cout << std::endl;                                                    \
  } while (0)

// solving the problem using the recursive approach
// the constraints we can move
// toward right
// towards right and up
// towards right and down
int solve(vector<vector<int>>&vec,int i,int j){
    // if (i<0 or j<0 or i>=vec.size() or j>=vec[0].size()) {
    //     return 0;
    // }

    if (i<0 or i==vec.size() or j==vec[0].size()) {
        return 0;
    }


    return vec[i][j]+max(max(solve(vec, i+1, j+1),solve(vec, i-1, j+1)),solve(vec, i, j+1));
}


int main() {
  // vector<vector<int>>vec{{1, 3, 3},
  //                       {2, 1, 4},
  //                       {0, 6, 4}};
  // get the max value for the first column
vector<vector<int>>vec{ {1, 3, 1, 5},
                      {2, 2, 4, 1},
                      {5, 0, 2, 3},
                      {0, 6, 1, 2}};
  int j=0;
  int k=0;
  int value=INT_MIN;
  int rows=vec.size();
  int cols=vec[0].size();
  // moving through all the rows of the first column and get the max value
  for(int i=0;i<rows;i++){
      if (vec[i][0]>value) {
        value=vec[i][0];
        j=i;
      }
  }
  std::cout<<solve(vec, j, k)<<std::endl;
  return 0;
}
