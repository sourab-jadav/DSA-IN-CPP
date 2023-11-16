#include <iostream>
#include <vector>

struct Node {
  int val;
  Node *next;
  Node(int val) {
    this->val = val;
    this->next = nullptr;
  }
};
Node *createList(std::vector<int> &vec) {
  Node *head = new Node(vec.at(0));
  for (int i = 1; i < (int)vec.size(); i++) {
    Node *temp = head;
    while (temp->next != nullptr) {
      temp = temp->next;
    }
    temp->next = new Node(vec.at(i));
  }
  return head;
}
void printlist(Node *head) {
  Node *temp = head;
  while (temp != nullptr) {
    std::cout << temp->val << " ";
    temp = temp->next;
  }
  std::cout << std::endl;
}


void deletePointer(Node* pointer){
    Node* temp=pointer->next;
    pointer->val=pointer->next->val;
    pointer->next=nullptr;
    delete temp;
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    std::vector<int >vec{
        1,4,2,3
    };
    Node *head=createList(vec);

    Node* pointer=head->next->next;
    printlist(head);
    deletePointer(pointer);
    printlist(head);


    return 0;
}


