#include <iostream>

#include <vector>

using namespace std;

int main()
{

    vector<int> a{5, 10, 10, 15, 30};
    vector<int> b{3, 5, 10, 10, 10, 15, 15, 20};

    int n1 = a.size();
    int n2 = b.size();
    int i, j = 0;

    while (i < n1 && j < n2)
    {
        // if (i > 0 && a[i] == a[i - 1])
        // {
        //     i++;
        //     continue;
        // }
        // if (a[i] < b[j])
        // {
        //     i++;
        // }
        // else if (b[j] < a[i])
        // {
        //     j++;
        // }
        // else if (a[i] == b[j] && a[i] != a[i - 1])
        // {
        //     cout << a[i] << " " << endl;
        //     i++;
        //     j++;
        // }
        if (i > 0 && a[i] == a[i - 1])
        {
            i++;
            continue;
        }
        if (a[i] < b[j])
        {
            i++;
        }
        else if (a[i] > b[j])
        {
            j++;
        }
        else
        {
            cout << a[i] << " " << endl;
            i++;
            j++;
        }
    }
}