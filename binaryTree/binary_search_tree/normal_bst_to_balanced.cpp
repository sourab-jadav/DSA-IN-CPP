#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// the avl tree implemented here does self balancing on insertion
class bst {
    int data;
    bst *left;
    bst *right;
    public:
    bst();
    bst(int val);
    bst *insert(bst *root, int data);
    bst *insertAndBalance(bst* root,int data);
    void inorder(bst *root,bool left, bool right);
    void preorder(bst *root,bool left, bool right);
    bst *rightrotate(bst *root);
    bst *leftrotate(bst* root);
    bst *leftRightRotate(bst* root);
    bst *rightLeftRotate(bst* root);
    int getHeight(bst* root);
};
int bst::getHeight(bst* root){
    if (!root) {
        return 0;
    }
    return 1+max(getHeight(root->left),getHeight(root->right));
}
void bst::preorder(bst* root,bool left,bool right){
    if (root==nullptr) {
        return;
    }
    if (left) {
        std::cout<<"left -> "<<root->data<<std::endl; // this is a good way to understand 
                                                      // the binary tree structure
    }else if (right) {
        std::cout<<"right -> "<<root->data<<std::endl;
    }else {
        std::cout<<"root -> "<<root->data<<std::endl;
    }
    preorder(root->left,true,false);
    preorder(root->right,false,true);
}
bst::bst() {
    this->data = 0;
    this->left = nullptr;
    this->right = nullptr;
}

bst::bst(int val) {
    this->data = val;
    this->left = nullptr;
    this->right = nullptr;
}
void bst::inorder(bst *root,bool left,bool right) {
    if (root == nullptr) {
        return;
    }
    inorder(root->left,true,false);
    if (left) {
        std::cout<<"left -> "<<root->data<<std::endl; // this is a good way to understand 
                                                      // the binary tree structure
    }else if (right) {
        std::cout<<"right -> "<<root->data<<std::endl;
    }else {
        std::cout<<"root -> "<<root->data<<std::endl;
    }
    inorder(root->right,false,true);
}
bst *bst::insert(bst *root, int data) {
    if (!root) {
        return new bst(data);
    }
    if (root->data == data) { // in bst duplicates are not allowed
        return root;
    }
    if (root->data > data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}
bst *bst::insertAndBalance(bst* root,int data){
    // let's insert by balancing the tree structre
    bst c;
    bst* x_root=c.insert(root, data);
    int left_height=getHeight(x_root->left);
    int right_height=getHeight(x_root->right);
    if (abs(left_height-right_height)>1) {
        if (left_height>right_height) {
            if (x_root->left and x_root->left->left) {
                x_root=leftrotate(root);
            }else if (x_root->left and x_root->left->right) {
                x_root=leftRightRotate(root);
            }
        }else {
            if (x_root->right and x_root->right->right) {
                x_root=rightrotate(root);
            }else if (x_root->right and x_root->right->left) {
                x_root=rightLeftRotate(root);
            }
        }
    }
    return x_root;
}
bst *bst::rightrotate(bst *root) {
    if (root->left && root->left->right) {
        bst *temp = root->left->right;
        root->left->right = root;
        bst *temp1= root->left;
        root->left=nullptr;
        root=temp1;
        root->right->left = temp;
    } else {
        root->left->right=root;
        bst* temp=root->left;
        root->left=nullptr;
        root=temp;
    }
    return root;
}
bst *bst::leftrotate(bst* root){
    if (root->right && root->right->left) {
        bst *temp = root->right->left;
        root->right->left = root;
        bst *temp1= root->right;
        root->right=nullptr;
        root=temp1;
        root->left->right = temp;
    } else {
        root->right->left=root;
        bst* temp=root->right;
        root->right=nullptr;
        root=temp;
    }
    return root;
}
// https://www.notion.so/avl-tree-64d21adfbd8b4306949e8fca83393bc3?pvs=4#03fdc3fd599543fbafdf33a4d5e45ffb
// let's do left right and right left rotation together
bst* bst::rightLeftRotate(bst* root){
    bst c;
    bst* x_root=c.rightrotate(root->right);
    x_root=c.leftrotate(root);
    return x_root;
}
bst* bst::leftRightRotate(bst* root){
    bst c;
    bst* x_root=c.leftrotate(root->left);
    root->left=x_root;
    x_root=c.rightrotate(root);
    return x_root;
}

int main() {
    // vector<int> vec{10,5,1,6,7}; // use this to check right rotate
    // vector<int>vec{1,10,50,18,7,8} // use this to check left rotate
    vector<int>vec{10,1,2}; // take an example for  left right rotate
    bst c;
    bst *root = nullptr;
    for (auto v : vec) {
        root = c.insertAndBalance(root, v);
    }
    c.preorder(root,false,false);
    // root=c.leftRightRotate(root);
    // c.preorder(root, false, false);
    return 0;
}
