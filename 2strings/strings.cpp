#include <iostream>
#include <typeinfo>
#include <string>

using namespace std;

int main()
{
    string s = "lkjsdlfj";
    cout << typeid(s[0]).name();
    int a = 45;
    cout << endl;
    cout << typeid(a).name();
}