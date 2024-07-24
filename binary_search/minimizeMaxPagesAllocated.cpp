#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int sum(int arr[],int s,int d){
    int total{};
    for(int i=s;i<=d;i++){
        total+=arr[i];
    }
    return total;

}
int minimizeMaxPagesAllocated(int arr[],int n,int k ){
    if (k==1) {
        return sum(arr,0,n-1);
    }
    if (n==1) {
        return arr[0];
    }
    int result=INT_MAX;
    for(int i=1;i<n;i++){
        result=min(result,max(minimizeMaxPagesAllocated(arr, i, k-1),sum(arr, i, n-1))); // takes all the permutations of the
                                                                                         // result and tries to minimize all
                                                                                         // all the possible values
    }
    return result;
}
int main() {
int arr[] = { 12, 34, 67, 90 };
int n=sizeof(arr)/sizeof(arr[0]);
int k=2;
int result=minimizeMaxPagesAllocated(arr, n, k);
std::cout<<result<<std::endl;
    return 0;
}


