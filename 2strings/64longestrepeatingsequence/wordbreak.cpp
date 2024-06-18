#include <iostream>
#include <set>
#include <vector>
#include <string>
using namespace std;
bool solve(set<string>&st,vector<int>&dp,int ind,string s){
    int n=s.size();
    if (ind==n || st.find(s)!=st.end()) {
        return 1;
    }
    for(int j=ind;j<n;j++){
        string temp=s.substr(ind,j-ind+1);
        if (st.find(temp)!=st.end() and solve(st, dp, j+1, s)) {
            return 1;
        }
    }
    return 0;

}
int main() {
    string s = "applepenapple"; 
    vector<string> wd={"apple","pen"};
    set<string>st(wd.begin(),wd.end()); // we need set because it contains the find method vector does not contain the find method
    int n=s.size();
    vector<int>dp(n,-1);
    std::cout<<solve(st, dp, 0, s)<<std::endl;
    
    return 0;
}


