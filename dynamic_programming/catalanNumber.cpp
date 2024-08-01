#include <cstring>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
     // printing the catalan sequence
    int cat[2345];
    memset(cat, 0, sizeof(cat));
    cat[0]=1;
    cat[1]=1;
    int n;
    cin>>n;
    for(int i=2;i<=n;i++){
        for(int j=0;j<=i;j++){
            cat[i]+=cat[j]*cat[i-1-j];
        }
    }
    for(int i=0;i<=n;i++){
        std::cout<<cat[i]<<" ";
    }
    return 0;
}
