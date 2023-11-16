#include <bits/stdc++.h>

using namespace std;

void printsub(int arr[], vector<int> &vec, int n, int i)
{
    if (i == n)
    {
        if (vec.empty())
        {
            cout << "{}"
                 << " ";
            return;
        }
        else
        {
            cout << "{ ";
            for (auto x : vec)
            {
                cout << x << " ";
            }
            cout << "} ";
            return;
        }
    }
    printsub(arr, vec, n, i + 1);
    vec.push_back(arr[i]);
    printsub(arr, vec, n, i + 1);
    vec.pop_back();
}

int main()
{
    int arr[] = {5, 8, 3, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> vec;

    printsub(arr, vec, n, 0);

    return 0;
}