#include <bits/stdc++.h>

using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (!root)
            return ans;

        queue<TreeNode *> q;
        q.push(root);

        bool flag = true; // left->right first//

        while (!q.empty())
        {
            int n = q.size();
            vector<int> level;
            if (flag)
            {
                for (int i = 0; i < n; i++)
                {
                    TreeNode *ele = q.front();
                    q.pop();
                    level.push_back(ele->val);
                    if (ele->right)
                        q.push(ele->right);
                    if (ele->left)
                        q.push(ele->left);
                }
                flag = false;
            }

            else
            {
                for (int i = 0; i < n; i++)
                {
                    TreeNode *ele = q.front();
                    q.pop();
                    level.push_back(ele->val);

                    if (ele->left)
                        q.push(ele->left);
                    if (ele->right)
                        q.push(ele->right);
                }
                flag = true;
            }
            ans.push_back(level);
        }
        return ans;
    }
};
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    Solution s;
    s.zigzagLevelOrder(root);
    return 0;
}