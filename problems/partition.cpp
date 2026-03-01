#include <iostream>
#include <algorithm>

using namespace std;
void lomuto_partition(int arr[], int low, int high)
{
    int i = low - 1;
    int pivot = arr[high];
    int j = low;
    while (j <= high)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }

        j++;
    }
    // for (int j = low; j <= high - 1; j++)
    // {
    // }
    swap(arr[i + 1], arr[high]);
}

int main(int argc, char const *argv[])
{
    int arr[]{6, 4, 14, 16, 10, 45, 24, 5, 7};
    int pivot = 24;
    int i = -1;
    int j = -1;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "the array size is " << n << endl;
    cout << "before the array is " << endl;
    for (int x : arr)
    {
        cout << x << " ";
    }
    cout << endl;
    while (i < n)
    {
        if (arr[i + 1] < pivot)
        {
            i++;
            j++;
            swap(arr[i], arr[j]);
        }
        i++;
    }

    cout << "using lomuto the result is" << endl;
    // lomuto_partition(arr, 0, n - 1);
    cout << "after the array is " << endl;
    for (int x : arr)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
