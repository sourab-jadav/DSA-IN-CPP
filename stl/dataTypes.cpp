#include <climits>
#include <iostream>
using namespace std;
int main() {
    int v=INT_MAX; // it's binary is 0 followed by 31 1's
     // let's express this interms of 10 power x;
     //
     //
     //
     // for int and unsigned int on a 32 bit system is approximately 10^9
     // for long int,unsigned long int,long long int,unsigned long long int it is 10^18

    int x=1e9;
    // int z=1e10; // this does not work 
    long int z=1e18; // this is the max 10 power value that we can use
    long long int s=1e18;  // this works



    std::cout<<1e-5<<std::endl; // this is  10 power -5 and it is away to express a very small number
                                // and it should be placed in a double value
    long int y=1e10;
    long double sourab=1e-5; 
    // long long double sdfsdf=1e-5; // this does not works and trancates the value to 0
    return 0;
}
