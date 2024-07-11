#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

// struct CompareSecond{
//     bool operator()(const std::pair<int, int>&left,const std::pair<int, int>&right){
//         return left.second> right.second;
//     }
// };
//
// priority_queue is by default max heap if you use greater function it becomes min heap
int main() {
    std::priority_queue<std::pair<int, int>,std::vector<std::pair<int, int>>,std::greater<std::pair<int, int>>>pq; // creates the priority queue
                                                                                                                   // based on first element
                                                                                                                   // here vector is the underlying
                                                                                                                   // container
    //creating a priority queue based on the second element
    // std::priority_queue<std::pair<int, int>,std::vector<std::pair<int, int>>,CompareSecond>>>pq;         
                                                                                                            
    pq.push({0,1});
    pq.push({2,3});
    pq.push({4,0});
    pq.push({1,5});
    while (!pq.empty()) {
        std::cout<<pq.top().first<<" "<<pq.top().second<<std::endl;
        pq.pop();
    }
    return 0;
}


