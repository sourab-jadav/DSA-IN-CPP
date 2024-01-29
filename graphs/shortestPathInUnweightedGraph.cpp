#include <cstdint>
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
void addEdge(std::vector<int>vec[],int u,int v){
    vec[u].push_back(v);
    vec[v].push_back(u);
}
void createGraph(std::vector<std::vector<int>>graph,std::vector<int>vec[]){
    int n=(int)graph.size();
    for(int i=0;i<(int)graph.size();i++){
        addEdge(vec, graph[i][0], graph[i][1]);
    }
}

void bfsWhenSourceGiven(std::vector<int>vec[],int n,int s,std::vector<bool>&visited,std::vector<int>&dist){
    std::queue<int>q;
    visited[s]=true;
    dist[s]=0;
    q.push(s);
    while (!q.empty()) {
        int u=q.front();
        q.pop();
        // std::cout<<u<<" ";
        for (int x : vec[u]) {
            if (visited[x]==false) {
                visited[x]=true;
                dist[x]=dist[u]+1;
                q.push(x);
            }
        }
    }
}

int main() {
    std::vector<std::vector<int>>graph{
        {0,1},{1,2},{2,3},{1,3},{0,2}
    };
    std::cout<<"enter the size of the graph"<<std::endl;
    int n=4;
    std::vector<int>vec[n];
    createGraph(graph, vec);
    std::vector<bool>visited(n,false);
    std::vector<int>dist(n,0);
    bfsWhenSourceGiven(vec, n, 0, visited, dist);
    for (auto x : dist) {
        std::cout<<x<<" ";
    }
    std::cout<<std::endl;
    return 0;
}
