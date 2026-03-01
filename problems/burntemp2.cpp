#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *newNode(int key)
{
    Node *temp = new Node;
    temp->data = key;
    temp->left = temp->right = NULL;
    return (temp);
}

int findMinTime(Node *root, int target, int level,
                unordered_map<int, vector<int>> &ans,
                int consider)
{
    if (root == NULL)
        return -1;

    if (consider == 1)
    {
        ans[level].push_back(root->data);
    }

    if (root->data == target)
    {
        ans[0].push_back(root->data);
        findMinTime(root->left, target, 1, ans, 1);
        findMinTime(root->right, target, 1, ans, 1);
        return 1;
    }

    int left = findMinTime(root->left, target, level + 1,
                           ans, consider);
    int right = findMinTime(root->right, target, level + 1,
                            ans, consider);

    if (left != -1)
    {
        ans[left].push_back(root->data);
        findMinTime(root->right, target, left + 1, ans, 1);
        return left + 1;
    }
    if (right != -1)
    {
        ans[right].push_back(root->data);
        findMinTime(root->left, target, right + 1, ans, 1);
        return right + 1;
    }
    return -1;
}

unordered_map<int, vector<int>> minTime(Node *root,
                                        int target)
{
    unordered_map<int, vector<int>> ans;
    findMinTime(root, target, 0, ans, 0);
    return ans;
}

int main()
{

    Node *root = newNode(10);
    root->left = newNode(12);
    root->right = newNode(13);

    root->right->left = newNode(14);
    root->right->right = newNode(15);

    root->right->left->left = newNode(21);
    root->right->left->right = newNode(22);
    root->right->right->left = newNode(23);
    root->right->right->right = newNode(24);
    int targetNode = 14;

    unordered_map<int, vector<int>> answer = minTime(root, targetNode);
    for (auto it = answer.begin(); it != answer.end();
         it++)
    {
        cout << "Nodes burnt at stage " << it->first
             << " are ";
        for (int i = 0; i < it->second.size(); i++)
        {
            cout << it->second[i] << " ";
        }
        cout << endl;
    }

    return 0;
}

// This code is contributed by "Dilraj Singh"
