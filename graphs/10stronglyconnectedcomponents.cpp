#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// logic here
// first document what you think and then start coding
// we are given edges and number of vertices we can construct adj list
//
// we need dfs to check if there is a path from u to v
//
// two vertices will form strongly connected component if there is a path from u
// to v and there is a path from v to u
//
// we need visited array to keep track of visited nodes
//
// here your idea is
//  from u=1 to u=5
//      if that u is not visited ()
//          push that u into the ans
//          look for all the possible paths v from u (or) we should travel from
//          v=1 to v=5;  // here in sol v is starting from u+1
//                      //  if i do 1 to 2 in first iteration you don't need to
//                      check
//                      //  2 to 1 in the second iteration so you start from u+1
//          now you have to check dfs from u to v and and v to u where u!=v
//          if satisfied push that v into the answer
//
//  all set !!
bool checkpath(vector<vector<int>> &adj, int u, int v, vector<bool> &visited) {
    // if (visited[s]==true) {
    //     return true;
    // }
    // visited[s]=true;
    // for (int x : adj[s]) {
    //     if (checkpath(adj, x, visited)==true) { // it will travel visited also and return true
    //         return true;
    //     }
    // }
    // return false;
    if (u == v) {
        return true;
    }
    visited[u] = true;
    for (auto &x : adj[u]) {
        // only move to x if it is not visited
        if (!visited[x]) {
            if (checkpath(adj, x, v, visited)) {
                return true;
            }
        }
    }
    return false;
}
bool isPath(vector<vector<int>> &adj, int u, int v) {
    vector<bool> visited(adj.size() + 1, false);
    return checkpath(adj, u, v, visited);
}
void findStronglyConnectedComponents(vector<vector<int>> &edges, int v) {}
int main() {
    // you are given edges and vertices
    int v = 5;
    vector<vector<int>> edges{{1, 3}, {1, 4}, {2, 1}, {3, 2}, {4, 5}};
    vector<vector<int>> adj(v + 1);
    // creating graphs from edges
    for (int i = 0; i < (int)edges.size(); i++) {
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    vector<bool> is_scc(v + 1, false);
    vector<vector<int>> ans;
    for (int i = 1; i <= v; i++) {
        if (!is_scc[i]) {
            vector<int> scc;
            scc.push_back(i);
            for (int j = i + 1; j <= v; j++) {
                if (!is_scc[j] && isPath(adj, i, j) && isPath(adj, j, i)) {
                    is_scc[j] = 1;
                    scc.push_back(j);
                }
            }
            ans.push_back(scc);
        }
    }
    for (auto &x : ans) {
        for (auto &y : x) {
            std::cout<<y<<" ";
        }
        std::cout<<std::endl;
    }
    return 0;
}
