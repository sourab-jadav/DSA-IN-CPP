#include <algorithm>
#include <iostream>
#include <vector>
std::vector<std::vector<int>>result;
void findAllUniqueCombinations(std::vector<int>&temp,std::vector<int>&init,int target,int i){
    if (target==0) {
        result.push_back(temp);
        return;
    }
    for(int j=i;j<(int)init.size();j++){
        if(j!=i && init[j]==init[j-1])continue;
        if (target-init[j]>=0) {
            temp.push_back(init[j]);
            findAllUniqueCombinations(temp, init, target-init[j], j+1);
            temp.pop_back();
        }
    }
}

int main() {
    std::vector<int>init{
        10,1,2,7,6,1,2,5
    };
    std::sort(init.begin(),init.end());
    std::vector<int>temp;
    std::cout<<"the idea is to print all the unique combinations"<<std::endl;
    findAllUniqueCombinations(temp, init, 8, 0);
    for (auto x : result) {
        for (auto value : x) {
        std::cout<<value<<" ";
        }
        std::cout<<std::endl;
    }
    return 0;
}
