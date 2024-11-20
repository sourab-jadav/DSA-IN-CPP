#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
#define printxyz(arr, rows, cols)                      \
        for (int i = 0; i < rows; ++i) {               \
            for (int j = 0; j < cols; ++j) {           \
                std::cout << arr[i][j] << " ";         \
            }                                          \
            std::cout << std::endl;                    \
        }                                              \
        std::cout<<std::endl;                          \
    } while (0)
#define printarray(arr, n)                             \
        std::cout<<std::endl;                          \
        for (int i = 0; i < n; ++i) {                  \
            std::cout<<arr[i]<<" ";                    \
        }                                              \
        std::cout<<std::endl;                          \

// here the night is moving from one point to the another point
// is feasable function is required here
// is feasable checks for a given coardinate is possible or not
bool isFeasable(int x,int y,int N){
    if (x>=0 && x<N && y>=0 && y<N) {
        return true;
    }else {
        return false;
    }
}
struct cell{
    int x,y;
    int dis;
    cell(){}
    cell(int x,int y,int dis):x(x),y(y),dis(dis){

    }
};
int solve(int kpos[],int tpos[],int N){
    int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 };
    int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
    // we will be solving this problem by using bfs
    // traversing through all the possible ways
    queue<cell>q;
    cell t;
    int x,y;
    bool visit[N][N];
    memset(visit, false, sizeof(visit));
    q.push(cell(kpos[0],kpos[1],0));
    visit[kpos[0]][kpos[1]]=true;
    while (!q.empty()) {
        t=q.front();
        q.pop();
        if (t.x==tpos[0] && t.y==tpos[1]) {
            return t.dis;
        }

        for(int i=0;i<8;i++){
            x=t.x+dx[i];
            y=t.y+dy[i];
            // now you have to see if it is reachable from here or not 
            // if it is already reached then we don't consider that path

            if (isFeasable(x, y, N) && !visit[x][y]) {
                visit[x][y]=true;
                q.push(cell(x,y,t.dis+1));
            }
        }
        
    }
    return -1;
}

int calculateSteps(int knightPos[],int targetPos[],int N){
    return solve(knightPos,targetPos,N);
}


int main() {
    // we have knight and we have the target
   int N=30;
   int knightPos[]{0,0};
   int targetPos[]{29,29};
   int result=calculateSteps(knightPos, targetPos, N);
   std::cout<<result<<std::endl;
    return 0;
}
