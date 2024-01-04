#include <algorithm>
#include <climits>
#include <iostream>
// you forgot the intuition in this problem and blindly solved it
//The intuition behind the approach is taking different bars and finding the maximum width possible using the bar.

int main() {
    int heights[]={2,1,5,6,2,3};
    int n=sizeof(heights)/sizeof(heights[0]);
    // finding the maximum area possible
    // bruteforce solution
    int area=INT_MIN;
    for(int i=0;i<n;i++){
        int height=INT_MAX;
        for(int j=i;j<n;j++){
            height=std::min(height,heights[j]);
            int width=j-i+1;
            area=std::max(area,height*width);
        }
    }



    return 0;
}


