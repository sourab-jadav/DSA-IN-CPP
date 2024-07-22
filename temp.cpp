#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;
// creating a linked list and getting the nth element from the end
struct Node {
    int data;
    Node *next;
    Node(int n) {
        this->data = n;
        this->next = nullptr;
    }
};

void push(Node *&head, int n) {
    Node *temp = new Node(n);
    temp->next = head;
    head = temp;
}
void printlist(Node *head) {
    while (head) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}
// finding the nth element from the end using two pointer
// void findMiddle(Node *head, int n) {
//     Node *ref = head;
//     Node *main = head;
//
//     int i = 0;
//     while (i < n) {
//         if (ref == nullptr) {
//             std::cout << "n value is greater than the length of the list"
//                 << std::endl;
//             return;
//         }
//         ref = ref->next;
//         i++;
//     }
//     while (ref != nullptr) {
//         main = main->next;
//         ref = ref->next;
//     }
//     std::cout << main->data << std::endl;
// }
// detecting the cycle in the loop
// void detectCycle(Node *head) {
//     Node *slow = head;
//     Node *fast = head;
//     do {
//         slow = slow->next;
//         fast = fast->next->next;
//     } while (slow != fast);
//     slow = head;
//     while (slow != fast) {
//         slow = slow->next;
//         fast = fast->next;
//     }
//     std::cout << slow->data << std::endl;
// }
int main() {

    int arr[]{5,6,12,14,17};
    int n=sizeof(arr)/sizeof(arr[0]);
    auto it=lower_bound(arr,arr+n,8); 
    std::cout<<it-arr<<std::endl;
    // Node *head = new Node(1);
    // push(head, 2);
    // push(head, 3);
    // push(head, 4);
    // push(head, 5);
    // push(head, 6);
    // vector<int>vec{1,2,3,4,5};
    // // Node *temp = head;
    // // int i = 0;
    // // while (i < 5) {
    // //     temp = temp->next;
    // //     i++;
    // // }
    // // temp->next = head->next;
    // // detectCycle(head);
    //
    // return 0;
}
