#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>
std::vector<int>maxSlidingWindow(std::vector<int>&arr,int k){
    int n=arr.size();
    std::deque<int>dq;
    std::vector<int>ans;
    for(int i=0;i<n;i++){
        // if the element at the front is of index i-k then we
        // remove it as the element goes out of the current window
        if (!dq.empty()&& dq.front()==i-k) {
            dq.pop_front();
        }
        // if the rear element in the dequeue are already less than current element 
        // then we don't need them
        while (!dq.empty() && arr[dq.back()]<arr[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
        if (i>=k-1&& !dq.empty()) {
           ans.push_back(arr[dq.front()]) ;
        }
    }
    return ans;
}
int main() {
    std::vector<int>arr{
        4,0,-1,3,5,3,6,8
    };
    int k=3;
    std::vector<int>ans;
    ans=maxSlidingWindow(arr, k);
    for (auto &x : ans) {
        std::cout<<x<<" ";
    }
    std::cout<<std::endl;
    return 0;
}

// https://www.notion.so/dequeue-8ac5b4c138fd40779b8c3f37badb3190?pvs=4#f86e3dc538974322852f44f991aba751
