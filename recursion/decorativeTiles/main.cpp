// Online C++ compiler to run C++ program online
// writing a program that can solve decorative time problem

#include <bits/stdc++.h>
using namespace std;
int calculateTiles(int m, int n)
{
    if (m == 1)
    {
        return n;
    }
    else if (n == 1)
    {
        return m;
    }
    int temp = 0;
    while (m / static_cast<int>(pow(2, temp)) != 0 && (n / static_cast<int>(pow(2, temp)) != 0))
    {
        temp++;
    }
    temp--;
    int temp2 = 0;
    while (n / pow(2, temp2) != 0)
    {
        temp2++;
    }
    temp2--;
    return 1 + calculateTiles(m % (int)pow(2, temp), temp2) + calculateTiles(m, n % (int)pow(2, temp));
}

int main()
{
    int m = 6, n = 5;
    int result = calculateTiles(m, n);
    cout << "the result is " << result << endl;
    return 0;
}