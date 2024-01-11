#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Solution { // this solution gave undefined satised error on leetcode 
                 // because of the findParent function 
                 // it should be parent[node] = findParent(parent[node], parent);
public:
    bool equationsPossible(vector<string>& equations) {
        vector<char> parent(26); 
        for (int i = 0; i < 26; i++) {
            parent[i] = i + 'a';
        }
        for (auto ed : equations) {
            if (ed[1] == '=') {
                int u = ed[0] - 'a';
                int v = ed[3] - 'a';
                int pu = findParent(u, parent);
                int pv = findParent(v, parent);
                if (pu != pv) {
                    parent[pv] = pu;
                }
            }
        }
        for (auto ed : equations) {
            if (ed[1] == '!') {
                int u = ed[0] - 'a';
                int v = ed[3] - 'a';
                int pu = findParent(u, parent);
                int pv = findParent(v, parent);
                if (pu == pv) {
                    return false;
                }
            }
        }
        return true;
    }
    int findParent(int node, vector<char>& parent) {
        if (node == parent[node] - 'a') {
            return node;
        }
        else {
            return parent[node] = findParent(parent[node]-'a', parent); // sanitizer error
                                                                        // at this line
        }
    }
};
int main() {
    Solution s;
    vector<string> vec = {"a==b","b!=a"};
    cout << s.equationsPossible(vec);


    return 0;
}
