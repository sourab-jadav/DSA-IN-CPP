#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#include <user_definations.h>

// std::vector<std::vector<int>> triplet(int n, std::vector<int> &arr) {
//   // reducing the loops to two
//   for (int i = 0; i < arr.size(); i++) {
//     std::set<int> hashset;
//     for (int j = i + 1; j < arr.size(); j++) {
//       int temp = -(arr[i] + arr[j]);
//       if (hashset.find(temp) != hashset.end()) {
//         std::vector<int> vec = {arr[i], arr[j], temp};
//         std::sort(vec.begin(), vec.end());
//       }
//       hashset.insert(temp);
//     }
//   }
//   return {{}};
// }
int main() {
  std::cout << "Hello, World!" << std::endl;
  std::vector<int>vec=genV(10);
  for (auto &x : vec) {
    std::cout<<x<<" ";
  }
  
  return 0;
}
