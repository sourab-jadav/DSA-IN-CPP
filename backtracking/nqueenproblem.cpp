#include <algorithm>
#include <iostream>
// simple funda is that you have to place n queens
// on n * n board such that they don't  attack each other
#define N 4
bool isFeasible(int arr[][N], int row, int col) {
  int i, j;
  // checking horizontally
  for (int i = 0; i < col; i++) {
    if (arr[row][i] == 1) {
      return false;
    }
  }
  // checking top left diagonally here is where i got stuck
  for (i = row, j = col; i >= 0; i--, j--) {
    if (arr[i][j] == 1) {
      return false;
    }
  }
  // checking bottom left diagonally understand the why i did i-- j-- above and
  // i++ j-- you will get a clear idea if you visualize it from how the array
  // rows and collumns are place and indexing is done (from top left if you
  // consider array as a matrix)
  for (i = row, j = col; i < N && j >= 0; i++, j--) {
    if (arr[i][j] == 1) {
      return false;
    }
  }
  return true;
}
bool NQUtil(int arr[][N], int col) {
  if (col == N) {
    return true;
  }
  for (int i = 0; i < N; i++) {
    if (isFeasible(arr, i, col)) {
      // if it is placable then we place
      arr[i][col] = 1;
      // now check after placing if it giving the desired result
      if (NQUtil(arr, col + 1)) {
        return true;
      }
      arr[i][col] = 0;
    }
  }
  return false;
}
void solveNQ() {
  int arr[][N] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
  NQUtil(arr, 0);
  // to these matrix we have to place n queenc
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      std::cout << arr[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

int main() {
  solveNQ();
  return 0;
}
