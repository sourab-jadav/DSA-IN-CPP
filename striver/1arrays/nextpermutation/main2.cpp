#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void reverse_func(vector<int> &temp, int low, int high)
    {
        while (low < high)
        {
            swap(temp[low], temp[high]);
            low++;
            high--;
        }
    }
    void nextPermutation(vector<int> &arr)
    {
        int n = arr.size(), i, j;

        // Find for the pivot element.
        // A pivot is the first element from
        // end of sequenc ewhich doesn't follow
        // property of non-increasing suffix
        for (i = n - 2; i >= 0; i--)
        {
            if (arr[i] < arr[i + 1])
            {
                break;
            }
        }

        // Check if pivot is not found
        if (i < 0)
        {
            reverse_func(arr, 0, n - 1);
        }

        // if pivot is found
        else
        {

            // Find for the successor of pivot in suffix
            for (int j = n - 1; j > i; j--)
            {
                if (arr[j] > arr[i])
                {
                    break;
                }
            }

            // Swap the pivot and successor
            swap(arr[i], arr[j]);

            // Minimise the suffix part
            reverse_func(arr, i + 1, n - 1);
        }
    }
};

int main()
{
    Solution s;
    vector<int> arr{1, 2, 3};
    s.nextPermutation(arr);
    for (auto x : arr)
    {
        cout << x << " ";
        cout << endl;
    }
    return 0;
}