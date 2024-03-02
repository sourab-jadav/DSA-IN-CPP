#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
int solve(vector<int>&stones,int sum,int n){
    if (n<=0) {
        return 0;
    }
    if (sum-stones[n-1]<0) {
        return solve(stones, sum, n-1);
    }
    // now to find the max sum you either consider the element by subtracting or you don't consider the element and find the max

    else {
        return max(solve(stones, sum, n-1),solve(stones, sum-stones[n-1], n-1)+stones[n-1]);
    }
}

int main() {
    std::vector<int>stones = {9,9,9};
    //find the sum of all the elements with less code
    //using the accumulate function
    int sum=accumulate(stones.begin(),stones.end(),0);
    int n=(int)stones.size();
    sum=14;
    std::cout<<"sum is "<<sum<<std::endl;
    std::cout<<solve(stones, sum, n)<<std::endl;
    //learning find function in cpp to find the element in the vector 
    //if the element is not found then it returns the end of the vector
    return 0;
}


