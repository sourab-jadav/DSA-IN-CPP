#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
// also see dynamic_programming/catalanNumber.cpp
void generatePar(int n,string s,int left,int right,vector<string>&seq){
    if (s.length()==2*n) {
        seq.push_back(s);
        return ;
    }
    if (left<n) {
        generatePar(n, s+'(', left+1, right, seq);
    }
    // if (right<n) { // this is not right
    if (right<left) { 
        generatePar(n, s+')', left, right+1, seq);
    }
}
int main() {
    int n;
    std::cout<<"enter the n value"<<std::endl;
    cin>>n;
    vector<string>sequences;
    generatePar(n, "", 0, 0, sequences);
    for_each(sequences.begin(),sequences.end(),[](string str){
            std::cout<<str<<std::endl;
            });
    return 0;
}


