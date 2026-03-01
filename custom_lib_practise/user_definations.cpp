#include "user_definations.h"
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iostream>

std::vector<int> genV(int n){
    std::srand(std::time(0));

    std::vector<int> randomNumbers;

    for (int i = 0; i < n; ++i) {
        // Generate a random number in the range [1, 100]
        int randomNumber = std::rand() % 100 + 1;
        randomNumbers.push_back(randomNumber);
    }

    return randomNumbers;
}

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

