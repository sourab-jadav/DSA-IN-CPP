//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>> &M, int n)
    {
        for (int j = 0; j < n; j++) // traverse col-wise
        {
            int cnt = 0;
            for (int i = 0; i < n; i++)
            {
                if (M[i][j] == 1)
                    cnt++;
            }
            // cout<<j<<":  "<<cnt<<endl;

            bool flag = true;
            if (cnt == n - 1) // if everyone knows him
            {
                for (int i = 0; i < n; i++)
                    if (M[j][i] == 1) // check the same row, if he knows anyone
                    {
                        flag = false; // cout<<i<<":"<<j<<endl;
                    }

                if (flag)
                    return j;
            }
        }
        return -1;
    }
};
//{ Driver Code Starts.

int main()
{

    vector<vector<int>> v{{0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}, {0, 0, 1, 0}};
    Solution s;
    cout << s.celebrity(v, 4) << endl;
}

// } Driver Code Ends