#include <iostream>
#include <vector>
using namespace std;

int lowestcommonincreasing(Node *root, vector<int> &vec1, vector<int> &vec2)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    vec1.push_back(root->data);
    lowestcommonincreasing(root->left);

    lowestcommonincreasing(root->right);
}

int main()
{
    cout << "hello world" << endl;
    return 0;
}