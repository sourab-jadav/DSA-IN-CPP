#include <iostream>
#include <variant>
#include <vector>
// https://leetcode.com/problems/keys-and-rooms/
using namespace std;
class Solution {
    public:
        void visitRoom(vector<vector<int>> &rooms, int i, vector<bool> &visited) {
            visited[i] = true;
            for (auto x : rooms[i]) {
                if (!visited[x]) {
                    visitRoom(rooms, x, visited);
                }
            }
        }
        bool canVisitAllRooms(vector<vector<int>> &rooms) {
            vector<bool> visited(rooms.size(), false);
            visitRoom(rooms, 0, visited);
            for (int i = 0; i < visited.size(); i++) {
                if (!visited[i]) {
                    std::cout << i << " is not visited " << std::endl;
                    return false;
                }
            }
            return true;
        }
};

int main() {
    std::vector<std::vector<int>> rooms = {{1, 3}, {3, 0, 1}, {2}, {0}};
    Solution s;
    cout << s.canVisitAllRooms(rooms) << endl;
    return 0;
}
