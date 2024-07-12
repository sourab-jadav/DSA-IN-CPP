#include <algorithm>
#include <filesystem>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// this is perfectly working solution --sourabh
struct node {
    int val;
    node *next;
    node(int val) {
        this->val = val;
        this->next = nullptr;
    }
};
void printList(node *root) {
    while (root != nullptr) {
        std::cout << root->val << " ";
        root = root->next;
    }
}
node *reverseInGroupOfN(node *root, node **next_group_start, node **groupEnd,
        int n) {
    if (n == 1 && root != nullptr) {
        *next_group_start = root->next;
        *groupEnd = root;
        return root;
    }
    if (root == nullptr) {
        return nullptr;
    }
    node *temp = reverseInGroupOfN(root->next, next_group_start, groupEnd, n - 1);
    if (temp == nullptr) {
        return nullptr;
    }
    temp->next = root;
    root->next = nullptr;
    return root;
}

int main() {
    // Create a linked list with
    // values 5, 4, 3, 7, 9 and 2
    node *head = new node(1);
    head->next = new node(2); // what gp does
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(5);
    head->next->next->next->next->next = new node(6);
    head->next->next->next->next->next->next = new node(7);
    // printList(head);
    // int n=2;
    int n;
    std::cout << "before :" << std::endl;
    printList(head);
    std::cout << "enter the n value" << std::endl;
    cin >> n;
    node *groupEnd;
    node *groupStart = reverseInGroupOfN(head, &head, &groupEnd, n);
    if (groupStart == nullptr) {
        std::cout << "not possiible" << std::endl;
        return 0;
    }
    node *root = groupEnd;
    // groupStart->next=head;
    while (head != nullptr) {
        node *safeSide = head;
        node *temp = reverseInGroupOfN(head, &head, &groupEnd, n);
        if (temp == nullptr) {
            groupStart->next = safeSide;
            break;
        }
        groupStart->next = groupEnd;
        groupStart = temp;
    }
    printList(root);
    return 0;
}
