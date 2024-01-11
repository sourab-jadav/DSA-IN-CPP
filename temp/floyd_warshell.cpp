#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
// floyd warshall algorithm is different from other algorithm because it is not
// greedy algorithm it is dynamic programming algorithm it is used to find all
// pair shortest path it is used to find shortest path between all pair of
// vertices all pair shotest path means shortest path between all pair of
// vertices for example if we have 4 vertices then we have to find shortest path
// between all pair of vertices

// this algorithm is used to find all pair shortest path from the each vertex to
// every other vertex
using namespace std;
void shortest_path(vector<vector<int>> &matrix, int V) {
    // here is the code for the above example
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (matrix[i][k] == -1 || matrix[k][j] == -1)
                    continue;
                else if (matrix[i][j] == -1)
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
                else
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }
}
// printing the matrix
void printmatrix(vector<vector<int>>&matrix,int v){
     //print the matrix
   for (auto x : matrix) {
      for (auto y : x) {
         cout << y << " ";
      }
      cout << endl;
   }
}

int main() {
    int V = 4;
    vector<vector<int>> matrix(V, vector<int>(V, -1));
    matrix[0][1] = 2;
    matrix[1][0] = 1;
    matrix[1][2] = 3;
    matrix[3][0] = 3;
    matrix[3][1] = 5;
    matrix[3][2] = 4;
    shortest_path(matrix, V);
    printmatrix(matrix, V);
    return 0;
}
