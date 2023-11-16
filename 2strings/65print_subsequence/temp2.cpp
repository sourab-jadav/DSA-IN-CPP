#include <bits/stdc++.h>

using namespace std;
void printsubseq(string str)
{
    int n = str.length();
    for (int i = 1; i <= ((1 << n) - 1); i++)
    {
        for (int j = 0; j < str.length(); j++)
        {
            if (i & (1 << j))
            {
                cout << str[j];
            }
        }
        cout << " ";
    }
}

int main()
{
    string str = "abc";
    printsubseq(str);
    return 0;
}