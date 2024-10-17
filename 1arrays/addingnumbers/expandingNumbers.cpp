#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define printxyz(arr, rows, cols)                      \
        for (int i = 0; i < rows; ++i) {               \
            for (int j = 0; j < cols; ++j) {           \
                std::cout << arr[i][j] << " ";         \
            }                                          \
            std::cout << std::endl;                    \
        }                                              \
        std::cout<<std::endl;                          \
    } while (0)
#define printarray(arr, n)                             \
        std::cout<<std::endl;                          \
        for (int i = 0; i < n; ++i) {                  \
            std::cout<<arr[i]<<" ";                    \
        }                                              \
        std::cout<<std::endl;                          \


// you are given a number 4685 you have to expand it
int main() {
    int n=4685;
    std::cout<<n%10000<<std::endl;
    std::cout<<n/1000<<std::endl;
    long long x=10000000000000000; // we have taken 16 zeroes
    // std::cout<<n%x<<std::endl;
    // std::cout<<n/x<<std::endl;
    // for(int i=1;i<18;i++){
    //     std::cout<<n%x<<std::endl;
    //     x/=10;
    // }
    string output="";
    // the idea is take the max possible 1 followed by n zeroes that can fit as a number in a datatype
    // 
    
    while (n!=0) {
        if (n/x!=0) {
            std::cout<<n%x<<std::endl;
            std::cout<<"n value is "<<n<<" x value is "<<x<<std::endl;
            if (n/10!=0) {
                output+=to_string(n/x*x)+"+";
            }else {
                output+=to_string(n/x*x);
            }
            n=n%x;
        }
        x/=10;
    }
    std::cout<<output<<std::endl;
    // the other way could be 
    // convert the number to string 
    // take each character at a time starting from 0 
    // each time you append the character to the result string also append that many zeroes to the string as 
    // the number of characters that are there from next to that index to n-1

    return 0;
}
