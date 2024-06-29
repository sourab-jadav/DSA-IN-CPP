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


