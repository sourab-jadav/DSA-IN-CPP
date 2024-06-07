#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    int arr[]{5,2,6,1,1,1,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int sum=0;
    for (auto x : arr) {
        sum+=x;
    }
    if (sum%3!=0) {
        std::cout<<"cannot be divided"<<std::endl;
        return 0;
    }
    int target=sum/3;
    std::cout<<"the target is "<<target<<std::endl;
    int count=0;
    sum=0;
    for (auto x : arr) {
        sum+=x;
        if (sum==target) {
            count++;
            sum=0;
        }
    }
    if (count==3) {
        std::cout<<"yes"<<std::endl;
    }else {
        std::cout<<"no"<<std::endl;
    }
    return 0;
}
