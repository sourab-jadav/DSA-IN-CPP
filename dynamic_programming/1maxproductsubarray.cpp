#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    // int arr[]{6,-3,-10,0,2};
    int arr[]{1,-2,-3,0,7,-8,-2};  // i thought this approach but not sure
    // int arr[]{-1,-3,-10,0,60};
    int n=sizeof(arr)/sizeof(arr[0]);
    int pos_sum=1;
    int neg_sum=1;
    int result=0;
    for(int i=0;i<n;i++){
        if (arr[i]==0) {
            pos_sum=1;
            neg_sum=1;
            continue;
        }
        if (arr[i]<0) {
            result=max(result,pos_sum);
            pos_sum=1;
        }else {
            pos_sum*=arr[i];
        }
        neg_sum*=arr[i];
        result=max(result,neg_sum);
    }
    std::cout<<result<<std::endl;

    return 0;
}
