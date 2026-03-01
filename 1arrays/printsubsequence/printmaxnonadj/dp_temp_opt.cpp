#include <bits/stdc++.h>

using namespace std;

int main()
{
    int arr[]{3, 2, 7, 10};
    int n = 4;
    int first_max = 0;
    int second_max = arr[0];
    for (int i = 1; i < n; i++)
    {
        int right = first_max + arr[i];
        int left = max(first_max, second_max);
        first_max = left;
        second_max = right;
    }
    cout << max(first_max, second_max) << endl;

    return 0;
}