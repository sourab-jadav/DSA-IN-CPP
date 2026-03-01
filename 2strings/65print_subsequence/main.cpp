#include <bits/stdc++.h>
using namespace std;

void func(string input, string output)
{
    if (input.empty())
    {
        cout << output << " ";
        return;
    }
    func(input.substr(1), output + input[0]);
    func(input.substr(1), output);
}

int main()
{
    string str = "some";
    cout << str.substr(1) << endl;
    cout << str.substr(2, 1) << endl;
    func(str, "");
}