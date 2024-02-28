#include <iostream>
#include <queue>
using namespace std;
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isBipartite(int V, vector<int>adj[]){

        // Code here
        //here we are using bfs to check if the graph is bipartate or not
        // we are using two colors 0 and 1
        // we are using a queue to store the nodes
        // we are using a vector to store the color of the nodes
        // if we find a node with the same color as its parent then the graph is not bipartate
        // if we find a node with a different color than its parent then we push it into the queue
        // if we find a node with the same color as its parent then we return false
        // if we traverse the whole graph and we dont find any such node then we return true
        // we are using a vector to store the color of the nodes
        // we are using a queue to store the nodes
        vector<int> color(V, -1);
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                q.push(i);
                color[i] = 0;
                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    for (auto it : adj[node]) {
                        if (color[it] == -1) {
                            color[it] = 1 - color[node];
                            q.push(it);
                        }
                        else if (color[it] == color[node]) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;

	     // to check if the graphs is bipartate 
      //    we store the u v pairs in two different sets
      //    if we find a pair in the same set then the graph is not bipartate
 //         unordered_set<int> s1;
 //         unordered_set<int> s2;
 //         for(int i=0;i<V;i++){
 //             if(s1.find(i)==s1.end() && s2.find(i)==s2.end()){
 //                 s1.insert(i);
 //                 queue<int> q;
 //                 q.push(i);
 //                 while(!q.empty()){
 //                     int u = q.front();
 //                     q.pop();
 //                     for(int v:adj[u]){
 //                         if(s1.find(v)!=s1.end()){
 //                             if(s1.find(u)!=s1.end()){
 //                                 return false;
 //                             }
 //                             s2.insert(u);
 //                         }
 //                         else if(s2.find(v)!=s2.end()){
 //                             if(s2.find(u)!=s2.end()){
 //                                 return false;
 //                             }
 //                             s1.insert(u);
 //                         }
 //                         else{
 //                             if(s1.find(u)!=s1.end()){
 //                                 s2.insert(v);
 //                             }
 //                             else{
 //                                 s1.insert(v);
 //                             }
 //                             q.push(v);
 //                         }
 //                     }
 //                 }
 //             }
 //         }
 //         return true;
	// }

};

//{ Driver Code Starts.
int main(){
	int tc;
    std::cout<<"enter tc"<<std::endl;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
