#include <iostream>
#include <queue>
#include <utility>
#include <vector>
// you are given a undirected graph with weights you need to find minimum spanning tree of the graph
// minimum spanning tree is the tree which connects all the vertices with minimum weight
// here we need to know the number of vertices
void printMst(int V, std::vector<std::pair<int, int>> vec[]) {
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    pq.push({0, 0});
    std::vector<bool> visited(V, false);
    int mstWeight = 0;
    while (!pq.empty()) {
        std::pair<int, int> p = pq.top();
        pq.pop();
        int x = p.second;
        if (visited[x] == true) {
            continue;
        }
        visited[x] = true;
        mstWeight += p.first;
        for (auto it : vec[x]) {
            if (visited[it.first] == false) {
                pq.push({it.second, it.first});
            }
        }
    }
    std::cout<<mstWeight<<std::endl;
}
int main() {
    int V = 5;
    std::vector<std::vector<int>> graph{{0, 1, 2}, {0, 3, 6}, {1, 2, 3}, {1, 3, 8}, {1, 4, 5}, {4, 2, 7}};

    // create a graph out of it using adjacency list

    std::vector<std::pair<int, int>>adj[V];
    //we also need weights so create a vector of pairs
    for (auto x : graph) {
        std::pair<int, int>p1;
        // first element is the value is source pointing to 
        // second element is the weight
        // we need to add the edge in both the directions
        // as it is an undirected graph
        // first element is the source
        // second element is the destination
        // third element is the weight
        adj[x[0]].push_back({x[1], x[2]});
        adj[x[1]].push_back({x[0], x[2]});
        // or
    }
    printMst(V, adj);
    return 0;
}
