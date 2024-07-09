#include <ios>
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <string>


using namespace std;

// we have solved three problems here 


// structure we define here
struct node{
    int key;
    node*left,*right;
    node(int k){
        this->key=k;
        this->left=nullptr;
        this->right=nullptr;
    }
};
// ingredients we need to to solve this problem
// map passed as reference
// fd varaiable
// void verticalOrder(node* root,int fd,map<int, vector<int>>&m){ // this is printing vertical order traversal from top to bottom
void verticalOrder(node* root,int fd,map<int, queue<int>>&m){ // this printing top view if we use front method because
                                                              // in queue we push from back and pop from front
                                                              // if we use back method this will print bottom view of the tree
    if (root==nullptr) {
        return;
    }
    // m[fd].push_back(root->key);
    m[fd].push(root->key);
    verticalOrder(root->left, fd-1, m);
    verticalOrder(root->right, fd+1, m);
}
// lef's say you want to print the 2 vertical line from the left you can also do that 
// void verticalOrderOfIthLine(node* root,int fd,vector<int>&result,int i){
//     if (root==nullptr) {
//         return;
//     }
//     if (fd==i) {
//         result.push_back(root->key);
//     }
//     verticalOrderOfIthLine(root->left, fd+1, result, i);
//     verticalOrderOfIthLine(root->right, fd-1, result, i);
// }

int main() {
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    root->right->left->right = new node(8);
    root->right->right->right = new node(9);
    map<int, queue<int>>m;
    // map<int, vector<int>>m;
    verticalOrder(root, 0, m);

    // // m.clear(); // removes all the elements from the map
    // vector<int>result;
    // // verticalOrderOfIthLine(root, 0, result,0);
    // while (!result.empty()) {
    //     std::cout<<result.back()<<std::endl;
    //     result.pop_back();
    // }
    // for(auto it=m.begin();it!=m.end();it++){
    //     for(int i=0;i<it->second.size();i++){
    //         std::cout<<it->second.at(i)<<" ";
    //     }
    //     std::cout<<std::endl;
    // }
    for(auto it=m.begin();it!=m.end();it++){
        std::cout<<it->second.front()<<std::endl;
    }
    //
    // now that vertical order is printed 
    return 0;
}


