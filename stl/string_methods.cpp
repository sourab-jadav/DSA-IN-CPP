#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    string str="hello";
    // str.erase(str.begin()+1,str.begin()+3); // this removes elements from index 1 to 3(exclusive)
    // str.erase(3); // remove all characters from index 3 to the end of the string
    // str.erase(1,3); // from index 1 of length 3 (this is right)
                    // not from index 1 to 3(exclusive)
    // str.erase(str.begin()); // remove the character at index 0
    // the above three methods are different
    std::cout<<str<<std::endl;
    return 0;
}


