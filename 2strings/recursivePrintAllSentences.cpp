#include <iostream>
#include <vector>
#include <string>
using namespace std;
// https://www.geeksforgeeks.org/recursively-print-all-sentences-that-can-be-formed-from-list-of-word-lists/
void traverse(vector<vector<string>> vec,int i,string current){ // this is a working solution 
    if (i==vec.size()) {
        std::cout<<current<<std::endl;
        return ;
    }
    for(int j=0;j<vec[i].size();j++){ 
        traverse(vec, i+1, current+vec[i][j]);
    }
}
int main() {
    vector<vector<string>>vec{{"you", "we"},
        {"have", "are"},
        {"sleep", "eat", "drink"}};
    traverse(vec,0,"");
    return 0;
}

