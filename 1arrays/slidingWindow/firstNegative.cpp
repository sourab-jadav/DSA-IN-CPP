#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
  int arr[] ={12, -1, -7, 8, -15, 30, 16, 28}; 
  int n = sizeof(arr) / sizeof(arr[0]);
  int k=3;

  // for(int i=0;i<=n-k;i++){
  //     bool flag=true;
  //     for(int j=0;j<k;j++){
  //         if (arr[i+j]<0) {
  //           cout<<arr[i+j]<<" ";
  //           flag=false;
  //           break;
  //         }
  //     }
  //     if (flag) {
  //       cout<<0<<" ";
  //     }
  // }
  //

  for(int i=0;i<k;i++){
      if (arr[i]<0) {
        std::cout<<arr[i]<<" ";
        break;
      }
  }
  int i=1;
  for(int j=k;j<n;j++){
      bool flag=true;
      for(int k=i;k<=j;k++){
          if (arr[k]<0) {
              cout<<arr[k]<<" ";
              flag=false;
              break;
          }
      }
      if (flag) {
        cout<<0<<" ";
      }
      i++;
  }
  return 0;
}
