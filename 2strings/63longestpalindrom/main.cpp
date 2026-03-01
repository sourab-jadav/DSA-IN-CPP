#include <bits/stdc++.h>
using namespace std;

bool checkpalindrome(string str, int low, int high)
{

    bool flag = true;
    while (low < high)
    {
        if (str[low] != str[high])
        {
            return false;
        }
        low++;
        high--;
    }
    return true;
}

int main()
{
    string str = "forgeeksskeegfor";
    int n = str.length();
    int low = 0;
    int high = n - 1;
    // printing the longest palindrome possible
    int count = 0;
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (checkpalindrome(str, i, j))
            {
                count = j - i + 1;
                result = max(result, count);
                break;
            }
        }
    }
    cout << "max possible length of the palindrome is " << result << endl;
    return 0;
}