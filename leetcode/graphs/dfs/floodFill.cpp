// https://leetcode.com/problems/flood-fill/description/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
    public:
        void dfs(vector<vector<int>>&image,int i,int j,int color,int value){
            if (i<image.size() and i>=0 and j<image[0].size() and j>=0 and image[i][j]==value and image[i][j]!=color) {
                image[i][j]=color;
                dfs(image, i+1, j, color, value);
                dfs(image, i, j+1, color, value);
                dfs(image, i-1, j, color, value);
                dfs(image, i, j-1, color, value);
            }
        }
        vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color) {
            int value=image[sr][sc];
            dfs(image, sr, sc, color, value);
            return image;
        }
};
int main() {
    Solution s;
    vector<vector<int>> image = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    int sr = 1, sc = 1, color = 2;
    s.floodFill(image, sr, sc, color);
    for (auto &x : image) {
        for (auto &y : x) {
            std::cout<<y<<" ";
        }
        std::cout<<std::endl;
    }
    return 0;
}
