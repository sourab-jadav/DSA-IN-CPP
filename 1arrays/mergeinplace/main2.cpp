// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    // Write C++ code here
    vector<int> arr1{1, 5, 9, 10, 15, 20};
    vector<int> arr2{2, 3, 8, 13};
    // int n1 = sizeof(arr1) / sizeof(arr1[0]);
    // int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int n1 = arr1.size();
    int n2 = arr2.size();

    int k = n1 - 1;
    int i = 0;
    int j = 0;
    while (i <= k)
    {
        if (arr1[i] < arr2[j])
        {
            i++;
        }
        else
        {
            swap(arr1[k--], arr2[j++]);
        }
    }
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    for (int i = 0; i < n1; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n2; i++)
    {
        cout << arr2[i] << " ";
    }
    return 0;
}