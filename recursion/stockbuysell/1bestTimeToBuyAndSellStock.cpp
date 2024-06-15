#include <iostream>
#include <vector>
#include <string>
using namespace std;
int findBestTimeToBuyStock(int arr[],int start,int end){
    if (start>=end) {
        return 0;
    }
    int profit=0;
    for(int i=start;i<=end;i++){
        for(int j=i+1;j<=end;j++){
            if (arr[j]>arr[i]) {
                int current_profit=(arr[j]-arr[i])+findBestTimeToBuyStock(arr, start, i-1)+findBestTimeToBuyStock(arr, j+1, end);
                profit=max(profit,current_profit);
            }
        }
    }
    return profit;
}
int main() {
    int arr[]{2,5,13,7,15,18,12,10}; // the idea here is pick every pair i,j where j is > i 
    int n=sizeof(arr)/sizeof(arr[0]);
    int result=findBestTimeToBuyStock(arr,0,n-1);
    std::cout<<result<<std::endl;
    return 0;

}


