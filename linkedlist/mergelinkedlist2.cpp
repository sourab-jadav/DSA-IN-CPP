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

Node *mergeLinkedList(Node *t1, Node *t2) {
  Node *temp = nullptr;
  Node *head1 = nullptr;
  Node *head2 = nullptr;
  if (t1->val < t2->val) {
    head1 = t1;
    head2 = t2;
    temp = t1;
  } else {
    head1 = t2;
    head2 = t1;
    temp = t2;
  }
  while (head1->next  && head2->next ) {
    while (head1->next  && head1->next->val < head2->val) {
      head1 = head1->next;
    }
    Node *temp1 = head1->next;
    head1->next = head2;
    while (head2->next  && head2->next->val < temp1->val) {
      head2 = head2->next;
    }
    Node *temp2 = head2->next;
    head2->next = temp1;
    head1 = temp1;
    head2 = temp2;
  }
  if (head1->next == nullptr) {
    head1->next = head2;
  }
  return temp;
}

int main() {
  std::vector<int> list1{3, 7, 7, 7, 10};
  // std::vector<int> list1{5,10,15};
  std::vector<int> list2{1, 2, 5, 8, 10};
  // std::vector<int> list2{2,3,20};
  Node *head1 = createList(list1);
  Node *head2 = createList(list2);
  Node *final = mergeLinkedList(head1, head2);
  printlist(final);

  return 0;
}
// ith node from the back is n-i+1the node from the front
