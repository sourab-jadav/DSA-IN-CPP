#include <iostream>
#include <queue>
#include <string>
#include <variant>
#include <vector>


void addEdge(std::vector<int>vec[],int u,int v){
    vec[u].push_back(v);
    vec[v].push_back(u);
}


void printGraph(std::vector<int>vec[],int n){
    for(int i=0;i<n;i++){
        for(int x:vec[i]){
            std::cout<<x<<" ";
        }
        std::cout<<std::endl;
    }
}


// std::vector<int>* createGraph(){   //this is not working saying address of stack memory associated with local variable x returned
void createGraph(std::vector<int>vec[],int n){
    std::cout<<"enter -1 to stop creating edges"<<std::endl;
    while (true) {
        int u,v;
        std::cin>>u>>v;
        if (u==-1 || v==-1) {
            break;
        }
        addEdge(vec, u, v);
    }
}


void bfsWhenSourceGiven(std::vector<int>vec[],int n,int s,std::vector<bool>&visited){
    std::queue<int>q;
    visited[0]=true;
    q.push(0);
    while (!q.empty()) {
        int u=q.front();
        q.pop();
        std::cout<<u<<" ";
        for (int x : vec[u]) {
            if (visited[x]==false) {
                visited[x]=true;
                q.push(x);
            }
        }
    }
}


void bfsWithOutSourceGiven(std::vector<int>vec[],int n){
    std::vector<bool>visited(n,false);
    for(int i=0;i<n;i++){
        if (visited[i]==false) {
           bfsWhenSourceGiven(vec, n, i,visited); 
        }
    }
}


// depth first search
void dfs(std::vector<int>vec[],std::vector<bool>visited,int n,int s){
    visited[s]=true;
    std::cout<<s<<" ";
    for (int x : vec[s]) {
        if (visited[x]==false) {
            dfs(vec, visited, n, x);
        }
    }
}

int main() {
    // createGraph(vec, n);
    std::vector<std::vector<int>>graph{
        {0,1},{1,2},{2,3},{0,4},{4,5},{5,6},{4,6}
    };
    int n=(int)graph.size();
    std::vector<int>vec[n];
    for(int i=0;i<(int)graph.size();i++){
        addEdge(vec, graph[i][0], graph[i][1]);
    }
    std::vector<bool>visited(n,false);
    dfs(vec, visited, n,0);
    return 0;
}
