#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
// https://www.geeksforgeeks.org/weighted-job-scheduling-log-n-time/
// also look at job sequencing  problem
//
// challenge is to check if a profit x can be achieved by the given transactions or not
using namespace std;
// this is recursive approach
// // 
// //
// //
// struct Job
// {
//     int start, finish, profit;
// };
// // 
// //
// // here you have start time finish time
// //
// // sorting interms of the finish time is important to check the overlappness
// //
// // since there are intervals which are overlapping to address this problem 
// // for a current interval we have to find latest non overlapping interval (non overlapping interval close to the 
// //                                                                          current interval on the right side)
//
//
//
//
// // let's write a funtion that get's us the latest non overlapping interval
// int latestNonConflict(Job arr[],int i){
//     for(int j=i-1;j>=0;j--){
//         // check for overlapping 
//         if (arr[j].finish<=arr[i-1].start) {
//             return  j;
//         }
//     }
//     return -1;
// }
//
// // find the profit
// int findMaxProfit(Job arr[],int n){
//     if (n==1) {
//          // if there is only one interval then return it's profit
//         return arr[n-1].profit;
//     }
//     int incprof=arr[n-1].profit;
//     int i=latestNonConflict(arr, n);
//     if (i!=-1) {
//         // incprof+=findMaxProfit(arr, n-1); // there is a mistake here
//         incprof+=findMaxProfit(arr, i+1);
//     }
//     int excludeprof=findMaxProfit(arr, n-1);
//     return max(incprof,excludeprof);
// }
//
//
// int main()
// {
//     Job arr[] = {{3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {2, 100, 200}};
//     int n = sizeof(arr)/sizeof(arr[0]);
//     sort(arr,arr+n,[](Job x1,Job x2){
//             return x1.finish<x2.finish;
//             });
//     cout << "The optimal profit is " << findMaxProfit(arr, n);
//     return 0;
// }
//



// let's talk about can we do it with binary search


