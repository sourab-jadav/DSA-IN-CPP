#include <iostream>
#include <vector>
#include <string>
// https://www.geeksforgeeks.org/find-a-fixed-point-in-a-given-array/
using namespace std;
int main() {
    int  arr[] = {-10, -5, 0, 3, 7};
    // int  arr[] = {-10, -5, 3, 4, 7, 9};
    int n=sizeof(arr)/sizeof(arr[0]);
    // finding a fixed point i.e point where index and the value are same
    int low=0;
    int high=n-1;
    int result=-1;
    while (low<=high) {
        int mid=(low+high)/2;
        if (mid==arr[mid]) {
            result=mid;
            break;
        }
        if (arr[mid]<0 || arr[mid]<mid) {
            low=mid+1;
        }else {
            high=mid-1;
        }
    }
    std::cout<<result<<std::endl;
    return 0;
}


