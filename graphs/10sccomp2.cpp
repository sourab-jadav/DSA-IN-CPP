#include <algorithm>
#include <iostream>
#include <stack>
#include <type_traits>
#include <vector>
// concept of starting time and finishing time in kosaraju algorithm
// https://takeuforward.org/graph/strongly-connected-components-kosarajus-algorithm-g-54/
// the algorithm states sort all the nodes according to their finishing time
// the nodes in the last strongly connected component finishes first so you can use stack
// i solved printing strongly connected without reversing the edges
using namespace std;
void print(vector<int>adj[],int n){
    for(int i=0;i<n;i++){
        for (auto &x : adj[i]) {
            std::cout<<i<<"->"<<x<<" ";
        }
    }
    std::cout<<std::endl;
}
void dfs(vector<int>adj[],vector<bool>&visited,int s,stack<int>&stk){
    visited[s]=true;
    stk.push(s);
    for (auto &x : adj[s]) {
        if (!visited[x]) {
            dfs(adj, visited, x, stk);
        }
    }
}
void countDfs(vector<int>adj[],vector<bool>&visited,int s){
    std::cout<<s<<" ";
    visited[s]=true;
    for (auto &x : adj[s]) {
        if (!visited[x]) {
            countDfs(adj, visited, x);
        }
    }
}
int countStronlyConnected(vector<int>adj[],int n){
    // use the stack and use dfs methodology to push into the stack
    stack<int>stk;
    // let's print the element first
    vector<bool>visited(n,false);
    dfs(adj, visited, 0, stk);
    visited.assign(n,false);
    std::cout<<std::endl;
    vector<int>adj1[n];
    for(int i=0;i<n;i++){
        for (auto &x : adj[i]) {
            adj1[x].push_back(i);
        }
    }
    int count=0;
    while (!stk.empty()) {
        while (!stk.empty()&& visited[stk.top()]) { // u stuck here
            stk.pop();
        }
        if (stk.empty()) {
            break;
        }
        int p=stk.top();
        countDfs(adj, visited, p);
        std::cout<<std::endl;
        count++;
    }
    std::cout<<count<<std::endl;
    return 0;
}

int main() {
     int n = 5;
    int edges[5][2] = {
        {1, 0}, {0, 2},
        {2, 1}, {0, 3},
        {3, 4}
    };
    vector<int> adj[n];
    for (int i = 0; i < n; i++) {
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    countStronlyConnected(adj, n);
    return 0;
}


