#include <iostream>
#include <vector>
#include <string>
using namespace std;
// https://www.geeksforgeeks.org/lowest-common-ancestor-binary-tree-set-1/
struct node{
    int key;
    node* left;
    node* right;
    node(int k){
        this->key=k;
        this->left=nullptr;
        this->right=nullptr;
    }
};
// finding lca invloves finding the paths from root to the nodes
// traversing the paths from the bottom until the values are equal

int main() {
  node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}


