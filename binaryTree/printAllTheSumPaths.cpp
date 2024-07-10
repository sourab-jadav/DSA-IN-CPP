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
void printPath(vector<int>&vec,int j){
    for(int i=j;i<vec.size();i++){
        std::cout<<vec[j]<<" ";
    }
    std::cout<<std::endl;

}
void solve(node* root,vector<int>&vec,int sum){
    // final implimentation 
    // ingredients to solve the problem
    //
    // 1 vector to store the path
    //
    if (!root) {
        return ;
    }
    vec.push_back(root->key);
    solve(root->left, vec, sum);
    solve(root->right, vec, sum);
    int f=0;
    for(int j=vec.size()-1;j>=0;j--){
        f+=vec[j];
        if (f==sum) {
            printPath(vec, j);
            
        }
    }
    vec.pop_back();
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
    vector<int>vec;
    int sum=5;
    solve(root, vec, sum);

    return 0;
}
