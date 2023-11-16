#include <bits/stdc++.h>

using namespace std;

template <typename x>
void swapTheNumbers(x &a, x &b)
{
    x temp;
    temp = a;
    a = b;
    b = temp;
    cout << "the numbers are swapped" << endl;
}

int main()
{
    // templates in c++ language
    int a = 10;
    int b = 20;
    cout << "before swapping the values are " << a << " " << b << endl;
    swapTheNumbers(a, b);
    cout << "after swapping the values are " << a << " " << b << endl;

    float c = 20.0;
    float d = 40.5;
    cout << "before swapping the values are " << c << " " << d << endl;
    swapTheNumbers(c, d);
    cout << "after swapping the values are " << c << " " << d << endl;
    return 0;
}