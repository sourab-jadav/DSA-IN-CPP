// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str = "geeksforgeeks";
    int max_length = 0;
    int count = 0;
    int j = 0;
    vector<int> vec(256, -1);
    int n = str.length();
    for (int i = 0; i < n; i++)
    {
        if (vec[str[i]] == -1)
        {
            count++;
            vec[str[i]] = i;
        }
        else
        {
            max_length = max(max_length, count);
            // count=count-(vec[str[i]]+1);
            count = count - (vec[str[i]] - j + 1);
            j = vec[str[i]] + 1;
            // vec[str[i]]=-1;
            count++;
        }
    }
    return 0;
}