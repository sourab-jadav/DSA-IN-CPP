#include <algorithm>
#include <iostream>
#include <vector>
// the ordering the vertices in decreasing orde of their finish time
// reversing all the edges
// for every vertex print the reachable vertex as one strongly connected
// component bool dfs(std::vector<int>vec[],std::vector<bool>visited,int n,int
// s){
//     visited[s]=true;
//     std::cout<<s<<" "; // you are stuck at verifying a node can form a cycle
//     or not for (int x : vec[s]) {
//         if (visited[x]==false) {
//             return dfs(vec, visited, n, x);
//         }else {
//             return true;
//         }
//     }
//     return false;
// }

// one problem i am facing here
// in ordering the vertices in the decreasing order of their finish time
void dfs(std::vector<int> vec[], std::vector<bool> visited, int n, int s,
         int &count, std::vector<int> &dist) {
  visited[s] = true;
  std::cout << s
            << " "; // you are stuck at verifying a node can form a cycle or not
  for (int x : vec[s]) {
    count++;
    if (visited[x] == false) {
      dfs(vec, visited, n, x, count, dist);
    }
  }
  count++;
  dist[s] = count;
}

void addEdge(std::vector<int> vec[], int u, int v) { vec[u].push_back(v); }
void createGraph(std::vector<std::vector<int>> graph, std::vector<int> vec[]) {
  int n = (int)graph.size();
  for (int i = 0; i < n; i++) {
    addEdge(vec, graph[i][0], graph[i][1]);
  }
}

int main() {
  // trying to work on kosaraju's algorithm
  std::vector<std::vector<int>> graph{// {0,1},{2,1},{2,3},{3,4},{4,5},{5,4}
                                      // {0,1},{1,2},{2,3},{3,0}
                                      {0, 1},
                                      {1, 2},
                                      {2, 0},
                                      {1, 3},
                                      {3, 4}};
  int n = graph.size();
  std::vector<int> vec[n];
  std::vector<bool> visited(n, false);
  createGraph(graph, vec);
  vec[3].erase(std::find(vec[3].begin(), vec[3].end(), 4));
  std::vector<int> dist(n, 0);

  int count = 0;
  dfs(vec, visited, n, 0, count, dist);
  std::cout << std::endl;
  for (auto x : dist) {
    std::cout << x << " ";
  }
  std::cout << std::endl;
  return 0;
}
