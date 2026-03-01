#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main(int argc, char const *argv[])
{
    // int arr1[]{800, 700, 600, 500};
    // int arr2[]{840, 820, 830, 530};
    // implementing the selection sort algorithm to sort the array and generate arr2 accordingly
    // int n = sizeof(arr1) / sizeof(arr1[0]);
    int arr1[]{900, 940, 950, 1100, 1500, 1800};
    int arr2[]{910, 1200, 1120, 1130, 1900, 2000};
    int n = size(arr1);
    cout << "size of array is " << n << endl;
    cout << "before sorting the elements are as follows:" << endl;

    for (auto x : arr1)
    {
        cout << x << " ";
    }
    cout << endl;
    for (auto x : arr2)
    {
        cout << x << " ";
    }
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr1[j] < arr1[min])
            {
                min = j;
            }
        }
        swap(arr1[i], arr1[min]);
        swap(arr2[i], arr2[min]);
    }
    for (auto x : arr1)
    {
        cout << x << " ";
    }
    cout << endl;
    for (auto x : arr2)
    {
        cout << x << " ";
    }
    cout << endl;
    int resultmin{};
    int resultmax{};
    int i = 0;
    int result = 0;
    while (i < n - 1)
    {
        int j = i;
        if (arr2[j] > arr1[j + 1] && j < n - 1)
        {
            int count = 1;
            int tempmin = INT_MIN;
            int tempmax = INT_MAX;
            while (arr2[j] > arr1[j + 1] && j < n - 1)
            {
                tempmin = max(tempmin, arr1[j + 1]);
                tempmax = min(tempmax, arr2[j]);
                j++;
                count++;
            }
            if (count > result)
            {
                resultmin = tempmin;
                resultmax = tempmax;
                result = count;
            }
            i = j;
        }
        else
        {
            i++;
        }
    }
    cout << "start time is :" << resultmin << " end time is   :" << resultmax << endl;

    return 0;
}
