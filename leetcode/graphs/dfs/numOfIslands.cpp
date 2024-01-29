#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void dfs(vector<vector<char>>&graph,int i,int j){
        if (i<0 or j<0 or i>=graph.size() or j>=graph[0].size()) {
            return;
        }
        if (graph[i][j]=='0') {
            return;
        }
        graph[i][j]='0';
        if (i+1<graph.size()) {
            dfs(graph, i+1, j);
        }
        if (j+1<graph[0].size()) {
            dfs(graph, i, j+1);
        }
        if (i-1 >=0) {
            dfs(graph, i-1, j);
        }
        if (j-1>=0) {
            dfs(graph, i, j-1);
        } // you don't need multiple if's here you are already handling that in the first if condition
    }
  int numIslands(vector<vector<char>> &grid) {
      int n=grid.size();
      int m=grid[0].size();
      int result{};
      for(int i=0;i<n;i++){
          for(int j=0;j<m;j++){
              if (grid[i][j]=='1') {
                  dfs(grid, i, j);
                  result++;
              }
          }
      }
      return result;
  }
};
int main() {
  vector<vector<char>> grid = {{'1', '1', '0', '0', '0'},
                               {'1', '1', '0', '0', '0'},
                               {'0', '0', '1', '0', '0'},
                               {'0', '0', '0', '1', '1'}};

  Solution s;
  int result=s.numIslands(grid);
  std::cout<<result<<std::endl;
  // return the number of islands
  // 1 is land and 0 is water
  return 0;
}
