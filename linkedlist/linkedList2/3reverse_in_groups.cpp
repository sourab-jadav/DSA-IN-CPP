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

Node *reverseInGroups(Node *head) {
  // first findig the length
  // getting the k value
  Node *temp = head;
  int length{};
  while (temp != nullptr) {
    temp = temp->next;
    length++;
  }
  std::cout << "enter the k value" << std::endl;
  int k;
  std::cin >> k;
  Node* dummyNode=new Node(0);
  dummyNode->next=head;
  Node *curr;
  Node *prev = dummyNode;
  Node *nex;
  while (length - k >= 0) {
    curr = prev->next; // here is the problem by using just pointer instead of node
    nex = curr->next;
    for (int i = 1; i < k; i++) {
      curr->next = nex->next;
      nex->next = prev->next;
      prev->next = nex;
      nex = curr->next;
    }
    prev=curr;
    length -= k;

  }
  std::cout<<head->val<<std::endl;
  return dummyNode->next;
}
int main() {
  std::vector<int> vec{1, 2, 3, 4, 5, 6, 7};
  Node *head = createList(vec);
  printlist(head);
  Node *temp = reverseInGroups(head);
  printlist(temp);
  return 0;
}
