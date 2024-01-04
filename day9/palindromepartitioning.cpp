#include <iostream>
#include <string>
#include <vector>
std::vector<std::string>result;
void printPermute(std::string str,int i){
    if(i==str.length()){
        std::cout<<str<<std::endl;
        result.push_back(str);
    }
    for(int j=i;j<str.length();j++){
        std::swap(str[i],str[j]);
        printPermute(str, i+1);
        std::swap(str[i],str[j]);
    }
}
int main() {
    // std::string str="abcdaabd";
    // std::cout<<"printing possible substrings of specified length"<<std::endl;
    // int n;
    // std::cin>>n;
    // std::vector<std::string>temp;
    // for(int i=0;i<=(int)str.length()-n;i++){
    //     std::string str_temp=str.substr(i,n);
    //     temp.push_back(str_temp);
    // }
    // for (auto st : temp) {
    // std::cout<<st<<" ";
    // }
    // std::cout<<std::endl;
    // return 0;
    std::string str="123";
    printPermute(str, 0);


}


