#include <iostream>
using namespace std;
int binarySearch(int arr[],int n,int x){  // simple and fast
    int low=0;
    int high=n-1;
    int mid=0;
    while (low<=high) { // <= is important here if you search for value 2 in range (1,5)
        mid=(low+high)/2; // in zero based indexing bid aligns towards left part
        if (arr[mid]==x) {
            return mid;
        }else if (arr[mid]>x) {
            high=mid-1;
        }else {
            low=mid+1;
        }
    }
    return -1;
}
int main() {
    int arr[]{1,2,3,4,5};
    // now this array is rotated you have to find an element in logn
    int result=binarySearch(arr, 5, 5);
    std::cout<<result<<std::endl;
    return 0;
}


