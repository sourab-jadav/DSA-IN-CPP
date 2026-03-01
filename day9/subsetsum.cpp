#include <iostream>
#include <vector>
// given an array
// int arr[]{5,2,1}
// priting all the possible subsets
// the idea is to take one time and don't take other time
// and if i==n then calculate the sum and push it to the result
//

int sum(std::vector<int>vec){
    int total=0;
    for (auto &x : vec) {
        total+=x;
    }
    return total;
}
// printing the subsets of the given vector
std::vector<int>result;
void printsubsets(std::vector<int>&temp,std::vector<int>&init,int i){
    if (i==(int)init.size()) {
        if (temp.empty()) {
            result.push_back(0);
            return;
        }else{
            int total=0;
            for (auto &x : temp) {
                total+=x;
            }
            result.push_back(total);
            return;
        }
    }
    printsubsets(temp, init, i+1);
    temp.push_back(init.at(i));
    printsubsets(temp, init, i+1);
    temp.pop_back();
}
int main() {
    std::vector<int>vec{
        5,2,1
    };
    std::vector<int>temp{};
    printsubsets(temp, vec, 0);
    for (auto &x : result) {
        std::cout<<x<<" ";
    }
    std::cout<<std::endl;
    return 0;
}

