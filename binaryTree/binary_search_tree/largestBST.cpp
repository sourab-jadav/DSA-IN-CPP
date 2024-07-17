#include <algorithm>
#include <ios>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// this is very very important
// when you write a code and it is not working the problem is with how you think
// learn and improve the skill of how you think
struct node {
    int key;
    node *left, *right;
    node(int k) {
        this->key = k;
        this->left = nullptr;
        this->right = nullptr;
    }
};
int result = 0;
int findLargestBst(node *root) { //  this is wrong solution
    if (root == nullptr) {
        return 1;
    }
    int left;
    int right;
    if (root->left && root->key > root->left->key) {
        left = 1 + findLargestBst(root->left);
    } else {
        left = findLargestBst(root->left);
    }
    if (root->right && root->key > root->right->key) {
        right = 1 + findLargestBst(root->right);
    } else {
        right = findLargestBst(root->right);
    }
    return max(left, right);
}
// int findLargestBst( node *root) {
//     return 0;
// }



// bool checkIfBinarySearchTree(node *root) { // this is  a wrong solution you thought 
//                                            // that root->val should be greater than 
//                                            // only root->left->val 
//                                            // but the thing is it should be greater than whole
//                                            // the left subtree combined
//     if (root == nullptr) {
//         return true;
//     }
//     bool left;
//     bool right;
//     if (root->left) {
//         if (root->key > root->left->key) {
//             left = checkIfBinarySearchTree(root->left);
//         } else {
//             return false;
//         }
//     } else {
//         left = true;
//     }
//
//     if (root->right) {
//         if (root->key < root->right->key) {
//             right = checkIfBinarySearchTree(root->right);
//         } else {
//             return false;
//         }
//     } else {
//         right = true;
//     }
//
//     return left && right;
// }

// the important thing to understand here is in the left recursive call we are 
// considering the current root value as the previous and recursively comparing on the left side that 
// current root value should be less than previous value
//
// let's do the preorder traversal to compare the elements and pass the current root value to the left recursive call 
// and then the right 





int main() {
    // node *root = new node(6);
    // root->left = new node(6);
    // root->right = new node(2);
    // root->right->right = new node(3);
    // root->right->right->right = new node(4);
    // root->right->left = new node(1);
    // root->left->right = new node(2);
    // int result = findLargestBst(root);
    // struct node* root = new node(4);
    // root->left = new node(2);
    // root->right = new node(5);
    // // root->right->left = new node(7);
    // root->left->left = new node(1);
    // root->left->right = new node(3);
struct node* root = new node(3);
    root->left = new node(2);
    root->right = new node(5);
    root->left->left = new node(1);
    root->left->right = new node(4);
    // bool result=checkIfBinarySearchTree(root);
    std::cout << "the result is " << result << std::endl;
}
