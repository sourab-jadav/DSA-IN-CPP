

#include <iostream>
#include <climits>
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
    int res = INT_MIN;
    int findpath(Node *root)
    {
        if (!root)
        {
            return 0;
        }
        // if the left is negative then we don't include it
        int leftsum = max(findpath(root->left), 0);
        int rightsum = max(findpath(root->right), 0);
        res = max(res, leftsum + rightsum + root->val);
        return root->val + max(leftsum, rightsum);
    }

    int maxPathSum(Node *root)
    {

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

// int countime(TreeNode *root, int x)
// {
//     int dist = -1;
//     return timeToInfect(root, x, dist);
// }
int main()
{
    // task is to burn a binary tree
    vector<int> vec{-3};
    // vector<int> vec{-10, 9, 20, NULL, NULL, 15, 7};
    Node *root = consbintree(vec);
    Solution s;
    cout << s.maxPathSum(root);
}