#include <iostream>
#include <string>
#include <vector>
using namespace std;
// printing longest substring which repeats itself
void printSubsequences(string input,string output){
    if (input.empty()) {
        std::cout<<output<<std::endl;
        return ;
    }
    printSubsequences(input.substr(1),output+input[0]);
    printSubsequences(input.substr(1),output);
}
int main() {
  string str = "abcd";
  int n=str.length();
  printSubsequences(str,"");
  return 0;
}
