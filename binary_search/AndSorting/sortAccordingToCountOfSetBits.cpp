#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <vector>
#include <string>
using namespace std;
struct descComparator{
    bool operator()(const int &lhs,const int &rhs)const{ 
        return lhs>rhs;
    }
};
int main() {
    map<int, vector<int>,descComparator>map; // here template orgument for the template type 
                                                       // parameter must be a type
    int arr[] = {5, 2, 3, 9, 4, 6, 7, 15, 32};
    int n=sizeof(arr)/sizeof(arr[0]);


    // the idea here is counting number of set bits for each element and 
    // and putting it in map with count as key and 

    for(int i=0;i<n;i++){
        int temp=arr[i];
        int count=0;
        while (temp!=0) {
            if ((temp&1) !=0 ) { // & has lower precedence than != so 
                               // != will be evaluated first
                count++;
            }
            temp=temp>>1;
        }
        map[count].push_back(arr[i]);
    }

    for (auto it : map) {
        std::cout<<it.first<<" ";
        std::cout<<"{ ";
        for (auto ele : it.second) {
            std::cout<<ele<<" ";
        }
        std::cout<<" }"<<std::endl;
    }



    return 0;
}


