
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
class Solution
{
public:
    int res = 0;
    int findpath(Node *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int left = findpath(root->left);
        int right = findpath(root->right);
        int leftmax = max(left + right + root->val, left + root->val);
        int rightmax = max(left + right + root->val, right + root->val);
        res = max(res, max(leftmax, rightmax));
        res = max(res, root->val);
        return root->val + max(left, right);
    }

    int maxPathSum(Node *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        else
        {
            res = root->val;
        }
        findpath(root);
        return res;
    }
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
        if (vec[i] != NULL && i < vec.size())
        {
            front->right = new Node(vec[i]);
            q.push(front->right);
        }
        i++;
    }
    return root;
}

int result = 0;
// int countime(TreeNode *root, int x)
// {
//     int dist = -1;
//     return timeToInfect(root, x, dist);
// }
int main()
{
    // task is to burn a binary tree
    vector<int> vec{9, 6, -3, NULL, NULL, -6, 2, NULL, NULL, 2, NULL, -6, -6, -6};
    // vector<int> vec{-10, 9, 20, NULL, NULL, 15, 7};
    Node *root = consbintree(vec);
    Solution s;
    cout << s.maxPathSum(root);
}