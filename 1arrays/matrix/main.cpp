// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void setZeroes(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    int flag[m][n];
    memset(flag, -1, sizeof(flag));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (flag[i][j] == 0)
            {
                continue;
            }
            if (matrix[i][j] == 0)
            {
                for (int k = 0; k < m; k++)
                {
                    if (flag[k][j] != 0)
                    {
                        matrix[k][j] = 0;
                        flag[k][j] = 0;
                    }
                }
                for (int c = 0; c < n; c++)
                {
                    if (flag[c][i] != 0)
                    {
                        matrix[i][c] = 0;
                        flag[i][c] = 0;
                    }
                }
            }
        }
    }
}
int main()
{
    vector<vector<int>> vec{{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    for (auto x : vec)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
    cout << "after" << endl;
    setZeroes(vec);
    for (auto x : vec)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
    return 0;
}