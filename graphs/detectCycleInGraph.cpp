#include <climits>
#include <bits/stdc++.h>
#include <cstdint>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// detecting cycle in undirected graph using dfs
//
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


//detecting cycle in directed graph using dfs
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
// detecting cycle in indirected graph using bfs 
// the logic is similar use the bfs traversal and one visited array 
// if you visit a vertex which is already visited and which is not u then the cycle is detected
//
//
// detecting cycle in directed graph using bfs 
// this is pretty challenging 
// here the concept of indegree should be considered

void create_indegree(vector<int>vec[],int n,vector<int>&indegree){
   for(int i=0;i<n;i++){
       for(auto it:vec[i]){
           indegree[it]++;
       }
   }
   // printarray(indegree, n);
}
bool checkCycleInDirected(vector<int>vec[],int n){
    // the approach is to maintain a count 
    // if V != cnt then there is cycle in the graph 
    // if v== cnt then there is no cycle in the graph
    // as each vertex in the cycle as atleast one degree and there is no 
    // other way to enter that cycle 
    //
    // so if there is a cycle then cnt will always be less than V

    vector<int>indegree(6,0);
    create_indegree(vec, n, indegree);
    // no that indegree of each vertex is created we create a queue and push all the vertices 
    // who's indegree is 0
    queue<int>q;
    for(int i=0;i<n;i++){
        if (indegree.at(i)==0) {
            q.push(i);
        }
    }
    int cnt=1;
    while (!q.empty()) {
        int el=q.front();
        q.pop();
        for (auto x : vec[el]) {
            if (x==0) {
                q.push(x);
                cnt++;
            }
        }
    }
    if (cnt!=n) {
        return true;
    }else {
        return false;
    }
}


// Driver program to test above functions
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
    // bool result = dfs(vec, visited,recstk, 0);
    bool result= checkCycleInDirected(vec, n);
    if (result) {
        std::cout << "cycle is detected" << std::endl;
    }else {
        std::cout<<"cycle is not detected"<<std::endl;
    }
    return 0;
}
