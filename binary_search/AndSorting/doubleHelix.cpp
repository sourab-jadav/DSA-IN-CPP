#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
// https://www.spoj.com/problems/ANARC05B/
using namespace std;
int main() {
    int arr1[]{3,5,7,9,20,25,30,40,55,56,57,60,62};
    int n=sizeof arr1/sizeof arr1[0];
    int arr2[]{1,4,7,11,14,25,44,47,55,57,100};
    int m=sizeof arr2/sizeof arr2[0];
    std::cout<<std::endl;
    while (n) { // handling inputs is cleared
        int i=0;
        int j=0;
        int sum1=0,sum2=0;
        int result=0;

        while (i<n and j<m) {
            if (arr1[i]<arr2[j]) {
                sum1+=arr1[i++];
            }else if (arr1[i]>arr2[j]) {
                sum2+=arr2[j++];
            }else {
                result+=max(sum1,sum2);
                sum1=sum2=arr1[i];
                i++;
                j++;
            }
        }
        // we are done with the half of the problem let's work on the rest half

        if (i==n) {
            while (j<m) {
                sum2+=arr2[j++];
            }
        }else if (j==m) {
            while (i<m) {
                sum1+=arr1[i++];
            }
        }
        result+=max(sum1,sum2);
        std::cout<<result<<std::endl;

        cin>>n;
    }
    // second part of the problem is handling inputs 
    //
    // it is given in the problem that the last line is going to be the zero value 
    // so we run a loop until the n value becomes 0

    return 0;
}


