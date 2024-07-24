#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>
// this code is not return by the author
using namespace std;
// using binary search to solve the problem
//
// writing the ispossible function to check if it is possible to allocate
// members for the given sum
bool ispossible(int arr[], int n, int m, int curr_sum) { 
    int sum = 0;
    int count = 1;
    for (int i = 0; i < n; i++) {
        if (arr[i] > curr_sum) {
            return false;
        }
        if (sum + arr[i] > curr_sum) {
            count++;
            sum = arr[i];
            if (count > m) {
                return false;
            }
        } else {
            sum += arr[i];
        }
    }
    return true;
}

int findPages(int arr[],int n,int m){
    long long sum=0;
    int mx=INT_MIN;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        mx=max(arr[i],mx);
    }
    // we set the boundary
    // range starts from max( of all arr[i]) to total sum;

    int start=mx;
    int end=sum;
    int result=INT_MAX;
    while (start<=end) {
        int mid=(start+end)/2;
        if (ispossible(arr, n, m, mid)) {
             result=mid;
            end=mid-1;
        }else {
            start=mid+1;
        }
    }
    return result;
}
int main() {
int arr[] = { 12, 34, 67, 90 };
int n=sizeof arr/sizeof arr[0];
    int m=2;
    int result=findPages(arr, n, m);
    std::cout<<result<<std::endl;

    return 0;
}
