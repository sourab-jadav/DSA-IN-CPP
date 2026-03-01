#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#define  INF 1000000 //  for some reason INT_MAX is not working here
                     //  this solution is giving address sanitizer error on memoization
// recursive sol
class Solution {
public:
    int solve(int i,int n,int last_copied,std::vector<std::vector<int>>&memo){
        if (i>n) {
            return INF;
        }
        // writing the base case
        if (i==n) {
            return 0;
        }
        if (memo[i][last_copied]!=0) {
            return memo[i][last_copied];
        }
        // performing the possible operations
        int copy=2+solve(i+i, n, i,memo);
        int paste=1+solve(i+last_copied, n, last_copied,memo);
        return memo[i][last_copied]=std::min(copy,paste);
    }
    int minSteps(int n) {
        std::vector<std::vector<int>>memo(n,std::vector<int>(n,0));
        solve(1, n, 1,memo);
        return memo[1][1];
    }
};
int main() {
  int n = 3;
  // initially you are having 'A' in your nodepad
  // the problem is find minimum number of copy paste operations
  // required to achieve n number of a's
  //
  // at each step you can do two operations copy or paste
  //
  // if you do copy you also have to paste in the future so it involves 2 op and
  // you keep track of last copied number(this is important!!!)
  //
  //if you copy i will become i+i and i will be the last copied number
  //if you paste i will become i+l and last copied number remains the same
 
  Solution s;
  int result=s.minSteps(n);
  std::cout<<result<<std::endl;
  return 0;
}
