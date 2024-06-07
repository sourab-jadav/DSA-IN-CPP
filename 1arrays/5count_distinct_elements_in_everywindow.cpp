#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;
int main() {
    int arr[]={1,2,1,3,4,3,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    int k=4;
    unordered_map<int, int>mp;
    int distinct_count=0;
    for(int i=0;i<k;i++){
        if (mp[arr[i]]==0) {
            distinct_count++;
        }
        mp[arr[i]]++;
    }
    cout<<distinct_count<<" ";
    for(int i=k;i<n;i++){
        if(--mp[arr[i-k]]==0){
            distinct_count--;
        }
        if (mp[arr[i]]==0) {
            distinct_count++;
        }
        mp[arr[i]]++;
        cout<<distinct_count<<" ";
    }
    
}


