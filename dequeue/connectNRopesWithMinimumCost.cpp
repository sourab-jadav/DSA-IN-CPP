#include <iostream>
#include <iterator>
#include <queue>
#include <vector>

using namespace std;
// do it in terms of long long
// you had hard time dealing with long long here
int main() {
    long long arr[] = {4, 3, 2, 6};
    long long N = sizeof(arr)/sizeof(arr[0]);
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < N; i++) {
        pq.push(arr[i]);
    }
    long long cost = 0;
    while (pq.size()>1) {
        long long el1=pq.top();
        pq.pop();
        // long long el2=(!pq.empty())?pq.top():0; // this verification is also not needed
        long long el2=pq.top();
        pq.pop();
        cost+=el1+el2;
        pq.push(el1+el2);
        // if (pq.size()==1) { // this not required
        //     break;
        // }
    }
    std::cout<<cost<<std::endl;
    return 0;
}
