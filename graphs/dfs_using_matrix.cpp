#include <iostream>
#include <utility>
#include <vector>

void dfs(int arr[7][7], std::vector<int> &visited, std::vector<int> &stack) {
    while(!stack.empty()) {
        int node = stack.back();
        stack.pop_back();
        if(visited[node] == 1) {
            continue;
        }
        visited[node] = 1;
        std::cout << node << " ";
        for(int i=0; i<7; i++) {
            if(arr[node][i] == 1) {
                stack.push_back(i);
            }
        }
    }
}

int main() {

    // points of the graph
    std::vector<std::pair<int, int>> points ={
        {1,2},{2,3},{4,5},{5,6}
    };
    // adjacency matrix
    int arr[7][7];
    for(int i=0; i<7; i++) {
        for(int j=0; j<7; j++) {
            arr[i][j] = 0;
        }
    }
    for(auto p: points) {
        arr[p.first][p.second] = 1;
        arr[p.second][p.first] = 1;
    }


    //doing dfs on this matrix
    int count=0;
    std::vector<int> visited(7, 0); 
    std::vector<int> stack;
    for(int i=1; i<7; i++) {
        stack.push_back(i);
        dfs(arr, visited, stack);
        std::cout<<std::endl;
    }
    std::cout<<count<<std::endl;
}


