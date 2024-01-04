#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// where i got stuck we are doing the bottom up approach for this solution
class Solution {
public:
    int getValue(vector<vector<int>>&mat,vector<vector<int>>&memo,int i=0,int j=0){
        int n=mat.size();
        int m=mat[0].size();

        
        if(i==n||j==m) return 1e9;
        if(i==n-1 && j==m-1){
            return (mat[i][j]<=0)?-mat[i][j]+1:1;
        }
        if (memo[i][j]!=1e9) {
            return memo[i][j];
        }
        int ifwegoright=getValue(mat,memo,i,j+1);
        int ifwegodown=getValue(mat,memo,i+1,j);
        int minhealth=min(ifwegoright,ifwegodown)-mat[i][j];
       return memo[i][j]=(minhealth<=0 )?1:minhealth; 
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        // doing the top down approach for this solution is not possible 
        // start thinking from the destination
         // if i==n-1 and j==m-1 then 
         //     if value is >=0 then 1
         //     else -value+1
        int n=dungeon.size();
        int m=dungeon[0].size();

        vector<vector<int>>memo(n,vector<int>(m,1e9));
         getValue(dungeon,memo);
         std::cout<<memo[0][0]<<std::endl;
    }
};
int main() {
    Solution s;
    vector<vector<int>>dungeon{{-2,-3,3},{-5,-10,1},{10,30,-5}};
    int result=s.calculateMinimumHP(dungeon);

    std::cout<<result<<std::endl;
}

// https://www.notion.so/dungeon-game-42f47b8204b4457c82f84263813d6e03?pvs=4#64775246b9254086b7f6bdcccd9d6802
