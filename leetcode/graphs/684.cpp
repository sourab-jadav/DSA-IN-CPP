#include <iostream>
#include <vector>
// https://leetcode.com/problems/redundant-connection/
using namespace std;
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // traversing through the edges
        int n=edges.size();
        vector<int>parent(n+1,0);
        for(int i=1;i<n+1;i++){
            parent[i]=i;
        }
        vector<vector<int>>result;
        for (auto ed : edges) {
            int u=ed[0];
            int v=ed[1];
            int pu=findparent(u,parent);
            int pv=findparent(v,parent);
            if (pu==pv) {
                result.push_back(ed);
            }
            parent[pv]=pu;
        }
        return result.back();
    }
    int findparent(int node,vector<int>parent){
        if (node==parent[node]) {
            return node;
        }
        else return parent[node]=findparent(parent[node], parent);
    }
};
int main() {
    Solution s;
    vector<vector<int>> vec = {{1, 2}, {1, 3}, {2, 3}};
    vector<int> ans = s.findRedundantConnection(vec);
    for (auto it : ans) {
        cout << it << " ";
    }
    return 0;
}



