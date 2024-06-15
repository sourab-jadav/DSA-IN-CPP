#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    int arr[]{2,5,13,7,15,18,12,10}; // the idea here is pick every pair i,j where j is > i 
    int n=sizeof(arr)/sizeof(arr[0]);
    int result{};
    for(int i=1;i<n;i++){
        if (arr[i]>arr[i-1]) {
            result+=(arr[i]-arr[i-1]);
        }
    }
    std::cout<<result<<std::endl;
}


