#include <iostream>
#include <vector>

// struct Node is modified here
struct Node {
  int val;
  Node *next;
  Node* random;
  Node(int val) {
    this->val = val;
    this->next = nullptr;
    this->random=nullptr;
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

int main() {
    std::cout << "Hello, World!" << std::endl;
    for (int i=0; i<25; i++) {
        std::cout<<"call from sourab do what you want and you will be good!!!"<<std::endl;
    }
    return 0;
}


