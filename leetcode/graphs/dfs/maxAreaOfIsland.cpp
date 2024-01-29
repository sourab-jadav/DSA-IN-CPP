#include <iostream>
#include <vector>
using namespace std;
// https://leetcode.com/problems/max-area-of-island/description
// /// the solution is straightforward,dfs 
class Solution {
public:
    int findAread(vector<vector<int>>&graph,int i,int j ){
        // standard base case to traverse safely
        if (i>=0 and i<graph.size() and j>=0 and j<graph[0].size() and graph[i][j]==1) {
            graph[i][j]=0;
            return 1+findAread(graph, i+1, j)+findAread(graph, i, j+1)+findAread(graph, i-1, j)+findAread(graph, i, j-1);
        }
        return 0;
    }
  int maxAreaOfIsland(vector<vector<int>> &grid) {
      int result{};
      for(int i=0;i<grid.size();i++){
          for(int j=0;j<grid[0].size();j++){
              if (grid[i][j]==1) {
                  result=max(result,findAread(grid, i, j));
              }
          }
      }
      return result;
  }
};
int main() {
  Solution s;
  vector<vector<int>> grid{{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                           {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
                           {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
  std::cout << s.maxAreaOfIsland(grid) << std::endl;
  return 0;
}
