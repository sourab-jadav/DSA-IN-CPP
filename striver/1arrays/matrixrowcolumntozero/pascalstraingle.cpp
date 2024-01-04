#include <bits/stdc++.h>

using namespace std;

void generate(int numRows)
{
    int n = numRows;
    vector<vector<int>> result;

    for (int i = 0; i < n; i++)
    {
        vector<int> row;
        if (result.empty())
        {
            row.push_back(1);
            result.push_back(row);
        }
        else
        {
            int x = result.size() - 1;
            int m = result[x].size();
            for (int j = 0; j < m; j++)
            {
                if (j == 0)
                {
                    row.push_back(1);
                    continue;
                }
                row.push_back(result[x][j] + result[x][j - 1]);
            }
            row.push_back(1);
        }
        result.push_back(row);
    }
}

int main()
{
    generate(5);
    return 0;
}