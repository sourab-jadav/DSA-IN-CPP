#include <algorithm>
#include <iostream>
#include <string>
#include <tuple>
#include <unordered_map>
#define IOS ios::sync_with_stdio(0);
// creating trie data structure
// what you need
class TreeNode {
public:
  std::unordered_map<char, TreeNode *> children;
  bool isEndOfword;
  TreeNode() { isEndOfword = false; }
};
// search operation
bool search(TreeNode *root, std::string &str) {
  for (auto &x : str) {
    if (root->children.find(x) == root->children.end())
      return false;
    root = root->children[x];
  }
  return root->isEndOfword;
}

// print operation
// we are doing the depth first search operation
void print(TreeNode *node, std::string currentword) {
  if (node->isEndOfword) {
    std::cout << currentword << std::endl;
  }
  for (const auto &pair : node->children) {
    print(pair.second, currentword + pair.first);
  }
}
int main() {
  std::cout << "hello world" << std::endl;
  std::cout << "enter the string" << std::endl;
  std::string str = "hello";
  TreeNode *root = new TreeNode();
  TreeNode *base = root;
  for (auto x : str) {
    if (root->children.find(x) == root->children.end()) {
      root->children[x] = new TreeNode();
    }
    root = root->children[x];
  }
  root->isEndOfword = true;
  print(base, "");
  return 0;
}
