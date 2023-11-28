#include <cstring>
#include <iostream>
// we will be discussing knights tour problem
// how do we approach a backtracking problem
// let's start with taking an example
// knight's tour problem
//
// we have a chess board knight is a 0 0
// it want to travel the overall chess board 8*8
// i want you to print the path
//
//
// backtracking approach can be trying out each and every path
// if the path is not feasable leave it there and try another path
#define N 8
void printUtil(int arr[N][N]) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      std::cout << arr[i][j] << " ";
    }
    std::cout << std::endl;
  }
}
int isFeasible(int currentX, int currentY, int arr[N][N]) {
  if ((currentX >= 0 && currentX < N) && (currentY >= 0 && currentY < N) &&
      arr[currentX][currentY] == -1) {
    return 1;
  } else {
    return -1;
  }
}

int solveKT(int arr[N][N], int xMove[], int yMove[], int current_x,
            int current_y, int move_num) {
  int next_x;
  int next_y;
  if (move_num == N * N) {
    return 1;
  }
  for (int i = 0; i < N; i++) {
    next_x = current_x + xMove[i]; // u got stuck here actually u need one more
                                   // variable next_x and next_y
    next_y = current_y + yMove[i];
    if (isFeasible(next_x, next_y, arr) == 1) {
      arr[next_x][next_y] = move_num;
      // now if this recursive path with the current x and current y works then
      if (solveKT(arr, xMove, yMove, next_x, next_y, move_num + 1) == 1) {
        return 1;
      } else {
        arr[next_x][next_y] = -1;
      }
    }
  }
  return -1;
}

void solveKUtil() {
  int arr[8][8];
  memset(arr, -1, sizeof(arr));
  int xMove[8] = {2, 1, -1, -2, -2, -1, 1, 2};
  int yMove[8] = {1, 2, 2, 1, -1, -2, -2, -1};
  int result = solveKT(arr, xMove, yMove, 0, 0, 1);
  if (result == 1) {
    printUtil(arr);
  } else {
    std::cout << "solution cannot be found" << std::endl;
  }
}

int main() {
  solveKUtil();
  return 0;
}
