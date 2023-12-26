#include <functional>
#include <iostream>
#include <queue>
#include <vector>

int main() {
    std::priority_queue<int,std::vector<int>,std::greater<int>>q;
    std::priority_queue<int>p;
    p.push(3);
    p.push(10);
    p.push(9);
    p.push(8);
    p.push(7);
    p.push(6);
    p.push(3);
    p.push(10);
    q.push(9);
    q.push(8);
    q.push(7);
    q.push(6);
    std::cout<<p.top()<<std::endl;
    std::queue<int>que;
    que.push(1);
    que.push(2);
    que.push(10);
    que.push(11);
    std::cout<<que.front()<<std::endl;
    return 0;
}


