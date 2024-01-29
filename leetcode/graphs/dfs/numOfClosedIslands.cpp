#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool dfs(vector<vector<int>>&grid,int i,int j){
        // now traverse throuh all the edges from here
        // first avoid the oveflow
            if (i<0 or j<0 or i>=grid.size() or j>=grid[0].size()) {
                return false;
            }
            // at any direction if you get one then return true there
            if (grid[i][j]==1) {
                return true;
            }

            grid[i][j]=1;
            bool d1=dfs(grid, i+1, j);
            bool d2=dfs(grid, i-1, j);
            bool d3=dfs(grid, i, j+1);
            bool d4=dfs(grid, i, j-1);
            return d1&& d2&& d3&& d4;
    }
  int closedIsland(vector<vector<int>> &grid) {
      // the ideais to find the number of islands of 0 surroundided by 1

      int n=grid.size();
      int m=grid[0].size();
      int result{};

      for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
              if (grid[i][j]==0) {
                  result+=dfs(grid,i,j)?1:0;
              }
          }
      }
      return result;

  }
};

int main() {
  vector<vector<int>> grid = {{1, 1, 1, 1, 1, 1, 1, 0},
                              {1, 0, 0, 0, 0, 1, 1, 0},
                              {1, 0, 1, 0, 1, 1, 1, 0},
                              {1, 0, 0, 0, 0, 1, 0, 1},
                              {1, 1, 1, 1, 1, 1, 1, 0}};
  Solution s;
  int result=s.closedIsland(grid);
  std::cout<<result<<std::endl;
  return 0;
}
