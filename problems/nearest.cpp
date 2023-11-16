#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int arr[]{24, 11, 13, 21, 3};
    stack<int> stk;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << n << endl;
    stk.push(arr[0]);
    cout << -1 << " ";
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < stk.top())
        {
            cout << stk.top() << " ";
            stk.push(arr[i]);
        }
        else
        {
            while (stk.top() <= arr[i] && stk.empty() == false)
            {
                stk.pop();
            }
            if (stk.empty() == true)
            {
                cout << -1 << " ";
                stk.push(arr[i]);
            }
            else
            {
                cout << stk.top() << " ";
                stk.push(arr[i]);
            }
        }
    }
}