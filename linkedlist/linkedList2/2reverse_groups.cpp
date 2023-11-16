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

Node *reverse(Node *head, int d,Node* prev) {
  Node *result = nullptr;
  int count = 0;
  while (count < d) {
    if (prev == nullptr) {
      result = head;
    }
    Node *temp = head->next;
    head->next = prev;
    prev = head;
    head=temp;
    count++;
  }
  return result;
}

int main() {
  std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
  Node *head = createList(vec);
  printlist(head);
  int n;
  std::cout << "enter the groups youw ant to reverse:" << std::endl;
  std::cin >> n;
  Node* prev=nullptr;
  Node*first =reverse(head, 3,prev);

  return 0;
}
