#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
// using for_each to print the elements 

// function to double an integer
struct Double{
    void operator()(int &n)const {
        n*=2;
    }
};




int main() {
    std::cout << "Hello, World!" << std::endl;
    vector<vector<int>>vec1{
        {1,2,3,4}
    };
    vector<vector<int>>vec2{
        {1,2,3,4}
    };

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
  // passing function to the for_each



  vector<int> temp{1,2,3,4,5,6};
  std::cout<<"before:"<<std::endl;
  for_each(temp.begin(),temp.end(),[](int n){
          std::cout<<n<<" ";
          });
  std::cout<<std::endl;
  for_each(temp.begin(),temp.end(),Double());
  std::cout<<"after"<<std::endl;
  for_each(temp.begin(),temp.end(),[](int n){
          std::cout<<n<<" ";
          });




    return 0;
}


