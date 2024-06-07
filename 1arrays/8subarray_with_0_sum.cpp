#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
using namespace std;
int main() {
     int arr[]{2,3,5,-4,-4,10};
     // we can use hashset here and solve the question
    int n=sizeof(arr)/sizeof(arr[0]);
    unordered_set<int>st;
    // subarrays with sum equal to 0
    st.insert(arr[0]);
    int sum=arr[0];
    for(int i=1;i<n;i++){
        sum+=arr[i];
        auto it=st.find(sum);
        if (it!=st.end()) {
            std::cout<<"it contains the subarray with sum 0 "<<std::endl;
            return 0;
        }
        st.insert(sum);
    }
    std::cout<<"no subarray with sum 0"<<std::endl;

}


