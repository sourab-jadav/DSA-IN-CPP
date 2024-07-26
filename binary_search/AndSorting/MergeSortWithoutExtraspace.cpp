#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void implementMergeSortInplace(int arr[],int start,int mid,int end){

    // std::cout<<"we got the values "<<start<<" "<<mid<<" "<<end<<std::endl;

    // peroforming inplace merge
    // the idea is to use 4 pointers approach start,mid,start1,end
    int start1=mid+1;
    while (start<=mid && start1<=end) {
        if (arr[start]<=arr[start1]) {
            start++;
            // start1++;//this is mistake
        }else {
            int value=arr[start1];
            int index=start1;
            while (index!=start) {
                arr[index]=arr[index-1];
                index--;
            }
            arr[index]=value;
            start++;
            mid++;
            start1++;
        }

    }
}



/* Driver program to test above functions */
int main() {
    int arr[]{1,4,12,14,18,21,6,13,17,19,20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int mid=(n-1)/2;
    std::cout<<"before :"<<std::endl;
    for_each(arr,arr+n,[](int n){
            std::cout<<n<<" ";
            });
    implementMergeSortInplace(arr,0,mid,n-1);
    std::cout<<std::endl;
    for_each(arr,arr+n,[](int n){
            std::cout<<n<<" ";
            });
    // mergeSort(arr, 0, arr_size - 1);
    // printArray(arr, arr_size);
    return 0;
}


