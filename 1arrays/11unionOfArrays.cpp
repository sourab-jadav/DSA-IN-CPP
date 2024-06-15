#include <iostream>
#include <vector>
#include <string>
using namespace std;
void nextInd(vector<int>&vec,int n,int &i){
    do {
    ++i;
    }while (i<n && vec[i]==vec[i-1]);
}
int main() {
    vector<int>arr1{ 1,2,2,2,3};
    vector<int>arr2{ 2,3,3,4,5,5}; 
    int n1=arr1.size();
    int n2=arr2.size();

    // finding the union of the two sorted arrays handling duplicates
    int i=0;
    int j=0;

    while (i<n1 && j<n2) {
        if (arr1[i]<arr2[j]) {
            std::cout<<arr1[i]<<" ";
            nextInd(arr1,n1,i);
        }else if (arr2[j]<arr1[i]) {
            std::cout<<arr2[j]<<" ";
            nextInd(arr2,n2,j);
        }else {
            std::cout<<arr1[i]<<" ";
            nextInd(arr1, n1, i);
            nextInd(arr2, n2, j);
        }
    }
    while (i<n1) {
        std::cout<<arr1[i]<<" ";
        nextInd(arr1, n1, i);
    }
    while (j<n2) {
        std::cout<<arr2[j]<<" ";
        nextInd(arr2, n2, j);
    }
}
