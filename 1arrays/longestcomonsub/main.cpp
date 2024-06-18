#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // arr[] : the input array
    // N : size of the array arr[]
    // unoptimized approach
    // Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int n)
    {
        vector<int> v;
        sort(arr, arr + n);
        v.push_back(arr[0]);
        for (int i = 1; i < n; i++)
        {
            if (arr[i] != arr[i - 1])
            {
                v.push_back(arr[i]);
            }
        }
        int count = 1;
        int result = 1;
        for (int i = 1; i < v.size();)
        {
            while (v[i] == v[i - 1] + 1 && i < v.size())
            {
                count++;
                i++;
            }
            result = max(result, count);
            count = 1;
            i++;
        }
        return result;
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int arr[]{2, 6, 1, 9, 4, 5, 3};
    Solution s;
    cout << s.findLongestConseqSubseq(arr, 7);
    return 0;
}
// } Driv

int findLongestConseqSubseq(int arr[], int N)
{
    set<int> s(arr, arr + N);
    int count = 1;
    int result = 1;

    for (auto x : s)
    {
        int t = x;
        while (s.find(t - 1) != s.end())
        {
            count++;
            t--;
        }
        result = max(result, count);
        count = 1;
    }
    return result;
}
