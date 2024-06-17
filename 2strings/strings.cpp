#include <iostream>
#include <typeinfo>
#include <string>
//
// using namespace std;
//
// int main()
// {
//     string s = "lkjsdlfj";
//     cout << typeid(s[0]).name();
//     int a = 45;
//     cout << endl;
//     cout << typeid(a).name();
// }
using namespace std;
bool check_suffle(string &s1,string &s2,string &result){
    string s1_s2=s1+s2;
    if (s1_s2.length()!=result.length()) {
        return false;
    }
    for (auto &c : result) {
        if (s1_s2.find(c)==string::npos) {
            return false;
        }
    }
    return true;
}
int main() {
    // check one is rotation of other
    // string str="geeksforgeeks";
    // string str2="forgeeksgeeks";
    // string result=str+str;
    //
    // if (result.find(str2)!=string::npos) {
    //     std::cout<<"Yes they are rotation of each other "<<std::endl;
    // }else {
    //     std::cout<<"No they are not rotations of each other"<<std::endl;
    // }
    // return 0;

    // if one is a right shuffle of other 
    string s1="abc";
    string s2="def";
    string result="adbcef";
    bool res=check_suffle(s1, s2, result);
    std::cout<<res<<std::endl;

}

