#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
// https://www.notion.so/bitwise-6fa2ce2d09c3496b9c434d26df71f022?pvs=4#b3658b3c229c44c58d3439cb20afe26a
using namespace std;
// finding the missing and the repeating element 
// 
// one way is to maintain a count array
// // for missing : look for the value who's frequency is 0
// // for repeating : look for the value who's frequency is 2;
// 
//
// another way of solving the problem is using hashset
// push the elements into the hash set
// if the element is already present you will get the repeating element
// now traverse i from through 1 to size and check if it is present in the set  
//      if present 
//          then remove it 
//      else 
//          if i is not repeating element 
//          then this is the missing element
//
//
// by calculating the sum of size elements // this is nice solution
// traverse through the elements 
// 
void printTwoElements(int arr[],int n){
    // get the sum
    int sum=(n*(n+1))/2;
    // since the elements are only going to contain positive elements let's use this 
    for(int i=0;i<n;i++){
        if (arr[abs(arr[i])-1]>0) {
            arr[abs(arr[i])-1]= -arr[abs(arr[i])-1];
            sum-=abs(arr[i]);
        }else {
            std::cout<<abs(arr[i])<<std::endl;
        }
    }
    std::cout<<"and the missing element is "<<sum<<std::endl;
}
// int main() {
//  int arr[] = { 7, 3, 4, 5, 5, 6, 2 };
//     int n = sizeof(arr) / sizeof(arr[0]);
//     printTwoElements(arr, n);
//
// }
int main(){

}
