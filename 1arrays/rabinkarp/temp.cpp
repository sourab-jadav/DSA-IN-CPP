#include <iostream>
#include <bits/stdc++.h>

using namespace std;
bool search(string txt, string pat, int i, int m)
{
    int k = 0;
    for (int j = i; j < i + m; j++)
    {
        if (pat[k] == txt[j])
        {
            k++;
        }
    }
    return k == m;
}

int main()
{
    string txt = "abdabcbabc";
    string pat = "abc";
    int m = pat.length();
    int n = txt.length();
    int t, p;
    t = p = 0;
    for (int i = 0; i < m; i++)
    {
        p += pat[i] - 'a' + 1;
        t += txt[i] - 'a' + 1;
    }
    for (int i = 0; i <= n - m; i++)
    {
        // t = calculatet(txt, i, m);
        if (t == p)
        {
            bool flag = search(txt, pat, i, m);
            if (flag == true)
            {
                cout << i << " ";
            }
        }
        t -= txt[i] - 'a' + 1;
        t += txt[i + m] - 'a' + 1;
        // i += m;
    }

    return 0;
}