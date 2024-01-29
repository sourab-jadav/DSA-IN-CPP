#include <iostream>
#include <list>
#include <map>
#include <vector>
using namespace std;
// https://leetcode.com/problems/time-needed-to-inform-all-employees/description/
class Solution {
    public:
        int dfs(map<int, list<int>> &m, int i, vector<int> &informTime) {
            // you didn't really understood the problem and you started coding
            int maxi = 0;

            for (auto it = m[i].begin(); it != m[i].end(); it++) {
                maxi = max(maxi, dfs(m, *it, informTime));
            }
            return maxi + informTime[i];
        }
        int numOfMinutes(int n, int headID, vector<int> &manager,
                vector<int> &informTime) {
            // the idea is construct a graph and do the top down approach
            // when you are at a node check for all of its children
            // which child gets the max time
            // add that time to the current manager inform time

            map<int, list<int>> m;
            // manager[i] is the parent and all it's children are it's employees
            // get the maximum time taken among it's child employees
            // and to that add the current informTime
            for (int i = 0; i < n; i++) {
                int man = manager[i];
                m[man].push_back(i);
            }
            return dfs(m, headID, informTime);
        }
};

int main() {
    vector<int> manager = {2, 2, -1, 2, 2, 2};
    int n = 6;
    int headID = 2;
    vector<int> informTime = {0, 0, 1, 0, 0, 0};
    Solution s;
    s.numOfMinutes(n, headID, manager, informTime);
}
