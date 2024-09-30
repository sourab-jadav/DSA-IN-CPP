#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <utility>
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


// https://www.notion.so/ibm-111bd12954e18068af2be8db9aa5fd18
vector<vector<int>> solve(int bighits,int newtons[],int n){
    unordered_map<int, int>mp;
    for(int i=0;i<n;i++){
        mp[newtons[i]]=i+1;
    }
    sort(newtons,newtons+n);
    vector<int>b_hits;
    vector<int>s_hits;
    vector<vector<int>>result;
    int i=n-1;
    if (bighits>0) {
        while (bighits>0) {
            b_hits.push_back(mp[newtons[i]]);
            bighits--;
            i--;
        }
        sort(b_hits.begin(),b_hits.end());
    }
    int sum=0;
    sum+=n-i-1;
    while (i>=0) {
        s_hits.push_back(mp[newtons[i]]);
        sum+=newtons[i];
        i--;
    }
    sort(s_hits.begin(),s_hits.end());
    result.push_back(vector<int>{sum});
    result.push_back(s_hits);
    result.push_back(b_hits);
    return result;
}
// solution using min heap 
vector<vector<int>> solve_m2(int bighits,int newtons[],int n){
    // the problem is to 
    // take the big hits 
    priority_queue<pair<int, int>,vector<pair<int, int>>,greater<>>pq_big;
    vector<int>small;
    vector<int>big;
    vector<vector<int>>result;
    int sum=0;
    
    int max_size=bighits;
    for(int i=0;i<n;i++){
        pq_big.push(make_pair(newtons[i], i+1));
        if (pq_big.size()==max_size+1) {
            small.push_back(pq_big.top().second);
            sum+=pq_big.top().first;
            pq_big.pop();
        }
    }
    while (!pq_big.empty()) {
        big.push_back(pq_big.top().second);
        pq_big.pop();
    }
    sum+=big.size();
    result.push_back(vector<int>{sum});
    result.push_back(small);
    result.push_back(big);
    // now we have the elements
    return result;
}
int main() {
    int bighits=4;
    int newtons[]{3,2,5,4,6,7,9};
    int n=sizeof(newtons)/sizeof(newtons[0]);
    vector<vector<int>>result=solve_m2(bighits,newtons,n);
    for (auto it : result) {
        for (auto el : it) {
            std::cout<<el<<" ";
        }
        std::cout<<std::endl;
    }

    solve_m2(bighits, newtons, n);

    return 0;
}
