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
Node *mergeLinkedList(Node *left, Node *right) {
  Node *head = nullptr;
  Node *prev =
      (left->val < right->val) ? new Node(left->val) : new Node(right->val);
  std::cout<<left->val<<std::endl;
  while (left != nullptr && right != nullptr) {
    if (left->val < right->val) {
      Node *temp = new Node(left->val);
      prev->next = temp;
      prev = temp;
      left = left->next;
    } else if (left->val == right->val) {
      prev->next = new Node(left->val);
      prev->next->next = new Node(left->val);
      prev = prev->next->next;
      left = left->next;
      right = right->next;
    } else {
      prev->next = new Node(right->val);
      prev = prev->next;
      right = right->next;
    }
    while (left != nullptr) {
      prev->next = new Node(left->val);
      prev = prev->next;
      left = left->next;
    }
    while (right != nullptr) {
      prev->next = new Node(right->val);
      prev = prev->next;
      right = left->next;
    }
  }
  return head;
}

int main() {
  std::vector<int> l1 = {3, 7, 10};
  std::vector<int> l2 = {1, 2, 5, 8, 10};
  Node *left = createList(l1);
  Node *right = createList(l2);
  Node *head = mergeLinkedList(left, right);
  printlist(head);

  return 0;
}
