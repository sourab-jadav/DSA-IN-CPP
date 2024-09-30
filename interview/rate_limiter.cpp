#include <iostream>
#include <type_traits>
#include <unordered_map>
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


// there is a gate way which receives the request each second
// from the domain array request[i] 
// the gateway allows atmost(<=) 2 request from a domain within 5 seconds
// and atmost 5 request within 30 seconds
int solve(string request[],int n,unordered_map<string, int>&mp){
    for(int i=0;i<n;i++){
        if (i<5) {
            if (mp[request[i]]<2) {
                mp[request[i]]++;
                std::cout<<"status:200,message: OK"<<std::endl;
            }else {
                std::cout<<"status:429,message: Too many request"<<std::endl;
            }
        }else if (i<30) {
            mp[request[i-5]]--;
            if (mp[request[i]]<2) {
                mp[request[i]]++;
                std::cout<<"status:200,message: OK"<<std::endl;
            }else {
                std::cout<<"status:429,message: Too many request"<<std::endl;
            }
        }else {
            mp[request[i-30]]--;
            if (mp[request[i]]<5) {
                mp[request[i]]++;
                std::cout<<"status:200,message: OK"<<std::endl;
            }else {
                std::cout<<"status:429,message: Too many request"<<std::endl;
            }
        }
    }
    return 0;

}
int main() {
    unordered_map<string, int>mp;
    int n=9;
    string request[]{"xyz.com","abc.com","xyz.com","pqr.com","abc.com","xyz.com","xyz.com","abc.com","xyz.com"};
    solve(request, n, mp);
    return 0;
}


