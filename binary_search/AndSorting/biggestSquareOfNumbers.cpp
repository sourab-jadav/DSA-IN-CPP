#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// okay hold it is pretty simple
// you have two rectangles you need to find biggest identical square possible


// not working for some reason
void print(int n){
    std::cout<<n<<" ";
}
bool areEqual(const vector<vector<int>>&v1,const vector<vector<int>>&v2,int x1,int y1,int x2,int y2,int sz){
    for(int i=0;i<sz;i++){
        for(int j=0;j<sz;j++){
            if (v1[x1+i][y1+j]!=v2[x2+i][y2+j]) {
                return false;
            }
        }
    }
    return true;
}


bool solve(const vector<vector<int>>&v1,const vector<vector<int>>&v2,int size,int &ax,int &ay){
    // mistake in how you think
    // here you are comparing v1 matrix with v2 matrix 
    // 
    int n=v1.size();
    int m=v1[0].size();
    for(int i=0;i<=n-size;i++){
        for(int j=0;j<=m-size;j++){
            for(int k=0;k<=v2.size()-size;k++){
                for(int l=0;l<=v2[0].size()-size;l++){
                    if (areEqual(v1, v2, i, j,k,l, size)) {
                        ax=i;
                        ay=j;
                        return true;
                    }
                }
            }
        }
    }
    return false;
}


// here if you can understand the question you will see that 
// if there is a match with matrix of size n then 
// then there will be definately be a identical matrix of size n-1
//
// you can see that the size of the identical matrix is a monotonic function 
// so you apply binary search on the size of the matrix

int main() {
  vector<vector<int>> vec1{
      {750, 77, 796, 655, 974, 982, 895, 330, 173, 279},
      {222, 799, 461, 798, 709, 659, 620, 581, 516, 427},
      {160, 911, 73, 225, 191, 887, 480, 16, 537, 59},
      {868, 272, 776, 827, 972, 986, 836, 307, 162, 175},
      {238, 405, 423, 667, 138, 121, 720, 791, 227, 213},
      {148, 346, 890, 772, 33, 316, 456, 979, 775, 440},
      {899, 255, 579, 114, 888, 749, 580, 682, 776, 454},
      {262, 495, 502, 89, 381, 693, 503, 867, 965, 52},
      {558, 661, 535, 465, 507, 10, 776, 23, 956, 481},
      {46, 9, 629, 884, 132, 359, 739, 874, 463, 167},
  };

  vector<vector<int>> vec2{
      {978, 165, 458, 77, 796, 655, 974, 982, 665, 756},
      {133, 887, 480, 16, 537, 59, 899, 255, 772, 171},
      {793, 986, 836, 307, 162, 175, 262, 495, 114, 5},
      {807, 121, 720, 791, 227, 213, 288, 502, 89, 12},
      {907, 316, 456, 979, 775, 440, 740, 902, 581, 137},
      {92, 749, 580, 682, 776, 454, 33, 852, 22, 700},
      {912, 799, 461, 798, 709, 544, 888, 8, 499, 460},
      {308, 911, 73, 225, 191, 775, 381, 693, 881, 182},
      {503, 272, 776, 827, 972, 819, 990, 141, 544, 239},
      {776, 405, 423, 667, 138, 151, 879, 496, 505, 856},
  };

  int low=1;
  int n=vec1.size();
  int m=vec1[0].size();
  int high=min(n,m);
  int result_size=0;
  int ax=0,ay=0;

  while (low<=high) {
    // int mid=(low+(high-low))/2; // this is where you made mistake
    int mid=low+(high-low)/2; // this is where you made mistake
    if (solve(vec1, vec2, mid,ax,ay)) {
        result_size=mid;
        low=mid+1;
    }else {
        high=mid-1;
    }
    std::cout<<"this is running"<<std::endl;
  }

  std::cout<<"the result ax: "<<ax<<" ay: "<<ay<<std::endl;
  return 0;
}


// printing with lamda's
// z

// for_each(vec1.begin(),vec1.end(),[](vector<int>&v){
//         for_each(v.begin(),v.end(),[](int x){
//                 std::cout<<x<<" ";
//                 });
//         std::cout<<std::endl;
//         });
// std::cout<<"----------------------------------------"<<std::endl;
// for_each(vec2.begin(),vec2.end(),[](vector<int>&v){
//         for_each(v.begin(),v.end(),[](int x){
//                 std::cout<<x<<" ";
//                 });
//         std::cout<<std::endl;
//         });

// get the size of one column
//

// first task is matching the squares of that size if the elements are equal or not


// original solution to the problem
// #include <iostream>
// #include <vector>
// #include <algorithm>
//
// using namespace std;
//
// // Function to check if two squares of size 'size' starting at (x1, y1) in matA and (x2, y2) in matB are identical
// bool isIdenticalSquare(const vector<vector<int>>& matA, const vector<vector<int>>& matB, int x1, int y1, int x2, int y2, int size) {
//     for (int i = 0; i < size; ++i) {
//         for (int j = 0; j < size; ++j) {
//             if (matA[x1 + i][y1 + j] != matB[x2 + i][y2 + j]) {
//                 return false;
//             }
//         }
//     }
//     return true;
// }
//
// // Function to check if there's an identical square of given size in the matrices
// bool hasIdenticalSquareOfSize(const vector<vector<int>>& matA, const vector<vector<int>>& matB, int size, int &ax, int &ay) {
//     int n = matA.size();
//     int m = matA[0].size();
//     for (int i = 0; i <= n - size; ++i) {
//         for (int j = 0; j <= m - size; ++j) {
//             for (int k = 0; k <= n - size; ++k) {
//                 for (int l = 0; l <= m - size; ++l) {
//                     if (isIdenticalSquare(matA, matB, i, j, k, l, size)) {
//                         ax = i;
//                         ay = j;
//                         return true;
//                     }
//                 }
//             }
//         }
//     }
//     return false;
// }
//
// int main() {
//     // Define the matrices
//     vector<vector<int>> matA = {
//         {750,  77, 796, 655, 974, 982, 895, 330, 173, 279},
//         {222, 799, 461, 798, 709, 659, 620, 581, 516, 427},
//         {160, 911,  73, 225, 191, 887, 480,  16, 537,  59},
//         {868, 272, 776, 827, 972, 986, 836, 307, 162, 175},
//         {238, 405, 423, 667, 138, 121, 720, 791, 227, 213},
//         {148, 346, 890, 772,  33, 316, 456, 979, 775, 440},
//         {899, 255, 579, 114, 888, 749, 580, 682, 776, 454},
//         {262, 495, 502,  89, 381, 693, 503, 867, 965,  52},
//         {558, 661, 535, 465, 507,  10, 776,  23, 956, 481},
//         { 46,   9, 629, 884, 132, 359, 739, 874, 463, 167}
//     };
//
//     vector<vector<int>> matB = {
//         {978, 165, 458,  77, 796, 655, 974, 982, 665, 756},
//         {133, 887, 480,  16, 537,  59, 899, 255, 772, 171},
//         {793, 986, 836, 307, 162, 175, 262, 495, 114,   5},
//         {807, 121, 720, 791, 227, 213, 288, 502,  89,  12},
//         {907, 316, 456, 979, 775, 440, 740, 902, 581, 137},
//         { 92, 749, 580, 682, 776, 454,  33, 852,  22, 700},
//         {912, 799, 461, 798, 709, 544, 888,   8, 499, 460},
//         {308, 911,  73, 225, 191, 775, 381, 693, 881, 182},
//         {503, 272, 776, 827, 972, 819, 990, 141, 544, 239},
//         {776, 405, 423, 667, 138, 151, 879, 496, 505, 856}
//     };
//
//     int n = matA.size();
//     int m = matA[0].size();
//     int left = 1, right = min(n, m), resultSize = 0;
//     int ax = 0, ay = 0;
//
//     // Binary search for the largest size of the identical square
//     while (left <= right) {
//         int mid = left + (right - left) / 2;
//         if (hasIdenticalSquareOfSize(matA, matB, mid, ax, ay)) {
//             resultSize = mid;
//             left = mid + 1;
//         } else {
//             right = mid - 1;
//         }
//     }
//
//     // Output the result
//     if (resultSize > 0) {
//         cout << "The largest identical square of size " << resultSize << " is:\n";
//         for (int i = 0; i < resultSize; ++i) {
//             for (int j = 0; j < resultSize; ++j) {
//                 cout << matA[ax + i][ay + j] << " ";
//             }
//             cout << endl;
//         }
//     } else {
//         cout << "No identical square found.\n";
//     }
//
//     return 0;
// }
