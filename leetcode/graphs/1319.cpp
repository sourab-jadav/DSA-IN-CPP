#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) { // as n nodes require n-1 edges to connect
            return -1;
        }
        vector<int> parent(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        for (auto ed : connections) {
            int u = ed[0];
            int v = ed[1];
            int pu = findParent(u, parent);
            int pv = findParent(v, parent);
            if (pu != pv) {
                parent[pv] = pu;
            }
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (parent[i] == i) {
                count++;
            }
        }
        return count - 1;
        
    }
    int findParent(int node, vector<int>& parent) {
        if (node == parent[node]) {
            return node;
        }
        else {
            return parent[node] = findParent(parent[node], parent);
        }
    }
};
int main() {
    Solution s;
    vector<vector<int>> vec = {{0,1},{0,2},{0,3},{1,2}};
    cout << s.makeConnected(6, vec);

    return 0;
}


