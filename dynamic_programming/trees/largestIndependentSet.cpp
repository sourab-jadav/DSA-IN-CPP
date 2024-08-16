#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
// https://www.geeksforgeeks.org/largest-independent-set-problem-using-dynamic-programming/
struct node {
    int key;
    node *left, *right;
    node(int k) {
        this->key = k;
        this->left = nullptr;
        this->right = nullptr;
    }
};
int liss(node* root){
    if (!root) {
        return 0;
    }
    // the idea is if we take it we cannot consider it's adjacent nodes
    int take=1+(root->left?liss(root->left->left)+liss(root->left->right):0)+
        (root->right?liss(root->right->right)+liss(root->right->left):0);
    int nottake=liss(root->left)+liss(root->right);
    return max(take,nottake);
}


int main() {
 node *root = new node(20); 
    root->left = new node(8); 
    root->left->left = new node(4); 
    root->left->right = new node(12); 
    root->left->right->left = new node(10); 
    root->left->right->right = new node(14); 
    root->right = new node(22); 
    root->right->right = new node(25); 
    // preorder(root, false, false);
    int result=liss(root);
    std::cout<<result<<std::endl;
    return 0;
}
