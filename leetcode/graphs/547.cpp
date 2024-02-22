#include <iostream>
#include <vector>
// https://leetcode.com/problems/number-of-provinces/
// graphs/dfs_using_matrix.cpp   //also checkout how to do dfs using matrix
using namespace std;
// dfs approach
// class Solution {
// public:
//     void dfs(vector<vector<int>> &isConnected, vector<bool> &visited, int i) {
//     visited[i] = true;
//     for (int j = 0; j < isConnected.size(); j++) {
//       if (isConnected[i][j] == 1 && !visited[j]) {
//         dfs(isConnected, visited, j);
//       }
//     }
//     }
//
//   int findCircleNum(vector<vector<int>> &isConnected) {
//     int n = isConnected.size();
//     vector<bool> visited(n, false);
//     int count = 0;
//     for (int i = 0; i < n; i++) {
//       if (!visited[i]) {
//         dfs(isConnected, visited, i);
//         count++;
//       }
//     }
//     return count;
//   }
// };
// another way of solving is using union find
class Solution {
public:
  int findCircleNum(vector<vector<int>> &isConnected) {
    // another approach is using union operation
    // initially nothing is connected
    int n = isConnected.size();
    vector<int> parent(n, 0);
    for (int i = 0; i < n; i++) {
      parent[i] = i;
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (isConnected[i][j] ==
            1) { // if there is an edge find its ultimate parent
            int p1=findParent(i, parent);
            int p2=findParent(j, parent);
            parent[p2]=p1; // here we are just attaching the nodes
        }
      }
    }
    int count=0;
    for(int i=0;i<n;i++){
        if (parent[i]==i) {
            count++;
        }
    }

    return count;
  }
  // now find parent should return an integer
  int findParent(int node, vector<int> &parent) {
      // what is node it is the ultimate parent
      if (parent[node]==node) {
      return node;
      }
      return parent[node]=findParent(parent[node], parent); // here we are storing the ultimate parent
  }
};
int main() {
  vector<vector<int>> isConnected = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
  Solution s;
  int result= s.findCircleNum(isConnected);
  std::cout<<result<<std::endl;
  // find the ultimate parent of the nodes if they do not match then do count++
  return 0;
}
