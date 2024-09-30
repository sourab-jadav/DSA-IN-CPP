#include <algorithm>
#include <iostream>
#include <unordered_map>
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
int main() {
    int bighits=4;
    int newtons[]{3,2,5,4,6,7,9};
    int n=sizeof(newtons)/sizeof(newtons[0]);
    vector<vector<int>>result=solve(bighits,newtons,n);
    for (auto it : result) {
        for (auto el : it) {
            std::cout<<el<<" ";
        }
        std::cout<<std::endl;
    }
    return 0;
}
