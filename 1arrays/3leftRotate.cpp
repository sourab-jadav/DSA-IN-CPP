#include <iostream>
#include <vector>
#include <string>
using namespace std;

// void swapValue(int arr[],int i,int j){
//     int temp=arr[i];
//     arr[i]=arr[j];
//     arr[j]=temp;
// }
//
// void swapPart(int arr[],int n,int k){
//     for(int i=0;i<k;i++){
//         swapValue(arr, i, n-k+i);
//     }
// }
// void printArray(int arr[],int n){
//     for(int i=0;i<n;i++){
//         std::cout<<arr[i]<<" ";
//     }
// }
// void reverse(int arr[],int n){
//     int low=0;
//     int high=n-1;
//     while (low<high) {
//         swapValue(arr, low, high);
//         low++;
//         high--;
//     }
// }
//
//
// void rotateByK(int arr[],int n,int k){
//     if (n==k) {
//         reverse(arr,n);
//     }else if (n==k+1) {
//         swapValue(arr, 0, n-1);
//         swapValue(arr, n-1, n-2);
//     }else if (n>k ) {
//         swapPart(arr, n, k);
//         rotateByK(arr, n-k, k);
//     }
// }
#include <iostream>
using namespace std;
// https://www.notion.so/left-rotate-an-array-using-recursion-e82e707037584f1b9e005713ba9c9d46?pvs=4#60859a808ad24514bbccd08a08337065
// Function to swap elements in the array
void swap(int arr[], int start, int end, int n) {
    for (int i = 0; i < n; i++) {
        int temp = arr[start + i];
        arr[start + i] = arr[end + i];
        arr[end + i] = temp;
    }
}

// Function to left rotate an array by d positions using recursion
void leftRotate(int arr[], int n, int d) {
    if (d == 0 || d == n) { // eg: {1,2,3,4,5} // {4,5,3} when d=2 there is overlapping
                            //                 // after excluding the overlapped part the remaining size on the left part is n-d=1
                            //                 // s=0 and end is d of size  n-d //do the swapping
                            //                 // now fix the overlapping part by rotating with size equal to overlapped array
        return;
    } // this is easy
    if (d < n - d) { // when there is no overlapping
        swap(arr, 0, n-d, d); // here swapping of length d
        leftRotate(arr, n-d,d);
    } else {
        swap(arr, 0, d, n - d); // swapping of lengh n-d
        leftRotate(arr + (n - d),  d , 2*d-n);
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int d = 3;

    cout << "Original array: ";
    printArray(arr, n);

    leftRotate(arr, d, n);

    cout << "Array after left rotation: ";
    printArray(arr, n);

    return 0;
}




// int main() {
//     int arr[]={1,2,3,4,5};
//     int n=sizeof(arr)/sizeof(arr[0]);
//     // rotateByK(arr, n, 3);
//     // printArray(arr, n);
//     
//     return 0;
// }
//
//
