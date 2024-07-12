#include <iostream>
#include <ostream>
#include <vector>
struct Node {
  int val;
  Node *next;
  Node(int val) {
    this->val = val;
    this->next = nullptr;
  }
};
// Node *root;
// // reverse the linked list
// Node *reverseList(Node *head) { // this is okay but you can also pass the pointer as reference
//   if (head->next == nullptr) {
//     root = head;
//     return head;
//   }
//   Node *prev = reverseList(head->next);
//   prev->next = head;
//   head->next = nullptr;
//   return head;
// }

Node* reverseLinkedList(Node* root,Node** final){ // this is much better 
    if (root->next==nullptr) {
        *final=root;
        return root;
    }

    Node* temp=reverseLinkedList(root->next, final);
    // here temp is the reference to the next node
    temp->next=root;
    root->next=nullptr;
    return root;
}


//reverse without the recurions
Node* revereWithOutRecursion(Node* head){
    Node* prev=nullptr;
    while (head!=nullptr) {
        Node* temp=head->next;
        head->next=prev;
        prev=head;
        head=temp;
    }
    return prev;
}
// creating a function that takes vector and returns the head of the linked list

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
// printing the list
//finding the middle element
//
void printlist(Node *head) {
  Node *temp = head;
  while (temp != nullptr) {
    std::cout << temp->val << " ";
    temp = temp->next;
  }
  std::cout<<std::endl;
}
Node* findingMiddle(Node * head){
    Node* slow=head;
    Node* fast=head;
    while(fast!=nullptr){
        if(fast->next==nullptr){
            return slow;
        }else if (fast->next->next==nullptr) {
            return slow->next;
        }
        else{
            fast=fast->next->next;
            slow=slow->next;
        }
    }
    return nullptr;
}


int main() {
  std::cout << "Hello, World!" << std::endl;
  std::vector<int> vec{1, 2, 3, 4, 5};
  Node *head = createList(vec);
  std::cout<<"before the reverse is done"<<std::endl;
  printlist(head);
  reverseLinkedList(head, &head);
  std::cout<<"after ther reverse is done"<<std::endl;
  printlist(head);

  // Node *middle=findingMiddle(head);
  // std::cout<<"middle value is "<<middle->val<<std::endl;


  return 0;
}
// this is something written for something else to check something in vim
