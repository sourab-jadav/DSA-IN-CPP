#include <iostream>
#include <vector>
std::vector<std::vector<int>> result;
void solve(std::vector<int> temp, std::vector<int> init, int i, int target) {
  if (target == 0) {
    result.push_back(temp);
  } else if (target - init[i] > 0) {
    for (int j = i; j < (int)init.size(); j++) {
      temp.push_back(init[j]);
      solve(temp, init, j, target - init[j]);
      temp.pop_back();
    }
  }
}
int main() {
  std::vector<int> vec{2};
  int target = 1;
  std::vector<int> temp;
  solve(temp, vec, 0, target);
  for (auto &x : result) {
    std::cout << "["
              << " ";
    for (auto &y : x) {
      std::cout << y << " ";
    }
    std::cout << "]"
              << " ";
  }

  return 0;
}
