#include <bits/stdc++.h>

using namespace std;

int main()
{
    string txt = "ababcbabc";
    string pat = "abc";
    int n = txt.length();
    int m = pat.length();
    // adding weights to the pat and txt
    int txt_count, pat_count{};
    for (int i = 0; i < m; i++)
    {
        pat_count += (pat[i] - 'a' + 1) * (pow(2, i+1 ));
        txt_count += (txt[i] - 'a' + 1) * (pow(2, i+1));
    }
    cout << "pat count is " << pat_count << endl;
    cout << "txt_coutnt is " << txt_count << endl;
    if (pat_count == txt_count)
    {
        cout << 0 << " ";
    }
    for (int i = 1; i <= n - m; i++)
    {
        // cout<<((txt_count/2)-(txt[i-1]-'a'+1))<<endl;
        // cout<<((txt[i+m-1]-'a'+1)*pow(2,m))<<endl;
        // txt_count = ((txt_count - (txt[i - 1] - 'a' + 1)) / 2) + ((txt[i + m - 1] - 'a' + 1) * pow(2, m));
        txt_count=((txt_count/2)-(txt[i-1]-'a'+1))+((txt[i+m-1]-'a'+1)*pow(2,m));
        if (txt_count == pat_count)
        {
            cout << i << " ";
        }
    }
    return 0;
}