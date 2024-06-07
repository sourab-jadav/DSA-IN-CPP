#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    int left[]{1,2,5,15};
    int right[]{5,8,7,18};
    int arr[100]{};
    int n=sizeof(left)/sizeof(left[0]);
    for(int i=0;i<n;i++){
        arr[left[i]]++;
        arr[right[i]+1]--;
    }
    int frequency=0;
    int result=-1;
    for(int i=1;i<100;i++){
        arr[i]+=arr[i-1];
        if (arr[i]>frequency) {
            frequency=arr[i];
            result=i;
        }
    }
    std::cout<<"value "<<result<<" appeared "<<frequency<<" times"<<std::endl;
}
