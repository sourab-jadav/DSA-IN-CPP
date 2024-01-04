#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
// https://www.notion.so/graphs-76ef1794d0084e85b4cf58288e6e0cfc?pvs=4#bb286a0f9d6d40498505b3d63e31938c
// making use of adjacency list with with weights
void printMST(std::vector<std::vector<int>> adj[], int V) {
    // creating a priority queuewhich stores the pairs in the ascending order of
    // their weight
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
        std::greater<std::pair<int, int>>>
            pq;
    std::vector<bool> visited(V, false);
    pq.push({0, 0});
    int total = 0;
    while (!pq.empty()) {
        auto el = pq.top();
        pq.pop();
        int node = el.second;
        int weight = el.first;
        if (visited[node])
            continue;
        visited[node] = true;
        total += weight;
        for (auto x : adj[node]) {
            // now traversing all the reachable nodes from here
            int adjNode = x[0];
            int adW = x[1];
            if (!visited[adjNode]) { // you did x[1]
                pq.push({adW, adjNode});
            }
        }
    }
    std::cout << total << std::endl;
}
int main() {
    // creating a graph with the s,d,w of vectors and pushing it to the pq in
    // creating min heap based on their weight
    int V = 5;
    std::vector<std::vector<int>> edges = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1},
        {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};
    // first document the process
    //
    //
    // construct the priority queue from the edges
    // traversing the edges and pushing the edges and associating source and
    // destination of each edge with their weight and pushing it to the pq mapping
    // source ,dest to their associated weights and forming adjacency list
    std::vector<std::vector<int>> adj[V];
    for (auto x : edges) {
        std::vector<int> temp(2);
        temp[0] = x[1];
        temp[1] = x[2];
        adj[x[0]].push_back(temp); // you went wrong here very badly
        temp[0] = x[0];
        temp[1] = x[2];
        adj[x[1]].push_back(temp);
    }
    std::cout << "end printing the temps" << std::endl;
    printMST(adj, V);
    return 0;
}
