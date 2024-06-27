#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

int main() {
    std::multimap<int, std::string> mmap;

    // Inserting values
    mmap.insert({1, "apple"});
    mmap.insert({1, "banana"});
    mmap.insert({2, "carrot"});
    mmap.insert({2, "date"});
    mmap.insert({1, "apricot"});

    // Iterating through the multimap
    // for (const auto& pair : mmap) {
    //     std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    // }


    return 0;
}

