#include <cstdint>
#include <iostream>

int lomuto_partitioning(int arr[],int l,int r){
  int j=l-1;
  int pivot=arr[r];
  for(int i=l;i<r+1;i++){
      if (arr[i]<=pivot) {
        j++;
        std::swap(arr[i],arr[j]);
      }
  }
  return j;
}
int kthSmallestElement(int arr[],int l,int r,int k){
    if (k<=r-l+1 && k>0) {
        int ind=lomuto_partitioning(arr, l, r);
        //if the found index is after k then reduce the size
        //if the found index is before k then reduce the k value by index-l+1
        if (ind-l==k-1) {
            return arr[ind];
        }
        if (ind-l>k-1) {
            return kthSmallestElement(arr, l, ind-1, k);
        }
        return kthSmallestElement(arr, ind+1, r, k-(ind-l+1));
    }
    return INT8_MAX;
}
void print(int arr[],int n){
  for(int i=0;i<n;i++){
      std::cout<<arr[i]<<" ";
  }
  std::cout<<std::endl;
}


int main() {
  int arr[]{6, 4, 14, 16, 10, 45, 24, 5, 7};
  int n=sizeof(arr)/sizeof(arr[0]);
  std::cout<<"enter which element you want"<<std::endl;
  int k;
  std::cin>>k;
  int result=kthSmallestElement(arr, 0, n-1, k);
  std::cout<<result<<std::endl;
}


