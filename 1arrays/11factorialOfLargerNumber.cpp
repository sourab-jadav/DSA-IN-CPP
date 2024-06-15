#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define MAX 500
int mutliply(int arr[],int res,int value){

    int carry=0;
    int i;
    for(i=0;i<res;i++){
        int val1=arr[i]*value+carry;
        carry=val1/10;
        arr[i]=val1%10;
    }
    while (carry) {
        arr[i]=carry%10;
        carry=carry/10;
        i++;
    }
    return i;
}
void factorial(int n){
    int arr[MAX]{};
    arr[0]=1;
    int res=1;
    for(int i=2;i<=n;i++){
        res=mutliply(arr,res,i );
    }
    for(int i=res-1;i>=0;i--){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
}
int main() {
    std::cout<<"enter the number whose factorial you want to find out"<<std::endl;
    int n;
    cin>>n;
    factorial(n);
    return 0;
}


