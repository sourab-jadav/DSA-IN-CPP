#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    int arr[] {36, 41, 56, 35, 44, 33, 34, 92, 43, 32, 42}; 
    // int arr[] { 1, 9, 3, 10, 4, 20, 2 }; 
    // int arr[] {1,2,2,3}; 
    // deal with three cases
    // handling duplicates
    // dealing with multiple consecutive subsequnces and finding the subseq with max length
    // dealing at the start of the array at 1 index where where we don't have to check i-1 and i-2 
    int n=sizeof(arr)/sizeof(arr[0]);
    sort(arr,arr+n);
    int count=0;
    int result=0;
    for(int i=1;i<n;i++){
        if (arr[i]==arr[i-1]+1 || arr[i]==arr[i-1]) {
            if (i-1==0 || arr[i-1]!=arr[i-2]+1) {
                count=1;
            }else {
                count++;
                result=max(result,count);
            }
        }
    }
    std::cout<<++result<<std::endl;

    return 0;
}


