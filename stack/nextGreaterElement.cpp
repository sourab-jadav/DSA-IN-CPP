#include <iostream>
#include <stack>
#include <vector>
void print(std::vector<int>&vec){

    for (auto x : vec) {
    std::cout<<x<<" ";
    }
    std::cout<<std::endl;
}
int main() {
    std::vector<int>vec{
        3,10,4,2,1,2,6,1,7,2,9
    };
    int n=vec.size();
    std::vector<int>result(n,-1);
    std::stack<int>stk;


    // assuming array is non circular in nature
    // for(int i=n-1;i>=0;i--){
    //     while (!stk.empty()&&stk.top()<vec[i]) {
    //         stk.pop();
    //     }
    //     if (!stk.empty()) {
    //         result[i]=stk.top();
    //     }
    //     stk.push(vec[i]);
    // }





    return 0;
}


