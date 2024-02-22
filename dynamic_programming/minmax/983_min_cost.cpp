#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int travel(vector<int>& days, vector<int>& costs,int dtv,int i){
        if (days[i]+dtv>=days[days.size()-1]) {
            return 0;
        }

        // now travel all the days possible from current day
        

        

    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // we have to travel the days with the minimum cost
        int result=INT_MAX;
        vector<int> no_days={1,7,30};
        // travel function should take days it can travel
        // and subproblem should traverse that many days
        // do it until all the days are travelled
        int n=costs.size();
        for(int i=0;i<n;i++){
            result=min(result,costs[i]+travel(days, costs, days[i],i));
        }
    }
};
int main() {
     vector<int>days = {1,4,6,7,8,20};
     vector<int> costs = {2,7,15};
     Solution s;
     s.mincostTickets(days, costs);
    return 0;
}


