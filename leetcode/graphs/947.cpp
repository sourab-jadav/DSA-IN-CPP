#include <iostream>
#include <vector>
using namespace std;

class Solution { // good question construct a parent and try you will understand
public:
    int removeStones(vector<vector<int>>& stones) {
        auto n = stones.size();
        vector<int> parent(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < stones.size(); j++) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    int pi = findParent(i, parent);
                    int pj = findParent(j, parent);
                    if (pi != pj) {
                        parent[pj] = pi;
                    }
                }
            }
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (parent[i] == i) {
                count++;
            }
        }
        return n - count;
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
    vector<vector<int>> vec = {{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}};
    Solution s;
    cout << s.removeStones(vec);
    return 0;
}
