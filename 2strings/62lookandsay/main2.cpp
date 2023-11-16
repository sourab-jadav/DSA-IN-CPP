#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str = "11";
    string ans = "";
    str += "$";

    unordered_map<char, int> m;
    int len = str.length();
    for (int i = 0; i < len; i++)
    {
        if (m.find(str[i]) == m.end() && i > 0)
        {
            auto prev = m.find(str[i - 1]);
            ans += to_string(prev->second) + prev->first;
            m.clear();
        }
        else
        {
            m[str[i]]++;
        }
    }
    cout << ans << " ";
}