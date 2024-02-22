#include <iostream>
#include <vector>
struct Node {
  int val;
  Node *next;
  Node() {
    this->val = 0;
    this->next = nullptr;
  }
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
Node *addTwoNumbers(Node *l1, Node *l2) {
  Node * temp= new Node();
  Node* dummy=temp;
  int carry = 0;
  while ((l1 != nullptr || l2 != nullptr )|| carry) {
    int sum = 0;
    if (l1 != nullptr) {
      sum += l1->val;
      l1 = l1->next;
    }
    if (l2 != nullptr) {
      sum += l2->val;
      l2 = l2->next;
    }
    sum += carry;
    carry = sum / 10;
    Node *node = new Node(sum % 10);
    temp->next = node;
    temp = temp->next;
  }
  return dummy->next;
}

int main() {
  std::vector<int> vec{8, 6, 2};
  std::vector<int> vec2{4, 7, 1, 7};
  Node *head1 = createList(vec);
  Node *head2 = createList(vec2);
  Node *temp = addTwoNumbers(head1, head2);
  printlist(temp);

  return 0;
}
