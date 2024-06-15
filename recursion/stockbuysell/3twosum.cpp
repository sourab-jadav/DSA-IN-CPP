#include <iostream>
#include <set>
#include <vector>
#include <string>
using namespace std;
int main() {
    std::cout << "Hello, World!" << std::endl;
    int arr[]{1,5,7,-1};
    int n=4;
    set<int>st;
    int count=0;
    int sum=6;
    for(int i=0;i<n;i++){
        if (st.find(sum-arr[i])!=st.end()) {
            count++;
        }else {
            st.insert(sum-arr[i]);
        }
    }
    std::cout<<count <<std::endl;

    return 0;
}


