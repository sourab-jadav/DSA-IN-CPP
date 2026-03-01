#include <climits> // for INT_MAX
#include <iostream>
#include <utility>
using namespace std;
int loumuto(int arr[],int low,int high){
    int x=arr[high];
    int i=low;
    for(int j=low;j<=high-1;j++){
        if (arr[j]<x) { // < prints the first occurence and <= gives the last occurence
            swap(arr[i],arr[j]);
            i++;
        }
    }
    swap(arr[i],arr[high]);
    return i;
}
int kthSmallest(int arr[],int low,int high,int k){
    // we are using loumuto partition here
    if (k>0 && k<=(high-low+1)) {
        int ind=loumuto(arr,low,high);
        if (ind-low==k-1) {
            return arr[ind];
        }else if (ind-low>k-1) {
            return kthSmallest(arr, low, ind-1, k);
        }else {
            return kthSmallest(arr, ind+1, high, k-ind+low-1); // this is crucial(k-(ind-low+1))
        }
    }
    return INT_MAX;
}
int main()
{
    int arr[] = { 12, 3, 5, 7, 4, 19, 26 };
    // int arr[]={4,5,6,3,3,1,1,2,2,3};
    int N = sizeof(arr) / sizeof(arr[0]), K = 3;

    // // Function call
    cout << "K'th smallest element is "
         << kthSmallest(arr, 0, N - 1, K);
    return 0;
}

