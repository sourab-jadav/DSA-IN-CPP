#include <iostream>
#include <unordered_map>
#include <vector>

struct Node {
    int val;
    Node *next;
    Node *arbit;
    Node(int val) {
        this->val = val;
        this->next = nullptr;
        this->arbit = nullptr;
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
    std::cout << head->val << "(" << head->arbit->val << ")";
    head = head->next;
    while (head != nullptr) {
        std::cout << "->" << head->val << "(" << head->arbit->val << ")";
        head = head->next;
    }
}
Node *cloneLinkedList(Node *head) {
    std::unordered_map<Node *, Node *> mp;
    Node *temp = head;
    Node *head1 = new Node(temp->val);
    mp[temp] = head1;
    temp = temp->next;
    while (temp != nullptr) {
        head1->next = new Node(temp->val);
        head1 = head1->next;
        mp[temp] = head1;
        temp = temp->next;
    }
    temp = head;
    while (temp != nullptr) {
        mp[temp]->arbit = mp[temp->arbit];
        temp = temp->next;
    }
    return mp[head];
}
int main() {
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->arbit = head->next->next;
    head->next->arbit = head;
    head->next->next->arbit = head->next->next->next->next;
    head->next->next->next->arbit = head->next->next;
    head->next->next->next->next->arbit = head->next;
    printlist(head);
    Node *result = cloneLinkedList(head);
    std::cout << std::endl;
    printlist(result);
    return 0;
}
