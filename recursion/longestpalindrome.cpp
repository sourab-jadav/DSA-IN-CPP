// Online C++ compiler to run C++ program online
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str = "somethmnge";
    auto it = find(str.rbegin(), str.rend(), 'm');
    // it != str.rend() ? cout << "found at index" << (str.rend() - 1) - it : cout << "not found";
    it!=str.rend()?cout<<"found at index "<<str.length()-(it-str.rbegin()+1):cout<<"element not found"<<endl;

    return 0;
}