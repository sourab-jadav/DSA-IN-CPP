#include <iostream>
#include <string>
#include <vector>
using namespace std;
// the idea is to return low for the first occurence
// and high for the second occurence
int main() {
    // int arr[] = {1, 3, 5, 5, 5, 5,5, 67, 123, 125}, x = 5;
    int arr[]={5,67};
    int x=5;
    int n = sizeof(arr) / sizeof(arr[0]);

    int start = -1;
    int low = 0;
    int high = n - 1;
    // using only < in the while loop
    // while (low < high) { // <= is important here if the index are 0,1,2,3, and the
    //                      // desired element is at index 2 ,if you don't put <=
    //                      // then the mid will point at 1 and the loop will exit
    //
    //      // assuming x value is present in the array
    //     int mid = (low + high) / 2;
    //     if (arr[mid] < x) {
    //         low = mid + 1;
    //     } else {
    //         high = mid - 1;
    //     }
    // }

    // using <= in the while loop
    while (low<=high) {
        int mid=(low+high)/2;
        if (arr[mid]<x) {
            low=mid+1;
        }else {
            high=mid-1;
        }
    }
    std::cout<<"left most occurence found at "<<low<<std::endl;

    low=0;
    high=n-1;
    while (low<=high) {   // it must <= here 
                          // < will not work to understand this dry run [5,67] x=5;
        int mid=(low+high)/2;
        if (arr[mid]>x) {
            high=mid-1;
        }else {
            // low=mid; // using this statement here can cause infinite loop
            low=mid+1;
        }
    }
    std::cout<<"the right most occurence is at "<<high<<std::endl;

    return 0;
}
// NOTE: 
// for finding the left most occurence both <= and < can be included in the while loop
// for finding the right most occurence only <= will work for the above approach 
