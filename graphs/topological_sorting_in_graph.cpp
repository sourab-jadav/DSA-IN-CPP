#include <csignal>
#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
#define printxyz(arr, rows, cols)                      \
        for (int i = 0; i < rows; ++i) {               \
            for (int j = 0; j < cols; ++j) {           \
                std::cout << arr[i][j] << " ";         \
            }                                          \
            std::cout << std::endl;                    \
        }                                              \
        std::cout<<std::endl;                          \
    } while (0)
#define printarray(arr, n)                             \
        std::cout<<std::endl;                          \
        for (int i = 0; i < n; ++i) {                  \
            std::cout<<arr[i]<<" ";                    \
        }                                              \
        std::cout<<std::endl;                          \

// what we are doing in this file
// we are performing the topological sort on the edges 
// there are three terms here:
// dependent 
// and the one it depends on , indegree
// (dependent)-> (depends on)
// (a)->(b)   => implies a is the dependent and it depends on b
//
// in the topological sort we calculate the indegree for each node
void addEdge(std::vector<int>vec[],int u,int v){
    vec[u].push_back(v);
}
void printGraph(std::vector<int>vec[],int n){
    for(int i=0;i<n;i++){
        for(int x:vec[i]){
            std::cout<<x<<" ";
        }
        std::cout<<std::endl;
    }
}
void createGraph(vector<int>vec[],int n,vector<vector<int>>edges){
    for (auto it : edges) {
        addEdge(vec, it.at(0), it.at(1));
    }
}
// creating the indegree array
void create_indegree(vector<int>vec[],int n,vector<int>&indegree){
   for(int i=0;i<n;i++){
       for(auto it:vec[i]){
           indegree[it]++;
       }
   }
   // printarray(indegree, n);
}
// now let's print the topological order of the graph
void printTopo(vector<int>vec[],int n,vector<int>indegree){
    // the topo order states that print the nodes which have indegree 0 first 
    // it means nodes on which no other nodes depend on 
    queue<int>q;
    for(int i=0;i<n;i++){
        if (indegree[i]==0) {
            q.push(i);
        }
    }
    // assuming there is atleast one independent node(with indegree 0)
    while (!q.empty()) {
        int t=q.front();
        std::cout<<t<<" ";
        q.pop();
        for(auto it:vec[t]){
            indegree[it]--;
            if (indegree[it]==0) {
                q.push(it);
            }
        }
    }
}
int main() {
    // the idea is to construct a graph 
    vector<vector<int>>edges{
        {2,3},{3,1},{4,0},{5,0},{5,2},{4,1}
    };
    int n=6;
    vector<int>vec[n];
    vector<int>indegree(n,0);
    // now let's traverse the edges one by one!!!
    createGraph(vec, 6,edges);
    create_indegree(vec, n,indegree);
    printTopo(vec, n, indegree);
    // now that the graph is created now let's do topological sorting
    return 0;
}
