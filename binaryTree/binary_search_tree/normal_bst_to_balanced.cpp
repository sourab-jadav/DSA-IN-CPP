#include <iostream>
#include <string>
#include <vector>
using namespace std;
class bst {
    int data;
    bst *left;
    bst *right;
    public:
    bst();
    bst(int val);
    bst *insert(bst *root, int data);
    void inorder(bst *root,bool left, bool right);
    void preorder(bst *root,bool left, bool right);
    bst *rightrotate(bst *root);
    bst *leftrotate(bst* root);
};
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


int main() {
    vector<int> vec{10,5,1,6,7}; // use this to check right rotate
    // vector<int>vec{1,10,50,18,7,8} // use this to check left rotate
    bst c;
    bst *root = nullptr;
    for (auto v : vec) {
        root = c.insert(root, v);
    }
    c.preorder(root,false,false);
    root=c.rightrotate(root);
    std::cout<<std::endl;
    c.preorder(root,false,false);
    return 0;
}
