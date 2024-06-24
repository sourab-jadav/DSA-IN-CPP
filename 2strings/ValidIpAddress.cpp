#include <ios>
#include <iostream>
#include <sstream>
#include <type_traits>
#include <vector>
#include <string>
using namespace std;
int main() {
    string input ="25525511135";
    int n=input.length();
    vector<string>result;
    stringstream ss;
    // bool flag=true;
    // for(int i=0;i<n-1;){
    //     string part=input.substr(i,3);
    //     if (part[0]=='0'|| stoi(part)>255) {
    //         flag=false;
    //         break;
    //     }
    //     ss<<part<<" "; // here if you do not include spaces then the behaviour will not be as expected
    //     // ss<<part;
    //     i+=3;
    // }
    // if (flag) {
    //     result.push_back(ss.str());
    // }
    // ss.str(string());
    for(int i=0;i<n-1;i+=3){
        bool flag=true;
        for(int j=0;j<n-1;){
            if (i==j) {
                string part=input.substr(i,2);
                if (part[0]=='0') {
                    flag=false;
                    break;
                }
                j+=2;
                ss<<part<<" ";
            }else {
                string part=input.substr(j,3);
                if (part[0]=='0'|| stoi(part)>255) {
                    flag=false;
                    break;
                }
                j+=3;
                ss<<part<<" ";
            }
        }
        if (flag) {
            result.push_back(ss.str());
            // ss.clear();
            // The clear() member function is inherited from ios and is used to clear the error state of the stream,
            // e.g. if a file stream has the error state set to eofbit (end-of-file), then calling clear() 
            // will set the error state back to goodbit (no error).
            ss.str(string()); // this will set the string present in the ss stream to ""
        }else {
            ss.str(string());
        }
    }
    for(auto it:result){
        std::cout<<it<<std::endl;
    }
    return 0;
}


