#include <bits/stdc++.h>

using namespace std;

int josephus(int n, int k) {
    if (n == 1) {
        return 0;
    }
    else {
        return (josephus(n - 1, k) + k) % n;
    }
}

int main() {
    int n;
    int k;
    cout << "enter n and k" << endl;
    cin>>n>>k;
    cout<<"entered values are "<<n<<" "<<k<<endl;
    int result=josephus(n,k);
    cout<<"ther result of the josephus is "<<result<<endl;
    return 0;
}
