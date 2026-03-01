#include <cstdlib>
#include <iostream>
// in queue when you push u push towards the end 
// and when you delete you delete from the start
// .front() method gives start side of the queue
class Queue{
    int*arr;
    int start,end,currsize,maxsize;
    public:
    Queue(){
        arr=new int[16];
        start=-1;
        end=-1;
        currsize=0;
    }
    Queue(int maxsize){
        this->maxsize=maxsize;
        arr=new int[maxsize];
        start=-1;
        end=-1;
        currsize=0;
    }
    void push(int element){
        // think while pushing what things should keep in mind
        // it should not exceed the size

        if (currsize==maxsize) {
            std::cout<<"queue is full and exiting"<<std::endl;
            exit(1);
        }
        if(end==-1){
            start=0;
            end=0;
        }else{
            end=(end+1)%maxsize;
        }
        arr[end]=element;
        std::cout<<"the element is pushed into the queue"<<std::endl;
        currsize++;
    }
    int pop(){
        if (start==-1) {
            std::cout<<"nothing to pop "<<std::endl;
            exit(1);
        }
        int popped=arr[start];
        if (currsize==1) {
            start=-1;
            end=-1;
        }
        else {
        start=(start+1)%maxsize;
        }
        currsize--;
        return popped;
    }
    int top(){
        if(start==-1){
            std::cout<<"queue is empty"<<std::endl;
            exit(1);
        }
        return arr[start];
    }
    int size(){
        return currsize;
    }
};

int main() {
    Queue q(6);
    q.push(4);
    q.push(14);
    q.push(34);
    std::cout<<"what is so fucking awesome about this thing"<<std::endl;
    std::cout<<q.top()<<std::endl;
}


