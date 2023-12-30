#include <iostream>
#include <queue>
#include <vector>
// learn using graph with priority queue which uses max heap or minheap
// for priority queue default is descending order if el<=el2 then the order is descending
bool comparator(std::pair<int, int>p1,std::pair<int, int>p2){
    return p1.second>=p2.second; // stability will be lost if there is no =
}

int main() {
    // normal priority queue
    // std::priority_queue<int>pq; // by default it is max heap
    // std::priority_queue<int,std::vector<int>,std::greater<int>>pq; // this becomes min heap

    std::vector<std::pair<int, int>> edges = {{10,8},{12,5},{7,45},{3,1},{34,25},{16,25}};

    // priority queue with pair
    // std::priority_queue<std::pair<int, int>,std::vector<std::pair<int, int>>>pq; // max heap based on first element
    // std::priority_queue<std::pair<int, int>,std::vector<std::pair<int, int>>,std::greater<std::pair<int, int>>>pq; // min heap based on first element

    // priority queue with comparator
    std::priority_queue<std::pair<int, int>,std::vector<std::pair<int, int>>,decltype(&comparator)>pq(comparator);

    for (auto &x : edges) {
        pq.push(x);
    }
    while (!pq.empty()) {
        std::cout<<pq.top().first<<" "<<pq.top().second<<std::endl;
        // std::cout<<pq.top()<<std::endl;
        pq.pop();
    }
    return 0;
}


