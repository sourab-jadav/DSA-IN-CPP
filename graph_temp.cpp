#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
//
// https://leetcode.com/problems/accounts-merge/
// 
class Solution { 
public:
    vector<set<string>> accountsMerge(vector<vector<string>>& accounts) {
        // you need to merge the accounts with same name and same and unique email id
        // and sort the email ids in lexicographical order 
        auto n = accounts.size();
        vector<int> parent(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) { // this is the main difference
                if (accounts[i][0] == accounts[j][0]) {
                    for (int k = 1; k < accounts[i].size(); k++) {
                        for (int l = 1; l < accounts[j].size(); l++) {
                            if (accounts[i][k] == accounts[j][l]) {
                                int pi = findParent(i, parent);
                                int pj = findParent(j, parent);
                                if (pi != pj) {
                                    parent[pj] = pi;
                                }
                            }
                        }
                    }
                }
            }
        }
        vector<set<string>> result;
        for (int i = 0; i < n; i++) {
            if (parent[i] == i) {
                set<string>temp;
                temp.insert(accounts[i][0]);
                for (int j = 1; j < accounts[i].size(); j++) {
                    temp.insert(accounts[i][j]);
                }
                result.push_back(temp);
            }
        }
        for (int i = 0; i < n; i++) {
            int pi = findParent(i, parent);
            if (pi != i) {
                for (int j = 1; j < accounts[i].size(); j++) {
                    result[pi].insert(accounts[i][j]);
                }
            }
        }
        // for (int i = 0; i < result.size(); i++) {
        //     sort(result[i].begin() + 1, result[i].end());
        // }
        return result;
       
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
int main(){
    Solution s;
    vector<vector<string>> vec = {{"John","johnsmith@mail.com","john_newyork@mail.com"},{"John","johnsmith@mail.com","john00@mail.com"},{"Mary","mary@mail.com"},{"John","johnnybravo@mail.com"}};
    vector<set<string>> ans = s.accountsMerge(vec);
    for (auto it : ans) {
        for (auto it1 : it) {
            cout << it1 << " ";
        }
        cout << endl;
    }
    set<int> s1{5,8,2,1,3,4,6,7,9,0};
    for(auto it:s1){
        cout<<it<<" ";
    }


    return 0;
}
