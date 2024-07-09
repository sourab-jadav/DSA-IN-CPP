#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;
struct node{
    char key;
    node* left;
    node* right;
    node(char k){
        this->key=k;
        this->left=nullptr;
        this->right=nullptr;
    }
};
// we maintain a static variable that keeps track of current element in an array
node* buildTree(char in[],char pre[],int start,int end,map<char, int>&mp){
    if (start>end) {
        return nullptr;
    }
    static int preindex=0;
    node* root= new node(pre[preindex++]);
    if (start==end) {
        return root;
    }
    int idx=mp[root->key];
    buildTree(in, pre, start, idx-1, mp);
    buildTree(in, pre, idx+1, end, mp);
    return root;
}

int main() {
    char in[] = { 'D', 'B', 'E', 'A', 'F', 'C' }; 
    char pre[] = { 'A', 'B', 'D', 'E', 'C', 'F' }; 
    int len = sizeof(in) / sizeof(in[0]); 
    // we also need to find the index of each node
    // mapping each of the element to it's index in in[]

    map<char, int>mp;
    for(int i=0;i<len;i++){
        mp[in[i]]=i;
    }

 

    



    /* Let us test the built tree by 
    printing Inorder traversal */
    cout << "Inorder traversal of the constructed tree is \n"; 
    return 0;
}


