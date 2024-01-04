#include <bits/stdc++.h>
using namespace std;

bool checkpalindrome(string str, int low, int high)
{
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
string longestPalindrome(string str)
{
    size_t n = str.length();
    for (int i = 0; i < n; i++)
    {
        auto it = find(str.rbegin(), str.rend(), str[i]);
        int index = (n - (it - str.rbegin() + 1));
        if (it != str.rend() && index > i)
        {
            if (checkpalindrome(str, i, index))
            {
                return str.substr(i, index - i + 1);
            }
        }
    }
    return "";
}

int main()
{

    string output = longestPalindrome("aacabdkacaa");
    cout << output << endl;
    return 0;
}