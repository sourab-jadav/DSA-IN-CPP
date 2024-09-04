#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int k) : val(k), left(nullptr), right(nullptr){};
};
class Solution {
public:
    // res to store maximum distance from the first infected node
    unordered_map<int, vector<int>> v; // adjacency list

    // create undirected graph for every parent-child  -> BFS
    void createGraph(TreeNode *root)
    {
        queue<pair<TreeNode *, int>> q;
        q.push({root, -1});
        while (q.size())
        {
            auto [node, parent] = q.front();
            q.pop();
            if (parent != -1)
            {
                v[parent].push_back(node->val);
                v[node->val].push_back(parent);
            }
            if (node->left)
                q.push({node->left, node->val});
            if (node->right)
                q.push({node->right, node->val});
        }
    }

    int amountOfTime(TreeNode *root, int start)
    {
        // create graph of given tree
        createGraph(root);

        // start bfs
        queue<int> q;
        unordered_map<int, bool> seen;
        q.push(start);
        seen[start] = true;
        int time = 0;
        for (; q.size(); time++)
        {
            int n = q.size();
            while (n--)
            {
                auto node = q.front();
                q.pop();
                for (auto i : v[node])
                {
                    if (!seen[i])
                    {
                        q.push(i);
                        seen[i] = true;
                    }
                }
            }
        }
        return time - 1;
    }
};
TreeNode *consbintree(vector<int> &vec)
{
    TreeNode *root = new TreeNode(vec[0]);
    int i = 1;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty() && i < vec.size())
    {
        TreeNode *front = q.front();
        q.pop();
        if (vec[i] != NULL)
        {
            front->left = new TreeNode(vec[i]);
            q.push(front->left);
        }
        i++;
        if (vec[i] != NULL)
        {
            front->right = new TreeNode(vec[i]);
            q.push(front->right);
        }
        i++;
    }
    return root;
}

int main()
{
    // vector<int> vec{1, 2, NULL, 3, NULL, 4, NULL, 5};
    vector<int> vec{1, 5, 3, NULL, 4, 10, 6, 9, 2};
    TreeNode *root = consbintree(vec);
    Solution s;
    cout << s.amountOfTime(root, 1);
}
