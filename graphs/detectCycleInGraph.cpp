#include <climits>
#include <cstdint>
#include <iostream>
#include <queue>
#include <vector>
// detecting cycle in undirected graph
// bool dfs(std::vector<int> vec[], std::vector<bool> visited, int n, int s) {
//     visited[s] = true;
//     std::cout << s << " ";
//     for (int x : vec[s]) {
//         if (visited[x] == false) {
//             if (dfs(vec, visited, n, x) == true) {
//                 return true;
//             }
//         } else if (x != s) {
//             return true;
//         }
//     }
//     return false;
// }
// void addEdge(std::vector<int> vec[], int u, int v) {
//     vec[u].push_back(v);
//     vec[v].push_back(u);
// }
// void createGraph(std::vector<std::vector<int>> graph, std::vector<int> vec[]) {
//     int n = (int)graph.size();
//     for (int i = 0; i < n; i++) {
//         addEdge(vec, graph[i][0], graph[i][1]);
//     }
// }
//


//detecting cycle in directed graph
// you can only solve dfs related questions only on how well you understood the technique
bool dfs(std::vector<int> vec[], std::vector<bool> visited ,std::vector<bool>recstk, int s) {
    visited[s]=true;
    recstk[s]=true;
    for (auto x : vec[s]) {
        if (visited[x]==false && dfs(vec, visited, recstk, x)) { // it is not s it is x
            return true;
        }
        else if(recstk[x]==true){
            return true;
        }
    }
    recstk[s]=false; // this means the cycle is not formed and we are closing the recursion stack
    return false;

}
void addEdge(std::vector<int> vec[], int u, int v) {
    vec[u].push_back(v);
}
void createGraph(std::vector<std::vector<int>> graph, std::vector<int> vec[]) {
    int n = (int)graph.size();
    for (int i = 0; i < n; i++) {
        addEdge(vec, graph[i][0], graph[i][1]);
    }
}
//
int main() {
    std::vector<std::vector<int>> graph{
        {0,1},{2,1},{2,3},{3,4},{4,5},{5,4}
        // {0,1},{1,2},{2,3},{3,0}
    };
    int n = graph.size();
    std::vector<int> vec[n];
    createGraph(graph, vec);
    std::vector<bool> visited(n, false);
    std::vector<bool> recstk(n, false);
    bool result = dfs(vec, visited,recstk, 0);
    if (result) {
        std::cout << "cycle is detected" << std::endl;
    }else {
        std::cout<<"cycle is not detected"<<std::endl;
    }
    return 0;
}
