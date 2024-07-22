#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
// ----------------------------------------xor operation----------------------------------------
// 0 xor n is always n 
// n xor n is always 0
// 
// there is one trick often used in xor operation 
// say after performing xor on arr 
// you got the result as a1 ^ a2
//
// now what would you do to sperate a1 and a2 
//
// to do this we acquire the right most set bit of the result(a1^a2)
// set bit=x& ~(x-1)
//
// now divide the array elements into two groups  using the set bit
// in which one group contains a1 and and another group contains a2
// binary_search/AndSorting/repeatingAndMissing.cpp 
//
// int main() {
//     int n=45;
//     std::cout<<(0^n)<<std::endl;
//     return 0;
// }
//

// ----------------------------------------lowerbound,upperbound----------------------------------------
//
static constexpr int kn=1e5;
#define long long ll;
int main(){
    int arr[]={10,25,28,44,60,82};
    int n=sizeof(arr)/sizeof(arr[0]);
    std::cout<<"the value os n is "<<n<<std::endl;
    std::cout<<"getting the value of lowerbound"<<std::endl;
    auto it=lower_bound(arr,arr+n,44); // lowerbound returns the iterator pointing to the 
                                       // first element greater than or equal to the val

    std::cout<<*it<<std::endl;       // upper_bound returns the iterator pointing to the 
                                     // the first element greater than the val
                                     //
    // auto it2=upper_bound(arr,arr+n,82); // this returns a garbase value
    // std::cout<<*it2<<std::endl;



}
