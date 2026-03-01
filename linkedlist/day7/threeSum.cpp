#include <iostream>
#include <iterator>
#include <vector>
#include <user_definations.h>

int main() {
  std::vector<int>vec=genV(50);
  std::cout << "hello world" << std::endl;
  std::cout<<std::endl;
  for (auto &x : vec) {
  std::cout<<x<<" ";
  }

  return 0;
}

