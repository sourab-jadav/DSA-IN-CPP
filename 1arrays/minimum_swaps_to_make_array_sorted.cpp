#include <algorithm>
#include <iostream>
#include <map>
#include <variant>
#include <vector>
#include <string>
using namespace std;
// this is a working solution 
// https://www.geeksforgeeks.org/minimum-swap-required-convert-binary-tree-binary-search-tree/
int main() {

    // vector<int>vec{2,4,5,1,3};
    vector<int>vec{5,3,9,2,8,4,1,6,7};
    int n=vec.size();

    // objective is to calculate minimum number of swaps needed to make the array sorted

    // the idea is to solve the problem using number of nodes involved in the cycle 
    // number of swaps = number of nodes -1;

    vector<int>temp(vec.begin(),vec.end());
    sort(temp.begin(),temp.end());

    map<int, int>mp;
    for(int i=0;i<n;i++){
        mp[temp[i]]=i;
    }

    // we have the map ready to check the current index of the element

    vector<bool>visited(n,false);
    int result=0;
    for(int i=0;i<n;i++){ // here the idea is count the number of nodes involved in the cycle
        if (visited[i]==false) {
            int j;
            // now get the correct index of j 
            // since the current index is not visited the cycle is possible
            // let's first visit the index
            visited[i]=true;
            // now get it's original index;
            j=mp[vec[i]];
            int curr=1;
            while (visited[j]==false) {
                visited[j]=true;
                curr+=1;
                j=mp[vec[j]];
            }
            if (curr>1) {
                result+=curr-1;
            }
        }
    }
    std::cout<<result<<std::endl;


    return 0;
}
