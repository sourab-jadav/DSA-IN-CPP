#include <cstring>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    std::cout<<"printing m n-bonachi numbers"<<std::endl;
    std::cout<<"enter number of numbers you want (m)"<<std::endl;
    int m;
    cin>>m;
    std::cout<<"what bonachi"<<std::endl;
    int n;
    cin>>n;
    if (m>=n) {
        int arr[m];
        memset(arr, 0, sizeof(arr));
        arr[n-1]=1;
        int sum=0;
        int i;
        for( i=n;i<2*n-1;i++){
            sum+=arr[i-1];
            arr[i]=sum;
        }
        for(int j=i;j<m;j++){
            sum+=(arr[j-1]-arr[j-n-1]);
            arr[j]=sum;
        }
        for(int i=0;i<m;i++){
            std::cout<<arr[i]<<" ";
        }
        
    }
    return 0;
}


