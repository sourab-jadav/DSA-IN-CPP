#include <bits/stdc++.h>
using namespace std;

int minTiles(int n, int m)
{
    // base case, when area is 0.
    if (n == 0 || m == 0)
        return 0;

    // If n and m both are even, calculate tiles for n/2 x m/2
    // Halving both dimensions doesn't change the number of tiles
    else if (n % 2 == 0 && m % 2 == 0)
        return minTiles(n / 2, m / 2);

    // If n is even and m is odd
    // Use a row of 1x1 tiles
    else if (n % 2 == 0 && m % 2 == 1)
        return (n + minTiles(n / 2, m / 2));

    // If n is odd and m is even
    // Use a column of 1x1 tiles
    else if (n % 2 == 1 && m % 2 == 0)
        return (m + minTiles(n / 2, m / 2));

    // If n and m are odd
    // add row + column number of tiles
    else
        return (n + m - 1 + minTiles(n / 2, m / 2));
}

// Driven Program
int main()
{
    int n = 5, m = 6;

    cout << minTiles(n, m) << endl;
    return 0;
}
