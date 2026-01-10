/*
  we are given an array we need to partition into two subsets in such a way
  that the difference of two subset sums is minimum
  eg:[1,11,5,6] if we divide this array into [1,5,6] and [11]
  the difference of this two subarrays is minimum 12-11 =1


  we need to achieve this
  if we think in a recursive way to solve the problem
  if we partition in a way so that the diff b/w the sum of subarray1 and sum of subarray2 is minimum

  to create a partition we need to make a decision of including it or not, starting from the last or first element

  the basecase could be after we have made decision on all elements we return the absolute diff b/w included and excluded elements
https://www.geeksforgeeks.org/dsa/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum/  
  
 */

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int solve(int arr[], int n, int sumIncluded, int totalSum) {
  if (n == 0) {
    // from the total sum you need to remove the included sum
    int otherPart = totalSum - sumIncluded;
    return abs(sumIncluded-otherPart);
  }
  return min(solve(arr,n-1,sumIncluded+arr[n-1],totalSum),solve(arr,n-1,sumIncluded,totalSum));
}




int main() {
int arr[]=  {1, 6, 11, 5};
 int sum = accumulate(arr, arr + 4,0);
 cout<<sum<<endl;
 cout << solve(arr,4,0,sum) << endl;

  return 0;
}


