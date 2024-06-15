#include <iostream>
#include <vector>
#include <string>
using namespace std;
int mergeArray(int arr[],int low,int mid,int high){
    int n1=mid-low+1;
    int n2=high-mid;
    int arr1[n1];
    int arr2[n2];
    int count=0;
    for(int i=0;i<n1;i++){
        arr1[i]=arr[low+i];
    }
    for(int i=0;i<n2;i++){
        arr2[i]=arr[mid+1+i];
    }
    int i=0;
    int j=0;
    int k=low;
    while (i<n1 && j<n2) {
        if (arr1[i]<arr2[j]) {
            arr[k]=arr1[i];
            k++;
            i++;
        }else if (arr1[i]>arr2[j]) {
            arr[k]=arr2[j];
            j++;
            k++;
            count+=(n1-i);
        }else{
            arr[k]=arr1[i];
            i++;
            k++;
            j++;
        }
    }
    while (i<n1) {
        arr[k]=arr1[i];
        i++;
        k++;
    }
    while (j<n2) {
        arr[k]=arr2[j];
        j++;
        k++;
    }
    return count;


}
int mergeSort(int arr[],int low,int high){
        int count=0;
    if (low<high) {
        int mid=(low+high)/2;
        count+=mergeSort(arr, low, mid);
        count+=mergeSort(arr, mid+1, high);
        count+=mergeArray(arr,low,mid,high); // i see the problem here
    }
    return count;
}
int main() {
    int arr[]{8,4,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    int result=mergeSort(arr, 0, n-1);
    for(int i=0;i<n;i++){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
    std::cout<<"the inversions are "<< result<<std::endl;
    return 0;
}


