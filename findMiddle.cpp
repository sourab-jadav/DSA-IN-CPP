#include <iostream>
#include <vector>
#include <string>
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
int main() {
    Node* head= new Node(45);

    return 0;
}


