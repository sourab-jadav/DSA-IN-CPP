#include <iostream>
#include <vector>
#include <string>
using namespace std;
int josephus(int n,int k){
    if (n==1) {
        return 0;
    }
    int result=(josephus(n-1,k)+k)%n;
    return result;
}
int main() {

}
