#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str = "11";
    int n;
    cout << "enter the n value" << endl;
    cin >> n;
    for (int i = 3; i <= n; i++)
    {
        int count = 1;
        int len = str.length();
        string temp = "";
        str += "$";

        for (int j = 1; j <= len; j++)
        {
            if (str[j] != str[j - 1])
            {
                temp += to_string(count);
                temp += str[j - 1];
                count = 1;
            }
            else
            {
                count++;
            }
        }
        str = temp;
        cout << str << " ";
    }

        return 0;
}