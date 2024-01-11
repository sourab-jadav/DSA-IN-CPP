#include <iostream>
#include <vector>
#include <climits>
// bellman algo work for negative weight cycle also
// for example if we have a graph with 3 nodes and 3 edges
// 1->2 weight 1
// 2->3 weight 1
// 3->1 weight -3
// then bellman algo will give shortest path as 0->1->2->3->0 with weight 0 but actually it is -1 so we can detect negative weight cycle using bellman algo
void bellmanford(std::vector<std::vector<int>>edges,int V,int src){
    std::vector<int>dist(V,INT_MAX);
    dist[src]=0;
    for(int i=0;i<V-1;i++){
        for(auto it : edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            if(dist[u]!=INT_MAX && dist[u]+wt<dist[v]){
                dist[v]=dist[u]+wt;
            }
        }
    }
    // now we have to check for negative weight cycle
    for(int i=0;i<edges.size();i++){
        if(dist[edges[i][0]]!=INT_MAX && dist[edges[i][0]]+edges[i][2]<dist[edges[i][1]]){
            std::cout<<"Negative weight cycle is present";
            return;
        }
    }
    for(int i=0;i<V;i++){
        std::cout<<dist[i]<<" ";
    }
}
int main() {
    int V=6;
    std::vector<std::vector<int>>edges(7,std::vector<int>(3));
    edges[0] = {3, 2, 6};
	edges[1] = {5, 3, 1};
	edges[2] = {0, 1, 5};
	edges[3] = {1, 5, -3};
	edges[4] = {1, 2, -2};
	edges[5] = {3, 4, -2};
	edges[6] = {2, 4, 3};
    // we have the edges and their weight 
    // we need to find the shortest path from source to destination
    // we will use bellman ford algo



    return 0;
}


