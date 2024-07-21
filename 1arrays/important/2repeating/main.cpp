#include <bits/stdc++.h>
using namespace std;

void twoRepeated(vector<int> arr, int N) {
    int m = N - 1;
    for (int i = 0; i < N; i++) {
        arr[arr[i] % m - 1] += m;
        if ((arr[arr[i] % m - 1] / m) == 2)
            cout << arr[i] % m << " ";
    }
}
// Driver Code
int main()
{
    vector<int> arr = {4, 1, 2, 5, 2, 3, 1};
    int n = arr.size();
    cout << "Repeating elements are ";
    twoRepeated(arr, n);

    return 0;
}

