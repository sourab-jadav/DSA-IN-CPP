
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;
    Node(int key)
    {
        this->key = key;
        left = right = nullptr;
    }
};
int preindex = 0;
Node *function(vector<int> &preorder, vector<int> &inorder, int low, int high)
{
    if (low > high)
    {
        return nullptr;
    }
    Node *root = new Node(preorder[preindex++]);
    int index;
    for (int i = low; i <= high; i++)
    {
        if (inorder[i] == root->key)
        {
            index = i;
            break;
        }
    }
    root->left = function(preorder, inorder, low, index - 1);
    root->right = function(preorder, inorder, index + 1, high);
    return root;
}
void preorderfunc(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    cout << root->key << " ";
    preorderfunc(root->left);
    preorderfunc(root->right);
}
int main()
{
    vector<int> preorder{3, 9, 20, 15, 7};
    vector<int> inorder{9, 3, 15, 20, 7};
    Node *root = function(preorder, inorder, 0, preorder.size() - 1);
    preorderfunc(root);
    return 0;
}