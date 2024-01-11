#include <climits>
#include <iostream>
#include <utility>
#include <vector>

int main() {
  // Given a weighted, undirected, and connected graph of V vertices and an
  // adjacency list adj where adj[i] is a list of lists containing two integers
  // where the first integer of each list j denotes there is an edge between i
  // and j, second integers corresponds to the weight of that edge. Return an
  // array of length V, where each element is the sum of the distances between
  // node i and all other nodes. Example 1: Input: V = 6, adj =
  // [[1,4],[2,4],[0,4],[4,3],[3,1],[5,2]] Output: [8,8,4,4,4,4] Explanation:
  // The distance from 0th node to other nodes are: [8,8,4,4,4,4] Example 2:
  // Input: V = 1, adj = [[]]
  // Output: [0]
  // Explanation: There is only one node in the graph, so the distance from 0th
  // node to other nodes is just [0] Constraints: 1 <= V <= 104 0 <= adj[i][j]
  // <= 1000 1 <= adj[i].size() <= V - 1 It is guaranteed that the graph is
  // connected and all edges are of length 1.
  std::vector<std::vector<int>> vec = {{0, 1, 1}, {1, 2, 3}, {2, 0, 6}};
  int n = vec.size();
  std::vector<int> dist(n, INT_MAX);
  dist[2] = 0;
  std::vector<std::pair<int, int>> adj[n];
  // here the source vertex is 0
  for (int i = 0; i < n; i++) {
    adj[vec[i][0]].push_back({vec[i][1], vec[i][2]});
    adj[vec[i][1]].push_back({vec[i][0], vec[i][2]});
  }
  for (int i = 0; i < n - 1; i++) { // it is possible that there is no path from
    // source to destination so we have to run the
    // loop n-1 times
    for (int i = 0; i < n; i++) { // traversing through all the edges
      for (auto it : adj[i]) {
        if (dist[i] != INT_MAX && dist[i] + it.second < dist[it.first]) {
          dist[it.first] = dist[i] + it.second;
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    std::cout << dist[i] << " ";
  }
  return 0;
}

// the above code is the solution for the problem
// the below code is the solution for the problem using priority queue
// #include <bits/stdc++.h>
// using namespace std;
// int main() {
//  int n = 3;
//  vector<vector<int>> vec = {{0, 1, 1}, {1, 2, 3}, {2, 0, 6}};
//  vector<pair<int, int>> adj[n];
//  for (int i = 0; i < n; i++) {
//  adj[vec[i][0]].push_back({vec[i][1], vec[i][2]});
//  adj[vec[i][1]].push_back({vec[i][0], vec[i][2]});
//  }
//  vector<int> dist(n, INT_MAX);
//  priority_queue<pair<int, int>, vector<pair<int, int>>,
//  greater<pair<int, int>>> pq;
//  pq.push({0, 2});
//  dist[2] = 0;
//  while (!pq.empty()) {
//  int node = pq.top().second;
//  int nodeDist = pq.top().first;
//  pq.pop();
//  for (auto it : adj[node]) {
//  if (nodeDist + it.second < dist[it.first]) {
//  dist[it.first] = nodeDist + it.second;
//  pq.push({dist[it.first], it.first});
//  }
//  }
//  }
//  for (int i = 0; i < n; i++) {
//  cout << dist[i] << " ";
//  }
//  return 0;
//  }
//  the above code is the solution for the problem using priority queue

//  the below code is the solution for the problem using bfs
//  #include <bits/stdc++.h>
//  using namespace std;
//  int main() {
//  int n = 3;
//  vector<vector<int>> vec = {{0, 1, 1}, {1, 2, 3}, {2, 0, 6}};
//  vector<pair<int, int>> adj[n];
//  for (int i = 0; i < n; i++) {
//  adj[vec[i][0]].push_back({vec[i][1], vec[i][2]});
//  adj[vec[i][1]].push_back({vec[i][0], vec[i][2]});
//  }
//  vector<int> dist(n, INT_MAX);
//  queue<pair<int, int>> q;
//  q.push({0, 2});
//  dist[2] = 0;
//  while (!q.empty()) {
//  int node = q.front().second;
//  int nodeDist = q.front().first;
//  q.pop();
//  for (auto it : adj[node]) {
//  if (nodeDist + it.second < dist[it.first]) {
//  dist[it.first] = nodeDist + it.second;
//  q.push({dist[it.first], it.first});
//  }
//  }
//  }
//  for (int i = 0; i < n; i++) {
//  cout << dist[i] << " ";
//  }
//  return 0;
//  }

//  the above code is the solution for the problem using bfs
//  the below code is the solution for the problem using dfs
//  #include <bits/stdc++.h>
//  using namespace std;
//  void dfs(int node, int nodeDist, vector<int> &dist,
//  vector<pair<int, int>> adj[]) {
//  dist[node] = nodeDist;
//  for (auto it : adj[node]) {
//  if (nodeDist + it.second < dist[it.first]) {
//  dfs(it.first, nodeDist + it.second, dist, adj);
//  }
//  }
//  }
//  int main() {
//  int n = 3;
//  vector<vector<int>> vec = {{0, 1, 1}, {1, 2, 3}, {2, 0, 6}};
//  vector<pair<int, int>> adj[n];
//  for (int i = 0; i < n; i++) {
//  adj[vec[i][0]].push_back({vec[i][1], vec[i][2]});
//  adj[vec[i][1]].push_back({vec[i][0], vec[i][2]});
//  }
//  vector<int> dist(n, INT_MAX);
//  dfs(2, 0, dist, adj);
//  for (int i = 0; i < n; i++) {
//  cout << dist[i] << " ";
//  }
//  return 0;
//  }
//  the above code is the solution for the problem using dfs
