// Back-end complete function Template for C++
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isfeasable(int n, int k, vector<int> &stalls, int dist)
    {
        int coord = stalls[0];
        int cnt = 1;
        for (int i = 1; i < n; i++)
        {
            if (stalls[i] - coord >= dist)
            {
                cnt++;
                coord = stalls[i];
            }

            if (cnt == k)
                return true;
        }
        return false;
    }

    int solve(int n, int k, vector<int> &stalls)
    {

        sort(stalls.begin(), stalls.end());
        int low = 1;
        int high = stalls[n - 1] - stalls[0];

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (isfeasable(n, k, stalls, mid))
                low = mid + 1;
            else
                high = mid - 1;
        }
        return high;
    }
};

int main()
{
    vector<int> vec{1, 2, 4, 8, 9};
    int n = 5;
    cout << "hello world" << endl;
    cout << "parindinaa another game of thrones another game of thrnoe" int k = 3;
    Solution s;
    cout << s.solve(n, k, vec) << endl;
    return 0;
}