#include <iostream>
#include <deque>

int main() {
    std::deque<int>mydeque;
    mydeque.push_back(1);
    mydeque.push_back(2);
    mydeque.push_back(3);
    mydeque.push_back(4);


    // pushing elements to the front of the dequeue
    mydeque.push_front(0);
    mydeque.push_front(-1);

    std::cout<<"deque elements: "<<std::endl;
    for(int num:mydeque){
        std::cout<<num<<" ";
    }
    std::cout<<std::endl;
    mydeque.pop_back();
    std::cout<<"updated deuque elements"<<std::endl;
    for(int num:mydeque){
        std::cout<<num<<" ";
    }
    std::cout<<std::endl;
    std::cout<<"Elements at position 2: "<<mydeque.at(2)<<std::endl;
    std::cout<<"Front element: "<<mydeque.front()<<std::endl;
    std::cout<<"Back element: "<<mydeque.back()<<std::endl;

    std::cout<<"is dequeue emepty"<<(mydeque.empty()?"yes":"no")<<std::endl;
    mydeque.clear();

    std::cout<<"is dequeue is empty after clearing"<<(mydeque.empty()?"yes":"no")<<std::endl;
    return 0;
}


