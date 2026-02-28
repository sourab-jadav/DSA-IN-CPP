#include <bits/stdc++.h>
#include <shared_mutex>

using namespace std;


int main() {
  int arr[] = {0, 1, 2, 0, 1, 2};
  // sort 0s 1s and 2s
  // traverse the mid pointer
  // low pointer on 0
  // mid pointer on 0
  // high pointer on n-1
  // if the value is 0 ;; do swap(arr[low],arr[mid]) low++,mid stays the same
  // if the value is 1 ;; mid++
  // if the value is 2 ;; swap arr[mid] arr[high] high--,mid stays the same
  int low = 0;
  int high = 5;
  int mid = 0;

while (mid<=high) {
  if (arr[mid] == 0) {
    swap(arr[low], arr[mid]);
    low++;
    mid++;    
  }else if(arr[mid]==1){

      mid++;
  } else {
      swap(arr[mid],arr[high]);      
      high--;
  }
}

for (int i = 0; i <= 5; i++) {
    cout<<arr[i]<<" ";
 }
  
  return 0;
  
}
