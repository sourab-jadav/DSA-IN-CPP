#include <iostream>
#include <vector>
using namespace std;
struct Node {
    int value;
    Node *next;
    Node(int i) {
        this->value = i;
        this->next = nullptr;
    }
};
void push(Node *&head, int value) {
    Node *temp = new Node(value);
    temp->next = head;
    head = temp;
}
// we delete the node with the help of delete keyword
// operations to be implemented are creating linked list pushing popping and
// printing
int main() {
    Node *head = new Node(45);
    head->next = new Node(10);
    push(head, 20);
    push(head, 30);
    while (head) {
        std::cout << head->value << std::endl;
        head = head->next;
    }
    int a=45;
    vector<int> v;
    std::cout<<"this is first game of the file"<<std::endl;
    int n=45;
    std::cout<<"the value of n is "<<n<<std::endl;
}
