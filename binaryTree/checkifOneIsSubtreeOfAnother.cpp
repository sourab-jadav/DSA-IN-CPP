#include <cmath>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
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
bool isSubtree(node* root1,node* root2){
    if (root1==nullptr && root2==nullptr) {
        return true;
    }else if (root1==nullptr || root2==nullptr) {
        return false;
    }
    if (root1->key==root2->key) {
        return isSubtree(root1->left, root2->left) and isSubtree(root1->right, root2->right);
    }else {
        return isSubtree(root1->left, root2) or isSubtree(root1->right, root2);
    }
    return false;
}
int main() {
  node* T = new node(26);
    T->right = new node(3);
    T->right->right = new node(3);
    T->left = new node(10);
    T->left->left = new node(4);
    T->left->left->right = new node(30);
    T->left->right = new node(6);
 
    // TREE 2
    /* Construct the following tree
        10
        / \
    4 6
    \
        30
    */
    node* S = new node(10);
    S->right = new node(6);
    S->left = new node(4);
    S->left->right = new node(30);
 
    if (isSubtree(T, S))
        cout << "Tree 2 is subtree of Tree 1";
    else
        cout << "Tree 2 is not a subtree of Tree 1";
 
    return 0;
}


