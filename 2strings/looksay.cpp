#include <iostream>
#include <vector>
#include <string>
using namespace std;
string look_and_say(string str,int n){
    if (n==1) {
        return str;
    }
    string t="";
    for(int i=0;i<str.length();){
        int count=1;
        int c=str[i];
        int j;
        for( j=i+1;str[j]==str[i] && j<str.length();j++){
            if (str[i]==c) {
                count++;
            }
        }
       t+=to_string(count)+str[i];
       i=j;
    }
    return look_and_say(t,n-1);
}
int main() {
    int n;
    cin>>n;
    string s="1";
    string result=look_and_say(s,n);
    std::cout<<result<<std::endl;
    return 0;
}


