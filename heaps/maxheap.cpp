#include <fstream>
#include <future>
#include <iostream>

class Heap {
  int heapsize;
  public: 
  Heap(int n) { this->heapsize = n; }
  // left index
  int left(int i) { return 2 * i + 1; }
  int right(int i) { return 2 * i + 2; }
  void heapify(int arr[], int i) {
    int highest = i;
    int l = left(i);
    int r = right(i);
    if (l < heapsize && arr[l] > arr[r]) {
      highest = l;
    }
    if (r < heapsize && arr[r] > arr[l]) {
      highest = r;
    }
    if (i != highest && arr[highest]>arr[i]) {
      std::swap(arr[i], arr[highest]);
      heapify(arr, highest);
    }
  }
  void buildheap(int arr[]){
      for(int i=(heapsize>>1)-1;i>=0;i--){
          heapify(arr, i);
      }
  }
  int getTop(int arr[]){
    int temp=arr[0];
    std::swap(arr[0],arr[heapsize-1]);
    heapify(arr, 0);
    heapsize--;
    return temp;
  }
};


int main(){
    int arr[]{ 2,3,8,34,12,17,19,5 };
    int n=sizeof(arr)/sizeof(arr[0]);
    Heap h(n);
    h.buildheap(arr );
    for(int i=0;i<n;i++){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
    std::cout<<h.getTop(arr)<<std::endl;
    std::cout<<h.getTop(arr)<<std::endl;
    std::cout<<h.getTop(arr)<<std::endl;
}
