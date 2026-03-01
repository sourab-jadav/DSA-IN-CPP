#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<vector<int>> matrix{
        {0, 0, 0, 5}, {4, 3, 1, 4}, {0, 1, 1, 4}, {1, 2, 1, 3}, {0, 0, 1, 1}};
    int m = matrix.size();
    int n = matrix[0].size();

    vector<vector<int>> flag(m, vector<int>(n));
    for (auto &row : flag)
    {
        fill(row.begin(), row.end(), -1);
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0 && flag[i][j] == -1 || flag[i][j] == -2)
            {
                for (int k = 0; k < n; k++)
                {
                    if (matrix[i][k] == 0 && k != j && flag[i][k] == -1)
                    {
                        flag[i][k] = -2;
                    }
                    else
                    {
                        matrix[i][k] = 0;
                        flag[i][k] = 0;
                    }
                }
                for (int l = 0; l < m; l++)
                {
                    if (matrix[l][j] == 0 && l != i && flag[l][j] == -1)
                    {
                        flag[l][j] = -2;
                    }
                    else
                    {
                        matrix[l][j] = 0;
                        flag[l][j] = 0;
                    }
                }
            }
        }
    }

    return 0;
}