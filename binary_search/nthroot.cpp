#include <iostream>
// finding the nth root of a number
int printRoot(int m,int n){
    if(m==1){
        return 1;
    }
    for(int x=2;x<m;x++){
        int temp=x;
        for(int i=0;i<n-1;i++){
            temp=temp*x;
        }
        if(temp==m){
            return m;
        }
    }
    return -1;
}
long long func(int b, int exp) {
    long long  ans = 1;
    long long base = b;
    while (exp > 0) {
        if (exp % 2) {
            exp--;
            ans = ans * base;
            std::cout<<"answer is "<<ans<<std::endl;
        }
        else {
            exp /= 2;
            std::cout<<"exp value is "<<exp<<std::endl;
            base = base * base;
            std::cout<<"base is "<<base<<std::endl;
        }
    }
    return ans;
}
int main() {
    int m=64;
    int n=3;
    int result=printRoot(m, n);
    std::cout<<result<<std::endl;
    std::cout<<func(4, 3)<<std::endl;
    return 0;
}
