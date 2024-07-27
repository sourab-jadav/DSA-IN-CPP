#include <iostream>
#include <string>
#include <vector>
using namespace std;
// let's create a binary search tree data structure that performs insert
// operation
class bst {
    // what can be the properties
    private:
        int data;
        bst *left;
        bst *right;

    public:
        bst();
        bst(int val);
        bst *insert(bst *root, int data);
        void inorder(bst *root);
        bool remove(bst* root,int data,bst*& prev,bool left,bool right);
};
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

void bst::inorder(bst *root) {
    if (root == nullptr) {
        return;
    }
    inorder(root->left);
    std::cout << root->data << " ";
    inorder(root->right);
}
bool bst::remove(bst *root,int data,bst* &prev,bool left,bool right){  // this logic is 
                                                                       // working
    if (root==nullptr) {
        return false;
    }
    if (root->data==data) {
        if (prev!=nullptr) {
            if (left) {
                bst* temp=root;
                if (root->right!=nullptr) {
                    prev->left=temp->right;
                    prev->left->left=temp->left;
                }else {
                    prev->left=root->left;
                }
                delete temp;
                return true;
            }else if (right) {
                bst* temp=root;
                if (root->left!=nullptr) {
                    prev->right=temp->left;
                    prev->right->right=temp->right;
                }else {
                    prev->right=root->right;
                }
                delete temp;
                return true;
            }
        }
    }
    else if (root->data>data) {
        prev=root;
        return  remove(root->left, data, prev, true, false);
    }else {
        prev=root;
        return remove(root->right, data, prev, false, true);
    }
    return false;
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



int main() {
    // insert delete operations on binary search tree
    bst c;
    bst *root = nullptr;
    vector<int> vec{10, 500, 40, 20, 30, 100, 500,7,8,1,25,28};
    for (auto v : vec) {
        root = c.insert(root, v);
    }
    c.inorder(root);
    int data;
    std::cout<<"enter data to be deleted"<<std::endl;
    cin>>data;
    bst* prev=nullptr;
    c.remove(root, data, prev, false, false);
    std::cout<<std::endl;
    c.inorder(root);
    return 0;
}
