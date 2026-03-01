#include <iostream>
#include <vector>
#include <climits>
void addEdge(std::vector<int> vec[], int u, int v) {
    vec[u].push_back(v);
    vec[v].push_back(u);
}
void createGraph(std::vector<std::vector<int>> graph, std::vector<int> vec[]) {
    int n = (int)graph.size();
    for (int i = 0; i < n; i++) {
        addEdge(vec, graph[i][0], graph[i][1]);
    }
}
int main() {
    std::vector<std::vector<int>>graph{ // instead you can use vector of {source,dest,weight}
        {0,1},{1,3},{2,3},{0,2},{1,2}
    };
    std::vector<std::vector<int>>weight{
        {0,5,8,0},{5,0,10,0},{8,10,0,20},{0,15,20,0}
    };
    int n=graph.size();
    // std::vector<std::vector<bool>>visited(n,std::vector<bool>(n,false)); // creating a visited array // you don't need this.
    std::vector<bool>visited(n,false);
    std::vector<int>vec[n];
    createGraph(graph, vec);
    std::vector<int>key(n,INT_MAX);
    // the idea is 
    // you traverse through all the vertex
             // in each traversal you pick vertex with minimum edge 
             // and this vetex is going to be the part of the graph so you mark as visited
                    //from the picked u you visit all the possible v's
                    //and make sure that the distance till v is as minimum as possible

    key[0]=0;
    int result=0;
    for(int count=0;count<n;count++){ // traversing through each vertex
        int u=-1;
        for(int i=0;i<n;i++){
            if (!visited[i] && (u==-1 || key[i]<key[u])) { // picking the vertex with minimum edge
                u=i;
            }
        }
        // we finalized the vertex we add the distance to the result and mark this vetex as visited
        result+=key[u];
        visited[u]=true;
        for(int v=0;v<n;v++){
            if (graph[u][v]!=0 && !key[v]) {
                key[v]=std::min(key[v],graph[u][v]);
            }
        }
    }


    return 0;
}


