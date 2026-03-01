#include <iostream>
#include <vector>
using namespace std;
vector<int> multiply(vector<int> &digits, int factor)
{
    int carry = 0;
    for (int i = 0; i < digits.size(); i++)
    {
        int prod = digits[i] * factor + carry;
        digits[i] = prod % 10;
        carry = prod / 10;
    }
    while (carry)
    {
        digits.push_back(carry % 10);
        carry /= 10;
    }
    return digits;
}
void print(vector<int> &digits)
{
    for (int i = digits.size() - 1; i >= 0; i--)
    {
        cout << digits[i];
    }
}
int main()
{
    int n = 100;
    vector<int> digits;
    digits.push_back(1);
    for (int i = 2; i <= n; i++)
    {
        digits = multiply(digits, i);
    }
    print(digits);
    return 0;
}