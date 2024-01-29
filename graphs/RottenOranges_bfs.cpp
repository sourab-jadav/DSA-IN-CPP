#include <iostream>
#include <queue>
#include <utility>
#include <vector>

// your code is code but there is a possibility of refactoring here
int main() {
    std::vector<std::vector<int>>grid{
        {2,1,1},{1,1,0},{0,1,1}
    };
    int row_size=grid.size();
    int column_size=grid[0].size();
    std::queue<std::pair<int, int>>q;
    q.push({0,0});
    int minute_count=0;
    while (!q.empty()) {
        std::pair<int, int>rc=q.front();
        q.pop();
        int row=rc.first;
        int col=rc.second;
        bool flag=false;
         // checking right
        if (col+1>=0 && col+1<column_size && grid[row][col+1]==1) {
            q.push({row,col+1});
            grid[row][col+1]=0;
            flag=true;
        }
        // checking bottom
        if (row+1>=0 && row+1<row_size && grid[row+1][col]==1) {
            q.push({row+1,col});
            grid[row+1][col]=0;
            flag=true;
        }
        // checking left
        if(col-1>=0 && grid[row][col-1]==1){
            q.push({row,col-1});
            grid[row][col-1]=0;
            flag=true;
        }
        // checking top
        if (row-1>=0 && grid[row-1][col]==1) {
            q.push({row-1,col});
            grid[row-1][col]=0;
            flag=true;
        }
        if (flag) {
            minute_count++;
        }
    }
    for(auto &x:grid){
        for(auto &y:x){
            if (y==1) {
                std::cout<<-1<<std::endl;
                return 0;
            }
        }
    }
    std::cout<<"minutes required: "<<minute_count<<std::endl;
    return 0;
}
