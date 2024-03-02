#include <iostream>
#include <vector>
#include <string>
using namespace std;
// https://leetcode.com/problems/search-a-2d-matrix-ii/description/
// Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
// Output: true
// search in a 2d matrix
// solving with the help of binary search and recursion
//
class Solution {
    int binarySearch(vector<int> &arr, int target) {
        int left = 0;
        int right = arr.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) {
                return mid;
            } else if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
    bool searchMatrix(vector<vector<int>> &matrix, int target, int row, int col) {
        if (row < 0 || col < 0 || row >= matrix.size() || col >= matrix[0].size()) {
            return false;
        }
        if (matrix[row][col] == target) {
            return true;
        }
        if (matrix[row][col] < target) {
            return searchMatrix(matrix, target, row + 1, col);
        }
        if (matrix[row][col] > target) {
            return searchMatrix(matrix, target, row, col - 1);
        }
        return false;
    }
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int row = 0;
        int col = matrix[0].size() - 1;
        return searchMatrix(matrix, target, row, col);
    }
};
int main() {
    vector<vector<int>>matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};

    int target = 5;
     // vector<vector<int>>matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};int target = 20;
    string result = Solution().searchMatrix(matrix, target) ? "true" : "false";
    std::cout<<result<<std::endl;
    return 0;
}
        // int m = matrix.size();
        // if (m == 0) {
        //     return false;
        // }
        // int n = matrix[0].size();
        // if (n == 0) {
        //     return false;
        // }
        // int i = 0;
        // int j = n - 1;
        // while (i < m && j >= 0) {
        //     if (matrix[i][j] == target) {
        //         return true;
        //     } else if (matrix[i][j] > target) {
        //         j--;
        //     } else {
        //         i++;
        //     }
        // }
        // return false;
        

