#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;
int main() {
    // in associative containers you can use .count method as a hack 
    // since map stores key value pair as a unique key 
    // hence the count of a perticular key in  a map can be either 0 or 1

    unordered_map<char, int>umap{{'A',1},{'B',2},{'C',3}};
    if (!umap.count('D')) {
        std::cout<<"D value is not present in the map "<<std::endl;
    }

    return 0;
}
// ----------------------------------------sorting the keys in discending order----------------------------------------
//
// struct descComparator{
//     bool operator()(const int &lhs,const int &rhs)const{
//         return lhs>rhs;
//     }
// };
// int main() {
//     map<int, int,descComparator>map{{5,10},{2,12},{6,15}}; // here template orgument for the template type 
//                                                        // parameter must be a type
//     for (auto it : map) {
//         std::cout<<it.first<<" "<<it.second<<std::endl;
//     }
//     return 0;
// }
