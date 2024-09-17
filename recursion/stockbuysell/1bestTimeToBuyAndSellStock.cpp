#include <algorithm>
#include <climits>
#include <cstdint>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
// infinite transactions are allowed here
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
// atmost one transaction is allowed here
int onlyOneTransactionAllowed(int arr[],int start,int end){
    int current_min=arr[start];
    int result=0;
    for(int i=start+1;i<=end;i++){
        if (arr[i]<current_min) {
            current_min=arr[i];
        }else {
            result=max(result,arr[i]-current_min);
        }
    }
    return result;
}
// atmost two transactions allowed
int onlyTwoTransactionsAllowed(int arr[],int n){
    int current_min=INT_MAX;
    int result=0;
    for(int i=0;i<n;i++){
        if (arr[i]<current_min) {
            current_min=arr[i];
        }else {
            result=max(result,arr[i]-current_min+onlyOneTransactionAllowed(arr, i+1, n-1 ));
        }
    }
    return result;
}
// another way of solving the two transactions
// what we can do is 
// we create two auxilary arrays 
// one arrays stores the max profit of the left part 
// and other array stores the max profit of the right part
int onlyTwoTransactionsAllowed_method2(int arr[],int n){
    int left_profit[n];
    int right_profit[n];
    // the cach is on the leftside we keep track of current_min
    // and on the right side we keep track of currentmax
    int result=0;
    int current_min=arr[0];
    left_profit[0]=0;
    for(int i=1;i<n;i++){
        if (arr[i]<current_min) {
            current_min=arr[i];
        }else {
            result=max(result,arr[i]-current_min);
        }
        left_profit[i]=result;
    }
    result=0;
    int currentmax=arr[n-1];
    right_profit[n-1]=0;
    for(int i=n-2;i>=0;i--){
        if (arr[i]>currentmax) {
            currentmax=arr[i];
        }else {
            result=max(result,currentmax-arr[i]);
        }
        right_profit[i]=result;
    }
    std::cout<<"done with the left and right array"<<std::endl;
     result=0;
    for(int i=0;i<n;i++){
        result=max(result,left_profit[i]+right_profit[i]);
    }
    return result;
}
// atmost k transactions allowed 
int k_transactions_allowed(int arr[],int start,int end,int k,int n ){
    // the idea is using the earlier recursion based approach to solve this problem
    // the base case could be 
    // if k=0 then no transaction is possible so return 0;
    if (k==0 || start<0 || end>=n) {
        return 0;
    }
    int result=0;
    for(int i=start;i<=end;i++){
        for(int j=i+1;j<=end;j++){
            if (arr[j]>arr[i]) {
                int current_profit=(arr[j]-arr[i])+max(k_transactions_allowed(arr, j+1, end, k-1,n),k_transactions_allowed(arr, start, i-1,  k-1,n));
                result=max(result,current_profit);
            }
        }
    }
    return result;
}
// using the statemachine to solve the  problem
// manageting the state of when the person bought and notbought seperately 
// if you didn't bought the stock then 
//      you can buy the stock or you don't buy a stock 
//      when you buy a stock the actual value will be decreased by the price at current i and transaction fee
// if you bought the stock then 
//      you can sell the stock or don't sell the stock 
//      if you sell the stock the the gain in value is price at i 
//      you don't sell at the current i you call for i+1 value
int statemachine_method(int arr[],int i,int n,bool bought,int fee){
    if (i==n) { // when there is nomore stock to buy then 
        return 0;
    }
    if (!bought) {
        int opt1=(-arr[i]-fee)+statemachine_method(arr, i+1, n, true, fee);
        int opt2=statemachine_method(arr, i+1, n, false, fee);
        return max(opt1,opt2);
    }else {
        // now we had bought previously now
        int opt1=arr[i]+statemachine_method(arr, i+1, n, false, fee);
        int opt2=statemachine_method(arr, i+1, n, true, fee);
        return max(opt1,opt2);
    }



}
int main() {
    // int arr[]{2,5,13,7,15,18,12,10}; // the idea here is pick every pair i,j where j is > i 
    // int arr[]  {2, 30, 15, 10, 8, 25, 80}; 
    // int arr[]{ 10, 22, 5, 75, 65, 80}; // passed
    // int arr[]{ 12, 14, 17, 10, 14, 13, 12, 15}; //passed
    // int arr[]{  100, 30, 15, 10, 8, 25, 80}; //passed
    // int arr[]{90,80,70,60,50};  //passed
    int arr[]{ 1,3,2,8,4,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    int fee=2;
    // int result=findBestTimeToBuyStock(arr,0,n-1);
    // int result=k_transactions_allowed(arr,0, n-1,2 ,n);
    int result=statemachine_method(arr, 0, n, false, fee); // expected is 8 but getting 23 for somereason
    std::cout<<result<<std::endl;
    return 0;
}
