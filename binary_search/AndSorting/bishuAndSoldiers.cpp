#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// approach this is o sqrt n time 
// int killMaxWithStrengthP(int p) {
//   // if you move the index from i=1 there will be an i who's square
//   // will be greater than p from that i moving on beginning from that i
//   // it is impossible to kill the soldiers
//
//   // so we only traverse from i=1 to i*i <=p
//
//   int temp{};
//   int count{};
//   for (int i = 1; i <= p; i++) {
//     // add the strength that got removed after killing each soldier
//     temp += (i * i);
//
//     if(temp<=p)
//         count++;
//     else
//         break;;
//   }
//   return count;
// }

// we can see if we kill the ith person we have already killed the i-1th person
// this means it is monotonic function f in which strength is increasing sq times
// monotonically from left to right
//
// we keep calculating the total strength accumulated till that point and we find the 
// point at which the accumulated strength reaches the p value
//
// #define ll long long
// static constexpr int kn=1e5;
//
//
// int killMaxWithStrengthP(int p){
//     ll sums[kn];
//     sums[0]=0;
//     for(int i=1;i<kn;i++)
//         sums[i]= (ll)(i*i)+sums[i-1];
//
//     auto it=lower_bound(sums,sums+kn,p); // this returns value greater than or equal to p 
//                                          // if the value is > p we do --it
//
//     if(*it>p)
//         --it;
//
//     return it-sums;
// }
//
// tc is o(kn)

// let's break down the complexity to log(1e5)
// and space to o 1
//
// the idea here is you just don't need to store the sum just calculate 
// and do the binary search on the indexes

long calSum(long n){
    return (n*(n+1)*(2*n+1))/6;
}
int killMaxWithStrengthP(long p){
    long low=0;
    long high=1e5;
    int result;
    while (low<=high) {
        long mid=low+(high-low)/2;
        long val=calSum(mid);
        // if the value is greater than we do high-1 and we don't include those value
        if (val>p) {
            high=mid-1;
        }else {
            result=mid;
            low=mid+1;
        }
    }
    return result;
}
int main() {
  int p = 14;
  int result = killMaxWithStrengthP(p);
  std::cout << result << std::endl;
  return 0;
}
