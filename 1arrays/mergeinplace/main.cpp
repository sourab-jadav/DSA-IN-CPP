#include <bits/stdc++.h>

using namespace std;

int main()
{
    // merging two sorted arrays
    vector<int> arr1 = {1, 5, 9, 10, 15, 20};
    vector<int> arr2 = {2, 3, 8, 13};
    int n1 = arr1.size();
    int n2 = arr2.size();
    for (int i = n2 - 1; i >= 0; i--)
    {
        int j;
        for (j = n1 - 1; j >= 0; j--)
        {
            if (arr1[j] > arr2[i])
            {
                break;
            }
        }
        if (j >= 0)
        {
            swap(arr1[j], arr2[i]);
            int temp = arr1[j];
            int k = j - 1;
            while (arr1[k] >= temp)
            {
                arr1[k + 1] = arr1[k];
                k--;
            }
            arr1[k + 1] = temp;
        }
    }
    cout << "arr1 elements:" << endl;
    cout << "{";

    for (auto x : arr1)
    {
        cout << x << " ";
    }
    cout << "}";
    cout << endl;
    cout << "arr2 elements:" << endl;
    cout << "{";
    for (auto x : arr2)
    {
        cout << x << " ";
    }
    cout << "}";

    return 0;
}