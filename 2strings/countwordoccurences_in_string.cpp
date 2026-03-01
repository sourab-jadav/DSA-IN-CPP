#include <iostream>
#include <map>
#include <string>
// N,A,A,N,X,B,A,A,N,B,A,B,Y,Z,N,A,N,X (ip) ->  N,A,A,N,X,B,A,N,B,Y,Z,X ->
// N,X,B,Y,Z,X count = 2 (op) Count the occurences of the word 'BANANA' in the
// string

int main() {
    std::string str = "NAANXAANAYZNANX";
    std::string check = "BANANA";
    std::map<char, int> m;
    for (auto &x : str) {
        m[x]++;
    }
    for (auto &x : m) {
        std::cout << x.first << " " << x.second << std::endl;
    }
    int count = 0;
    bool flag = true;
    while (flag) {
        int checkCount=0;
        for (auto &x : check) {
            if(m[x]==0){
                flag=false;
                break;
            }else {
                checkCount++;
                m[x]--;
            }
            if (checkCount==(int)check.length()) {
                count++;
            }
        }
    }
    std::cout<<"the length is "<<count<<std::endl;

    return 0;
}
