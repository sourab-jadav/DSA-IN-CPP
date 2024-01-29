#include <iostream>
#include <vector>
// https://leetcode.com/problems/find-eventual-safe-states/submissions/1151705804/
using namespace std;
class Solution {
public:
    // these solution let to time limit exeeded
    // the solution is correct but there is need for optimization you can memoize but i want to tabulize
    // bool detectCycle(vector<vector<int>>&graph,vector<bool>&visited,int i){
    //     if (visited[i]==true) {
    //         visited[i]=false;
    //         return false;
    //     }
    //     visited[i]=true;
    //     if (graph[i].size()==0) {
    //         visited[i]=false;
    //         return true;
    //     }
    //     for (auto &x : graph[i]) {
    //         if(detectCycle(graph, visited, x)==false){
    //             return false;
    //         }
    //     }
    //     visited[i]=false;
    //     return true;
    // }
    // vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    //     vector<int>safe;
    //     int n=graph.size();
    //     vector<bool>visited(n,false);
    //     for(int i=0;i<graph.size();i++){
    //         if (graph[i].size()==0) {
    //             safe.push_back(i);
    //             continue;
    //         }
    //         if (detectCycle(graph, visited, i)) {
    //             safe.push_back(i);
    //         }
    //     }
    //     for (auto x : safe) {
    //         std::cout<<x<<" ";
    //     }
    //     return safe;
    //     
    // }

    bool dfs(vector<vector<int>>&graph,int v,vector<int>&dp){
        if (dp[v]) {
            return dp[v]==1;
        }
        dp[v]=-1;
        for(auto it=graph[v].begin();it!=graph[v].end();it++){
            if (!dfs(graph, *it, dp)) {
                return false;
            }
        }
        dp[v]=1;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v=graph.size();
        vector<int>res;
        vector<int>dp(v,0);
        for(int i=0;i<v;i++){
            if (dfs(graph,i,dp)) {
                res.push_back(i);
            }
        }
        return res;

        
    }
};
int main() {
    Solution s;
    vector<vector<int>> graph = {{1,2},{2,3},{5},{0},{5},{},{}};
    s.eventualSafeNodes(graph);
    return 0;
}


