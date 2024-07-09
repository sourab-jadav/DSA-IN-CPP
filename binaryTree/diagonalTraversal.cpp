#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;
struct node{
    int key;
    node*left;
    node* right;
    node(int k){
        this->key=k;
        this->left=nullptr;
        this->right=nullptr;

    }
};
void diagnoalTraversal(node*root,int d,map<int, vector<int>>&m){
    if (!root) {
        return;
    }
    m[d].push_back(root->key);
    diagnoalTraversal(root->left, d+1, m);
    diagnoalTraversal(root->right , d, m);
}
int main() {
    node* root = new node(8);
    root->left = new node(3);
    root->right = new node(10);
    root->left->left = new node(1);
    root->left->right = new node(6);
    root->right->right = new node(14);
    root->right->right->left = new node(13);
    root->left->right->left = new node(4);
    root->left->right->right = new node(7);
    map<int, vector<int>>m;
    diagnoalTraversal(root,0,m);
    for(auto it=m.begin();it!=m.end();it++){
        for(int i=0;i<it->second.size();i++){
            std::cout<<it->second.at(i)<<" ";
        }
        std::cout<<std::endl;
    }
   return 0;
}


