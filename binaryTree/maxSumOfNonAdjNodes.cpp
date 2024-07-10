#include <iostream>
#include <string>
#include <vector>
using namespace std;
// https://www.geeksforgeeks.org/maximum-sum-nodes-binary-tree-no-two-adjacent/
struct node { // this is the working solution 
  int key;
  node *left, *right;
  node(int k) {
    this->key = k;
    this->left = nullptr;
    this->right = nullptr;
  }
};
// to solve maximum sum of nodes in binary tree
// the cache is that if a node is choosen it's adjacent nodes which are directly
// connected to it cannot be choosen at each node we have two options we can
// select a node or we don't select a node

int solve(node *root) {
  // we think of basecase later

    if (root==nullptr) {
        return 0;
    }
    if (root->left==nullptr and root->right==nullptr) {
        return root->key;
    }

  return max(
      ( // if selected
          root->key +
          (root->left && root->left->left ? solve(root->left->left) : 0) +
          (root->left && root->left->right ? solve(root->left->right) : 0) +
          (root->right && root->right->right ? solve(root->right->right) : 0) +
          (root->right && root->right->left ? solve(root->right->left) : 0)),
          ( // if not selected
            solve(root->left)+solve(root->right)
          )
      );
}

int main() {
node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->right->left = new node(4);
    root->right->right = new node(5);
    root->left->left = new node(1);
  int result = solve(root);
  std::cout << result << std::endl;
  return 0;
}
