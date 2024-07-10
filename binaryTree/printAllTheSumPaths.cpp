#include <deque>
#include <iostream>
#include <string>
#include <sys/types.h>
#include <vector>
using namespace std;
struct node {
    int key;
    node *left, *right;
    node(int k) {
        this->key = k;
        this->left = nullptr;
        this->right = nullptr;
    }
};
void solve(node* root,deque<int>&dq,int sum,int curr){
    if (root==nullptr) {
        return;
    }
    if (curr+root->key>sum) {
        return;
    }
    if (sum==curr+root->key) {
        dq.push_back(root->key);
        for (auto it=dq.begin(); it!=dq.end(); it++) {
            std::cout<<*it<<" ";
        }
        std::cout<<std::endl;
        return;
    }
    // at a particular element either we can select an element or we don't select an element
    // when we select it we pushback input the queue and we decrease the sum
    // when we don't select it we move either to left and right and perform the same operation
    // since negative numbers ar also possible
    //
    //  so we maintain a variable called curr

    dq.push_back(root->key);
    solve(root->left, dq, sum, curr+root->key);
    solve(root->right, dq, sum, curr+root->key);




}

int main() {
    int a = 45;
    node *root = new node(1);
    root->left = new node(3);
    root->left->left = new node(2);
    root->left->right = new node(1);
    root->left->right->left = new node(1);
    root->right = new node(-1);
    root->right->left = new node(4);
    root->right->left->left = new node(1);
    root->right->left->right = new node(2);
    root->right->right = new node(5);
    root->right->right->right = new node(2);
    deque<int>dq;
    int sum=5;
    solve(root, dq,  sum,0);

    return 0;
}
