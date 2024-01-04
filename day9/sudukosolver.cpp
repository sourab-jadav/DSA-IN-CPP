#include <cstdio>
#include <iostream>
#include <vector>
void printBoard(std::vector<std::vector<char>> &board) {
  for (auto &x : board) {
    for (auto &val : x) {
      std::cout << val << " ";
    }
    std::cout << std::endl;
  }
}

bool isFeasible(std::vector<std::vector<char>> &board, char val, int row,
                int col) {
  for (int i = 0; i < 9; i++) {
    if (board[row][i] == val) {
      return false;
    }
    if (board[i][col] == val) {
      return false;
    }
    // this is where i got stuck can't figure out a way to search in it's
    // appropriate 3*3 matrix
    if (board[3 * (row / 3) + i % 3][3 * (col / 3) + i % 3] == val) {
      return false;
    }
  }
  return true;
}

bool solveSuduko(std::vector<std::vector<char>> &board) {

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (board[i][j] == '.') {
        for (char c = '1'; c <= '9'; c++) {//good thought here
          if (isFeasible(board, c, i, j)) {
            board[i][j] = c;
            if (solveSuduko(board)) {
              return true;
            } else {
              board[i][j] = '.';
            }
          }
        }
        return false;
      }
    }
  }
  return true;
}

int main() {
  std::cout << "Hello, World!" << std::endl;
  std::vector<std::vector<char>> board{
      {'9', '5', '7', '.', '1', '3', '.', '8', '4'},
      {'4', '8', '3', '.', '5', '7', '1', '.', '6'},
      {'.', '1', '2', '.', '4', '9', '5', '3', '7'},
      {'1', '7', '.', '3', '.', '4', '9', '.', '2'},
      {'5', '.', '4', '9', '7', '.', '3', '6', '.'},
      {'3', '.', '9', '5', '.', '8', '7', '.', '1'},
      {'8', '4', '5', '7', '9', '.', '6', '1', '3'},
      {'.', '9', '1', '.', '3', '6', '.', '7', '5'},
      {'7', '.', '6', '1', '8', '5', '4', '.', '9'}};
  solveSuduko(board);
  printBoard(board);
  return 0;
}
