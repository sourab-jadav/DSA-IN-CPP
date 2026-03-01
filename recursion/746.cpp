 #include<bits/stdc++.h>

 using namespace std;

 int find(vector<int>&cost,int n,vector<int> &memo){

        if(n==0|| n==1){
            return 0;
        }
        

        if(memo[n]!=-1){
            return memo[n];
        }
       
      memo[n]= min(find(cost,n-1,memo)+cost[n-1],find(cost,n-2,memo)+cost[n-2]);
      return memo[n];
       
    }
    int minCostClimbingStairs(vector<int>& cost) {

        int n=cost.size();
        vector<int>memo(n+1,-1);
        return find(cost,n,memo);
    }

int main(){
    vector<int> vec{10,15,20};
    cout<<minCostClimbingStairs(vec);

}