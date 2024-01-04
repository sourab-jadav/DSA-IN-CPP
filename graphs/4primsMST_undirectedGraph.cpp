#include <iostream>
#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>
// MST is a tree which connects all the vertices of the graph with minimum weight
// here the approach is to find the minimum edge from the visited vertices and then add it to the result
// and then mark it as visited and then update the key of the vertices which are reachable from the current vertex
// and then repeat the process until all the vertices are visited
// the time complexity is O(V^2)
// because we are traversing all the vertices and then for each vertex we are traversing all the vertices

//this problem can be solved in O(ElogV) using priority queue and adjacency list  (adjacency matrix will take O(V^2) time) 
//here the parent array is used to store the parent of the vertex which is used to find the path of the MST 

// here we are traversing till n-2 because to find the MST we need to connect all the vertices with minimum weight 
// and we need n-1 edges to connect n vertices 
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

int main(){
    std::vector<std::vector<int>>graph{ // instead you can use vector of {source,dest,weight}
        {0,1},{1,4},{1,3},{1,2},{2,4},{0,3}
    };
    std::vector<std::vector<int>>weight{
        {0,2,0,6,0},
        {2,0,3,8,5},
        {0,3,0,0,7},
        {6,8,0,0,9},
        {0,5,7,9,0}
    };
    std::vector<int>vec[graph.size()];
    createGraph(graph,vec);
    int n = (int)graph.size();
    std::vector<int>key(n,INT_MAX);
    std::vector<bool>visited(n,false);
    std::vector<int>parent(n,-1);
    key[0] = 0;
    int result{};
    for (int i = 0; i < n-1; i++) { // here we are traversing all the vertices
        int min = INT_MAX;
        int minIndex = -1;
        for (int j = 0; j < n; j++) { // here the aim is to find the minimum edge from the visited vertices 
            if (!visited[j] && key[j] < min) {   // if the edge is not visited and the weight of the edge is less than the minimum edge
                min = key[j];
                minIndex = j;
            }
        }
        result+=min;
        visited[minIndex] = true;
        std::cout<<minIndex<<" ";
        for (int j = 0; j < vec[minIndex].size(); j++) {
            int v = vec[minIndex][j];
            if (!visited[v] && weight[minIndex][v] < key[v]) {
                key[v] = weight[minIndex][v];
                parent[v] = minIndex;
            }
        }
    }
    std::cout<<result<<std::endl;
    std::cout<<"printing the path of the graph"<<std::endl;
    for (auto x : parent) {
        std::cout << x << " ";
    }
    return 0;
}


// not working for some reason 
// #include <algorithm>
// #include <iostream>
// #include <vector>
// #include <climits>
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
// int main() {
//     std::vector<std::vector<int>>graph{ // instead you can use vector of {source,dest,weight}
//         {0,1},{1,3},{2,3},{0,2},{1,2}
//     };
//     std::vector<std::vector<int>>weight{
//         {0,5,8,0},{5,0,10,0},{8,10,0,20},{0,15,20,0}
//     };
//     int n=graph.size();
//     // another solution without using priority queue
//     std::vector<int>vec[n];
//     createGraph(graph, vec);
//     //the graph is created 
//     std::vector<bool>visited(n,false);
//     std::vector<int>key(n,INT_MAX);
//     int result=0;
//     key[0]=0;
//     // visit all the possible vertices from 0
//     for(int source=0;source<n-1;source++){
//         int u=-1;
//         for(int i=0;i<n;i++){
//             if (!visited[i]&& (u==-1 || key[i]<key[u])) {
//                 u=i;
//             }
//         }
//         result+=key[u];
//         visited[u]=true;
//         //now traverse all the vertice reachable from u
//         for (auto x : vec[u]) {
//             if (!visited[x]) {
//                 key[x]=std::min(key[x],graph[u][x]);
//             }
//         }
//     }
//     std::cout<<result<<std::endl;
//     return 0;
// }
//
