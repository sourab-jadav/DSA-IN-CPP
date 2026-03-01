#include <filesystem>
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

int main() {
  std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  Node *head = createList(vec);
  std::cout << "enter which node you want to delete from last?" << std::endl;
  int n;
  std::cin >> n;
  Node *slow = head;
  Node *fast = head;
  for (int i = n - 1; i > 0; i--) {
    fast = fast->next;
  }
  Node *temp = nullptr;
  while (fast != nullptr) {
    if (fast->next == nullptr) {
      temp = slow;
      break;
    }
    fast = fast->next;
    slow = slow->next;
  }
  std::cout << temp->val << std::endl;

  return 0;
}
