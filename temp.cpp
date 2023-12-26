#include <iostream>
#include <utility>
#include <vector>
#define N 4
using namespace std;

// function that prints the array
// board[N][N]
// how would you write the print function
// tranverse through the board if the value is defined the print q else print .
void printBoard(int board[N][N]) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (board[i][j])
        cout << "Q ";
      else
        cout << ". ";
    }
    cout << endl;
  }
}
// define the issafe function which will tell if placing the queen is valid or
// not

bool issafe(int board[N][N], int x, int y) {
  // as we are placing columnwise we need to check
  // left side of the row
  // left top diagonal
  // left bottom diagonal

  for (int i = 0; i < x; i++) {
    if (board[x][i]) {
      return false;
    }
  }
  // checking the left top row
  for (int i = x, j = y; i >= 0 && j >= 0; i--, j--) {
    if (board[i][j]) {
      return false;
    }
  }
  // checking the lower diagonal if it satisfies
  for (int i = x, j = y; i < N && j >= 0; i++, j--) {
    if (board[i][j]) {
      return false;
    }
  }
  return true;
}

int main() {}
