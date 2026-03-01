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
int main()
{
    Node *root = new Node(3);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);
    queue<Node *> q;
    q.push(root);
    vector<vector<int>> res;
    cout << q.size() << endl;
    while (!q.empty())
    {
        vector<int> line;
        int count = q.size();
        for (int i = 0; i < count; i++)
        {
            Node *curr = q.front();
            line.push_back(curr->key);
            q.pop();
            if (curr->left != nullptr)
            {
                q.push(curr->left);
            }
            if (curr->right != nullptr)
            {
                q.push(curr->right);
            }
        }
        res.push_back(line);
    }
    for (const auto &row : res)
    {
        for (const auto &elem : row)
        {
            cout << elem << " ";
        }
        cout << endl;
    }
}