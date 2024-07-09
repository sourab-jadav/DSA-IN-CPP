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
void convertToLL(node* root,node**head){
    if (root==nullptr) {
        return;
    }
    static node* prev=nullptr;
    convertToLL(root->left, head);

    if (prev==nullptr) {
        *head=root;
    }else {
        prev->right=root;
        root->left=prev;
    }
    prev=root;
    convertToLL(root->right, head);
}
int main() {
  // Let us create the tree shown in above diagram
    node* root = new node(10);
    root->left = new node(12);
    root->right = new node(15);
    root->left->left = new node(25);
    root->left->right = new node(30);
    root->right->left = new node(36);
    node* head=nullptr;
    convertToLL(root, &head);

    while (head) {
        std::cout<<head->key<<std::endl;
        head=head->right;
    }

    return 0;
}


