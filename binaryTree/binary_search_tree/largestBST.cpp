#include <algorithm>
#include <iostream>
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

bool checkBST(node* root,node*& prev){
    if (root) {
        if (!checkBST(root->left,prev)) {
            return false;
        }
        if (prev!=nullptr && root->key < prev->key ) {
            return false;
        }
        prev=root;
        return checkBST(root->right, prev);
    }
    return true;
}



int main() {

struct node* root = new node(3);
    root->left = new node(2);
    root->right = new node(5);
    root->left->left = new node(1);
    root->left->right = new node(4);
    node* prev=nullptr;
    bool result=checkBST(root, prev);
    if (result) {
        std::cout<<"it is a binary tree"<<std::endl;
    }else {
        std::cout<<"it is not a binary tree"<<std::endl;
    }

}
