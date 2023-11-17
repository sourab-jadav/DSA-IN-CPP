#include <iostream>
#include <vector>

struct Node {
  int val;
  Node *next;
  Node *bottom;
  Node(int val) {
    this->val = val;
    this->next = nullptr;
    this->bottom = nullptr;
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
Node *createBottomList(std::vector<int> &vec) {
  Node *head = new Node(vec.at(0));
  for (int i = 1; i < (int)vec.size(); i++) {
    Node *temp = head;
    while (temp->bottom != nullptr) {
      temp = temp->bottom;
    }
    temp->bottom = new Node(vec.at(i));
  }
  return head;
}
void printlist(Node *head) {
  Node *temp = head;
  while (temp != nullptr) {
    std::cout << temp->val << " ";
    Node *bottom = temp->bottom;
    while (bottom != nullptr) {
      std::cout << bottom->val << " ";
      bottom = bottom->bottom;
    }
    temp = temp->next;
  }
  std::cout << std::endl;
}

int main() {
  std::cout << "Hello, World!" << std::endl;
  // first defining the top vector
  std::vector<int> top{5, 10, 19, 28};
  std::vector<std::vector<int>> bottom{
      {7, 8, 10}, {20}, {22, 50}, {35, 40, 45}};
  Node *head = createList(top);
  Node *temp = head;
  int i = 0;
  while (temp != nullptr && i < (int)bottom.size()) {
    Node *sublist = createBottomList(bottom[i]);
    temp->bottom = sublist;
    temp = temp->next;
    i++;
  }
  printlist(head);

  return 0;
}
