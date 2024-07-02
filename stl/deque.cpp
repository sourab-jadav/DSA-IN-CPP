#include <deque>
#include <iostream>
#include <queue>
#include <vector>
#include <string>
// NOTE: in queue the direction of insertion and removal is from left to right
// i.e you insert from back and remove from front (B to F)
// follows FIFO principle
using namespace std;
int main() {
    // difference between queue and doubly ended queue
    queue<int>q;
    deque<int>dq;
    q.push(10); // in queue you push towards front and  you pop from the back 
    q.push(20);
    q.push(30);
    // std::cout<<q.back()<<std::endl; // should be 30
    // std::cout<<q.front()<<std::endl; // should be 10
    // q.pop();  // 10 from the queue
    //           // now front will be 20
    // std::cout<<q.front()<<std::endl; // it is 20
    //

    while (!q.empty()) {
        std::cout<<q.front()<<std::endl;
        q.pop();
    }
    // behaving deque as queue // we can do that by inserting into the deque from the back and
    // removing it from the front
    dq.push_back(10);
    dq.push_back(20);
    dq.push_back(30);
    while (!dq.empty()) {
        std::cout<<dq.front()<<std::endl;
        dq.pop_front();
    }
    return 0;
}


