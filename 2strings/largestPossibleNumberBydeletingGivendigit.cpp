#include <climits>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;
int main() {
    int num=936230;
    stringstream st;
    int result=INT_MIN;
    st<<num;
    int digit=3;
    string str;
    st>>str;
    for(int i=0;i<str.length();i++){
        int k=str[i]-'0';
        if (k ==digit) {
            string temp=str;
            temp.erase(temp.begin()+i);
            result=max(stoi(temp),result);
        }
    }
    std::cout<<result<<std::endl;
    return 0;
}


