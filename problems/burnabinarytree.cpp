#include <iostream>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node(int k) : val(k), left(nullptr), right(nullptr){};
};

Node *consbintree(vector<int> &vec)
{
    Node *root = new Node(vec[0]);
    int i = 1;
    queue<Node *> q;
    q.push(root);
    while (!q.empty() && i < vec.size())
    {
        Node *front = q.front();
        q.pop();
        if (vec[i] != NULL)
        {
            front->left = new Node(vec[i]);
            q.push(front->left);
        }
        i++;
        if (vec[i] != NULL)
        {
            front->right = new Node(vec[i]);
            q.push(front->right);
        }
        i++;
    }
    return root;
}
void preorder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}
void leveorder(Node *root)
{
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
int result = 0;
int timeToInfect(TreeNode *root, int data, int &dist)
{
    cout << result << " " << endl;
    if (root == nullptr)
    {
        return 0;
    }
    if (root->val == data)
    {
        dist = 0;
        return 1;
    }
    int ldist = -1;
    int rdist = -1;
    int lh = timeToInfect(root->left, data, ldist);
    int rh = timeToInfect(root->right, data, rdist);
    if (ldist != -1)
    {
        dist = ldist + 1;
        result = max(result, dist + rh);
    }
    if (rdist != -1)
    {
        dist = rdist + 1;
        result = max(result, dist + lh);
    }
    return max(lh, rh) + 1;
}
// int countime(TreeNode *root, int x)
// {
//     int dist = -1;
//     return timeToInfect(root, x, dist);
// }
void burnTree(Node *root, int target)
{
    queue<Node *> q;

    // Function call
    burnTreeUtil(root, target, q);

    // While loop runs unless queue becomes empty
    while (!q.empty())
    {
        int qSize = q.size();
        while (qSize > 0)
        {
            Node *temp = q.front();

            // Printing of burning nodes
            cout << temp->key;
            // Insert left child in a queue, if exist
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            // Insert right child in a queue, if exist
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }

            if (q.size() != 1)
                cout << " , ";

            q.pop();
            qSize--;
        }
        cout << endl;
    }
}
int main()
{
    // task is to burn a binary tree
    vector<int> vec{10, 12, 13, NULL, NULL, 14, 15, 21, 22, 23, 24};
    Node *root = consbintree(vec);
    int targetnode = 14;
    burntree(root, targetnode);
}