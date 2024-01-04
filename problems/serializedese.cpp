#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int k) : val(k), left(nullptr), right(nullptr){};
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
        if (vec[i] != NULL && i < vec.size())
        {
            front->right = new TreeNode(vec[i]);
            q.push(front->right);
        }
        i++;
    }
    return root;
}
class Codec
{
public:
    string serialize(TreeNode *root)
    {
        ostringstream out;
        serialize(root, out);
        return out.str();
    }

    TreeNode *deserialize(string data)
    {
        istringstream in(data);
        return deserialize(in);
    }

private:
    void serialize(TreeNode *root, ostringstream &out)
    {
        if (root)
        {
            out << root->val << ' ';
            serialize(root->left, out);
            serialize(root->right, out);
        }
        else
        {
            out << "# ";
        }
    }

    TreeNode *deserialize(istringstream &in)
    {
        string val;
        in >> val;
        if (val == "#")
            return nullptr;
        TreeNode *root = new TreeNode(stoi(val));
        root->left = deserialize(in);
        root->right = deserialize(in);
        return root;
    }
};
int main()
{
    Codec c;
    vector<int> vec{1, 2, 3, NULL, NULL, 4, 5};
    TreeNode *root = consbintree(vec);
    cout << c.serialize(root);
}