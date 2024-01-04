#ifndef USER_DEFINITIONS_H
#define USER_DEFINITIONS_H

#include <vector>
struct Node {
  int val;
  Node *next;
  Node(int val) {
    this->val = val;
    this->next = nullptr;
  }
};
std::vector<int> genV(int n);
Node *createList(std::vector<int> &vec);
void printlist(Node *head);
#endif // USER_DEFINITIONS_H

