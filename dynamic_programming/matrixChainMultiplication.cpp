#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// let's try to write program without using dp first
int main() {
    // vector<int> arr{40, 20, 30, 10, 30}; // result is as expected
    // vector<int> arr{1,2,3,4,3}; // result as expected
    vector<int> arr{10,20,30}; // result as expected
    for_each(arr.begin(),arr.end(),[](auto x){
            std::cout<<x<<" ";
            });
    std::cout<<std::endl;
    int result = INT_MAX;
    int n = arr.size();
    int idx=-1;
    int fresult=0;
    while (n>2) {
        for(int i=1;i<n-1;i++){
            int value=arr[i-1]*arr[i+1];
            if (value<result) {
                idx=i;
                result=value;
            }
        }
        if (idx!=-1) {
            fresult+=(arr[idx-1]*arr[idx]*arr[idx+1]);
            arr.erase(arr.begin()+idx);
            n=arr.size();
            idx=-1;
            result=INT_MAX;
        }else {
            break;
        }
    }
    std::cout<<fresult<<std::endl;
    return 0;
}
