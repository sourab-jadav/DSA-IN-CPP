#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// let's try to write program without using dp first
int main() {
    vector<int> arr{40, 20, 30, 10, 30};
    int result = INT_MAX;
    int n = arr.size();
    int idx=-1;
    int fresult=0;
    while (n>2) {
        for(int i=1;i<n-1;i++){
            int value=arr[i-1]*arr[i]*arr[i+1];
            if (value<result) {
                result=value;
                idx=i;
            }
        }
        std::cout<<"the result is "<<result<<std::endl;
        if (idx!=-1) {
            arr.erase(arr.begin()+idx);
            n=arr.size();
            idx=-1;
            fresult+=result;
            result=INT_MAX;
        }else {
            break;
        }
    }
    std::cout<<fresult<<std::endl;
    return 0;
}
