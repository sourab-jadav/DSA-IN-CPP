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

Node *findIntersection(Node *head1, Node *head2) {
  // while (head2 != nullptr) {
  //   Node *temp = head1;
  //   while (temp != nullptr) {
  //     if (temp == head2) {
  //       return head2;
  //     }
  //     temp = temp->next;
  //   }
  //   head2 = head2->next;
  // }
    //using hashing 
    std::unordered_set<Node*>s;
    while (head1!=nullptr) {
        s.insert(head1);
        head1=head1->next;
    }
    while (head2!=nullptr) {
        if(s.find(head2)!=s.end())return head2;
        head2=head2->next;
    }
  return nullptr;
}
int main() {
  std::vector<int> vec{1, 3, 1, 2, 4};
  std::vector<int> vec2{3, 2, 4};
  Node *head1 = createList(vec);
  Node *head2 = createList(vec2);
  Node* temp=head2->next;
  head2->next=head1->next->next->next;
  delete temp;
  Node *center = findIntersection(head1, head2);
  if(center==nullptr)std::cout<<"no intersection is present"<<std::endl;
  else
   std::cout<<center->val<<std::endl;;

  return 0;
}
