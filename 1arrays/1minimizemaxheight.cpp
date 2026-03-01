// C++ Code for the Approach

#include <bits/stdc++.h>
using namespace std;

// User function Template
int getMinDiff(vector<int> vec, int k)
{
    sort(vec.begin(), vec.end());
    // get the inital answer
    int n = vec.size();
    int ans = vec[n - 1] - vec[0];

    int tempmax{};
    int tempmin{};
    for (int i = 1; i < n; i++)
    {
        if (vec[i] - k < 0)
        {
            continue;
        }
        tempmin = min(vec[0] + k, vec[i] - k);
        tempmax = max(vec[n - 1] - k, vec[i - 1] + k);
        ans = min(ans, tempmax - tempmin);
    }
    return ans;
}

// Driver Code Starts
int main()
{

    int k = 6;
    vector<int> vec = {3, 9, 12, 16, 20};

    // Function Call
    int ans = getMinDiff(vec, k);
    cout << ans;
}