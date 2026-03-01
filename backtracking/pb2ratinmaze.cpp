#include <iostream>
#include <string>
#include <vector>
#define N 4

// Consider a rat placed at (0, 0) in a square matrix of order N * N. It has
// to reach the destination at (N – 1, N – 1). Find all possible paths that
// the rat can take to reach from source to destination. The directions in w
// hich the rat can move are ‘U'(up), ‘D'(down), ‘L’ (left), ‘R’ (right). Va
// lue 0 at a cell in the matrix represents that it is blocked and rat canno
// t move to it while value 1 at a cell in the matrix represents that rat ca
// n be travel through it. Return the list of paths in lexicographically
// increasing order. Note: In a path, no cell can be visited more than one time.
// If the source cell is 0, the rat cannot move to any other cell.

int dr[4] = {1, 0, 0, -1};
int dc[4] = {0, -1, 1, 0};
std::string direction = "DLRU";
std::vector<std::string> result;

int isFeasible(int x, int y, std::vector<std::vector<int>> arr) {
  if (x >= 0 && x < N && y >= 0 && y < N && arr[x][y] == 1) {
    return 1;
  }
  return -1;
}

void solveRatInMaze(std::vector<std::vector<int>> maze, std::string curr,
                    int xmove, int ymove) {
  if (xmove == N-1 && ymove == N-1) {
    result.push_back(curr);
    return;
  }
  maze[xmove][ymove]=0;//this is where you got stuck think why you used this line
  
  for (int i = 0; i < 4; i++) {
    int next_dr = xmove + dr[i];
    int next_dc = ymove + dc[i];
    if (isFeasible(next_dr, next_dc, maze) == 1) {
      curr += direction[i];
      solveRatInMaze(maze, curr, next_dr, next_dc);
      curr.pop_back();
    }
  }
  maze[xmove][ymove]=1;
}

int main() {
  std::vector<std::vector<int>> maze = {
      {1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
  std::vector<char> path;
  std::string curr = "";
  solveRatInMaze(maze, curr, 0, 0);
  for (auto &x : result) {
    std::cout << x << " ";
  }
  return 0;
}
