#include <cstdlib>
#include <iostream>
#include <unordered_set>
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

Node *findStart(Node *head) {
  Node *slow = head;
  Node *fast = head;
  slow = slow->next;
  fast = fast->next->next;
  while (slow != fast) {
    slow = slow->next;
    fast = fast->next->next;
    if (fast==nullptr || fast->next==nullptr) {
        std::cout<<"no cycle"<<std::endl;
        exit(0);
    }
  }
  std::cout << slow->val << std::endl;
  slow = head;
  while (slow->next->val != fast->next->val) {
    slow = slow->next;
    fast = fast->next;
  }
  return slow;
}
Node *join(Node *head) {
  while (head != nullptr) {
    if (head->val == 10) {
      return head;
    }
    head = head->next;
  }
  return nullptr;
}
int main() {
  std::cout << "Hello, World!" << std::endl;
  std::vector<int> vec{1, 2, 3, 4, 3, 6, 10};
  Node *head = createList(vec);
  Node *value = join(head);
  value->next = head->next->next;
  Node *result = findStart(head);
  std::cout << "starting point found at value " << result->val << std::endl;

  return 0;
}
