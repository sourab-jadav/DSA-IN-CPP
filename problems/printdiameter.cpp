#include <iostream>

using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node(int k) : val(k), left(nullptr), right(nullptr){};
};

int height(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    else
        return 1 + max(height(root->left), height(root->right));
}
int diameterOfBinaryTree(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int d1 = 1 + height(root->left) + height(root->right);
    int d2 = diameterOfBinaryTree(root->left);
    int d3 = diameterOfBinaryTree(root->right);
    return max(d1, max(d2, d3));
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    cout << diameterOfBinaryTree(root);
}
