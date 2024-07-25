#include <iostream>
#include <string>
#include <vector>
using namespace std;
// https://www.spoj.com/problems/PRATA/
/*
    This problem uses binary search approach , as answer is monotonic function .
   ( of true and false on time ). By applying binary search on time , we get the
   answer.
*/
// for the ispossible function
// the idea is to calculate for a given time how many pratas can each cook
// contributes
//
// at any point if number of contributions are greater than or equal to p we return true
// else we return false;
bool ispossible(int arr[], int n, int time, int p) {

    // for the given time calculate how much prata's each cook can contribute

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        // get the time taken for each cook
        int timeWeHave = time;
        int adder = arr[i];
        int count = 0;
        while (timeWeHave > 0) {
            timeWeHave = timeWeHave - adder;
            if (timeWeHave >= 0) {
                count++;
                adder += arr[i];
            }
        }
        cnt += count;
        if (cnt >= p) {
            return true;
        }
    }
    return false;
}
// learn to take the inputs in the prata file
// Input
//
// The first line tells the number of test cases. Each test case c
// onsist of 2 lines. In the first line of the test case we have P
// the number of prata ordered. In the next line the first integer
// denotes the number of cooks L and L integers follow in the same
// line each denoting the rank of a cook.
//
//  Input:
// 3
// 10
// 4 1 2 3 4
// 8
// 1 1
// 8
// 8 1 1 1 1 1 1 1 1

// Output:
// 12
// 36
// 1
//
//

int solve(int arr[],int n,int p){

    int s=0,e=1e7;
    int mid,ans=-1;
    while (s<=e) {
        mid=(s+e)/2;
        if (ispossible(arr, n, mid, p)) {
            ans=mid;
            e=mid-1;
        }else {
            s=mid+1;
        }
    }
    return ans;
}


int main() {
  // first line contains number of transactions
  int t;
  cin>>t;
while (t--) {
    int p;
    cin>>p;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    std::cout<<solve(arr,n,p)<<std::endl;

}

  return 0;
}
