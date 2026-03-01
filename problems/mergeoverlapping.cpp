#include <iostream>
#include <algorithm>

using namespace std;

struct interval
{
    int start;
    int end;
};
bool comparator(interval a, interval b)
{
    return a.start < b.start;
}
int main(int argc, char const *argv[])
{
    interval arr[]{{1, 3}, {6, 8}, {2, 4}, {5, 7}};
    cout << "before sorting the elements are " << endl;

    for (auto x : arr)
    {
        cout << x.start << " " << x.end << endl;
    }

    cout << "after sorting the elements are " << endl;
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + n, comparator);
    for (auto x : arr)
    {
        cout << x.start << " " << x.end << endl;
    }
    // logic for merging the overlapping intervals
    // how do you write a comparator for cpp sorting algorithm
    // mergin overlapping intervals
    //{{1,3},{2,4},{5,7},{6,8}}
    cout << "after merging the values are " << endl;
    int i = 0;
    while (i < n)
    {
        int j = i + 1;
        while (j < n)
        {
            if (arr[j - 1].end > arr[j].start)
            {
                arr[i].start = min(arr[i].start, arr[j].start);
                arr[i].end = max(arr[i].end, arr[j].end);
                j++;
            }
            else
            {
                break;
            }
        }
        cout << arr[i].start << " " << arr[i].end << endl;
        i = j;
    }
    return 0;
}