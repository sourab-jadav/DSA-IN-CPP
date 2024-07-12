#include <climits>
#include <iostream>
#include <utility>
#include <vector>
// all the below described approaches are working !!!
// some noteworthy points before solving this problem
// max no. of edges possible if every node is connected to every other node
// total undirected connections =n*(n-1); total edges = n*(n-1)/2
//
// in undirected acyclic graph : vertices= edges +1;
// no. of vertices will always be subset of edges+1;
//
// here the first for loop which is repeating no_of_vertices-1 times:
//      -> each time in worst case it will find minimum distance between any two
//      vertices starting from the source vertices who's distance is 0 since
//      source distance is already calculated we traverse no_of_vertices -1 time
//      to get the distance of remaining vertices
//
//  the inner for loop
//  it takes i as the source vertex and traverse through all the edges(towards
//  it(say j)) possible from it
//     calculates min(dist[j],dist[s]+weight[j])
//
int main() { // this is correct and working solution (brute force) for the problem
  std::vector<std::vector<int>> vec = {{0, 1, 1}, {1, 2, 3}, {2, 0, 6}};
  int edges=vec.size();
  int no_of_vertices = 3;
  std::vector<int> dist(no_of_vertices, INT_MAX);
  dist[2] = 0;
  std::vector<std::pair<int, int>> adj[no_of_vertices];
  // here the source vertex is 0
  for (int i = 0; i < edges; i++) {
    adj[vec[i][0]].push_back({vec[i][1], vec[i][2]});
    adj[vec[i][1]].push_back({vec[i][0], vec[i][2]});
  }
  for (int j = 0; j < no_of_vertices - 1; j++) {
    for (int i = 0; i < no_of_vertices; i++) {
      for (auto it : adj[i]) {// traversing through all the edges
        if (dist[i] != INT_MAX && dist[i] + it.second < dist[it.first]) {
          dist[it.first] = dist[i] + it.second;
        }
      }
    }
  }
  for (int i = 0; i < no_of_vertices; i++) {
    std::cout << dist[i] << " ";
  }
  return 0;
}

// // the above code is the solution for the problem
// // the below code is the solution for the problem using priority queue
// #include <bits/stdc++.h>
// using namespace std;
// int main() {
//   int n = 3;
//   vector<vector<int>> vec = {{0, 1, 1}, {1, 2, 3}, {2, 0, 6}};
//   vector<pair<int, int>> adj[n];
//   for (int i = 0; i < n; i++) {
//     adj[vec[i][0]].push_back({vec[i][1], vec[i][2]});
//     adj[vec[i][1]].push_back({vec[i][0], vec[i][2]});
//   }
//   vector<int> dist(n, INT_MAX);
//   priority_queue<pair<int, int>, vector<pair<int, int>>,
//                  greater<pair<int, int>>>
//       pq;
//   // here the priority queue is min heap(based on first element of
//   // pair(default)) because of greater function
//   pq.push({0, 2});
//   dist[2] = 0;
//   while (!pq.empty()) {
//     int node = pq.top().second;
//     int nodeDist = pq.top().first;
//     pq.pop();
//     for (auto it : adj[node]) {
//       if (nodeDist + it.second < dist[it.first]) {
//         dist[it.first] = nodeDist + it.second;
//         pq.push({dist[it.first], it.first});
//       }
//     }
//   }
//   for (int i = 0; i < n; i++) {
//     cout << dist[i] << " ";
//   }
//   return 0;
// }

// the above code is the solution for the problem using priority queue

//  the below code is the solution for the problem using bfs
// #include <bits/stdc++.h>
// using namespace std;
// int main() {
//   int n = 3;
//   vector<vector<int>> vec = {{0, 1, 1}, {1, 2, 3}, {2, 0, 6}};
//   vector<pair<int, int>> adj[n];
//   for (int i = 0; i < n; i++) {
//     adj[vec[i][0]].push_back({vec[i][1], vec[i][2]});
//     adj[vec[i][1]].push_back({vec[i][0], vec[i][2]});
//   }
//   vector<int> dist(n, INT_MAX);
//   queue<pair<int, int>> q;
//   q.push({0, 2});
//   dist[2] = 0;
//   while (!q.empty()) {
//     int node = q.front().second;
//     int nodeDist = q.front().first;
//     q.pop();
//     for (auto it : adj[node]) {
//       if (nodeDist + it.second < dist[it.first]) {
//         dist[it.first] = nodeDist + it.second;
//         q.push({dist[it.first], it.first});
//       }
//     }
//   }
//   for (int i = 0; i < n; i++) {
//     cout << dist[i] << " ";
//   }
//   return 0;
// }
//
//  the above code is the solution for the problem using bfs
//  the below code is the solution for the problem using dfs
// #include <bits/stdc++.h>
// using namespace std;
// void dfs(int node, int nodeDist, vector<int> &dist,
//         vector<pair<int, int>> adj[]) {
//     dist[node] = nodeDist;
//     for (auto it : adj[node]) {
//         if (nodeDist + it.second < dist[it.first]) {
//             dfs(it.first, nodeDist + it.second, dist, adj);
//         }
//     }
// }
// int main() {
//     int n = 3;
//     vector<vector<int>> vec = {{0, 1, 1}, {1, 2, 3}, {2, 0, 6}};
//     vector<pair<int, int>> adj[n];
//     for (int i = 0; i < n; i++) {
//         adj[vec[i][0]].push_back({vec[i][1], vec[i][2]});
//         adj[vec[i][1]].push_back({vec[i][0], vec[i][2]});
//     }
//     vector<int> dist(n, INT_MAX);
//     dfs(2, 0, dist, adj);
//     for (int i = 0; i < n; i++) {
//         cout << dist[i] << " ";
//     }
//     return 0;
// }
//  the above code is the solution for the problem using dfs
