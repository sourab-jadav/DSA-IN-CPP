#include <bits/stdc++.h>

using namespace std;

bool wordBreak(string s, unordered_set<string> &dict)
{
    if (dict.size() == 0)
        return false;

    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;

    for (int i = 1; i <= s.size(); i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (dp[j])
            {
                string word = s.substr(j, i - j);
                if (dict.find(word) != dict.end())
                {
                    dp[i] = true;
                    break; // next i
                }
            }
        }
    }

    return dp[s.size()];
}
int main()
{
    cout << "hello world" << endl;
    string s = "applepenapple";
    unordered_set<string> words = {"apple", "pen"};
    wordBreak(s, words);

    return 0;
}