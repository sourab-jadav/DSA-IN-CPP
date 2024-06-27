#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <utility>
#include <vector>
#include <string>
using namespace std; // [ difficult_strings ]
// int main() {
//     string str="aaaaabbbcd";
//     map<char, int>umap; // it sorts by default by first element 
//     for(auto c:str){
//         umap[c]++;
//     }
//     vector<pair<char, int>>vec(umap.begin(),umap.end());
//     for(auto x:vec){
//         std::cout<<x.first<<" "<<x.second<<std::endl;
//     }
//     std::cout<<"after the sorting is being done"<<std::endl;
//     sort(vec.begin(),vec.end(),[](pair<char, int> p1,pair<char, int>p2){ return p1.second>p2.second; });
//     int n=vec.size();
//     int count=0;
//     for(int i=1;i<n;i++){
//         count+=vec[i].second;
//     }
//     // here for n a's which has the highest count 
//     // we atleast require n-1 other characters
//     // or else the answer is not possible
//     int max_freq_char_count=vec[0].second;
//     if (count<max_freq_char_count-1) {
//         std::cout<<"not possible"<<std::endl;
//         return 0;
//     }
//     int sum=0;
//     for(int i=0;i<n;i++){
//         sum+=vec[i].second;
//     }
//
//     // if right size is less than left size -1  then it is not possible
//
//     string result="";
//     for(int i=0;i<n;i+=2){
//         int left_size=vec[i].second;
//         int right_size=sum-vec[i].second;
//         if (right_size<left_size-1) {
//             std::cout<<"not possible exiting11"<<std::endl;
//             return 0;
//         }
//         int j=i,k=i+1;
//         while (j<i+left_size-1) {
//             if (j<n && vec[j].second>0 && k<n) {
//                 result+=vec[j].first;
//                 if (vec[k].second>0) {
//                     result+=vec[k].first;
//                     vec[k].second--;
//                 }else {
//                     k++;
//                     result+=vec[k].first;
//                     vec[k].second--;
//                 }
//
//             }
//         } // this is getting so much still need to work on this not sure about the solution [ not sure ]
//
//
//         sum=sum-vec[i].second;
//     }
//     return 0;
// }



