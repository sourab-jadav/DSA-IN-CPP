#include <deque>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct node {
  node *left;
  node *right;
  int data;
  node(int n) {
    this->data = n;
    left = nullptr;
    right = nullptr;
  }
};
// printing root to leaf path using the pre-order traversal
deque<int>q;
bool flag=true;
void printRootToLeaf(node* current){
    if (current==nullptr) {
        if (flag) {
            for (auto it=q.begin(); it!=q.end(); it++) {
                std::cout<<*it<<" ";
            }
            std::cout<<std::endl;
            flag=!flag;
            return ;
        }else {
            flag=!flag;
            return;
        }

    }
    q.push_back(current->data);
    printRootToLeaf(current->left);
    printRootToLeaf(current->right);
    q.pop_back();
}
int main() {
    // binary tree data
  node *root = new node(1);
  root->left = new node(2);
  root->right = new node(3);
  root->left->left = new node(4);
  root->left->right = new node(5);
  root->right->left = new node(6);
  root->right->right = new node(7);
  root->left->left->left = new node(8);
  root->left->left->right = new node(9);
  root->left->right->left = new node(10);
  root->left->right->right = new node(11);
  root->right->left->left=new node(12);
  root->right->left->right=new node(13);
    printRootToLeaf(root);
  return 0;
}
