#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

struct Node {
    int val;
    Node *next;
    Node *bottom;
    Node(int val) {
        this->val = val;
        this->next = nullptr;
        this->bottom = nullptr;
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
Node *createBottomList(std::vector<int> &vec) {
    Node *head = new Node(vec.at(0));
    for (int i = 1; i < (int)vec.size(); i++) {
        Node *temp = head;
        while (temp->bottom != nullptr) {
            temp = temp->bottom;
        }
        temp->bottom = new Node(vec.at(i));
    }
    return head;
}
void printlist(Node *head) {
    Node *temp = head;
    while (temp != nullptr) {
        std::cout << temp->val << " ";
        Node *bottom = temp->bottom;
        while (bottom != nullptr) {
            std::cout << bottom->val << " ";
            bottom = bottom->bottom;
        }
        temp = temp->next;
    }
    std::cout << std::endl;
}
// typedef pair<int, Node*>pi;
// void flattenTheList(Node* head){
//     std::priority_queue<pi,std::vector<pi>,greater<pi>> minh;
//     Node* dummy = new Node(-1);
//     for(Node* cur = head; cur != nullptr; cur = cur->next){
//         minh.push({cur->val, cur});
//     }
//     Node* dummpy=new Node(-1);
//     Node* temp=dummy;
//     while (!minh.empty()){
//         Node* node=minh.top().second;
//         temp->bottom=node;
//         temp=temp->bottom;
//         temp->next=nullptr;
//         minh.pop();
//         if(node->bottom){
//             minh.push({node->bottom->val, node->bottom});
//         }
//     }
// }

// without priority queue // and recursion
// Node *merge(Node *a, Node *b) {
//     if (a == nullptr) {
//         return b;
//     }
//     if (b == nullptr) {
//         return a;
//     }
//     Node *result;
//     if (a->val < b->val) {
//         result = a;
//         result->bottom = merge(a->bottom, b);
//     } else {
//         result = b;
//         result->bottom = merge(a, b->bottom);
//     }
//     result->next = nullptr;
//     return result;
// }
// Node *flattenTheList(Node *head) {
//     if (head == nullptr || head->next == nullptr) {
//         return head;
//     }
//     head->next = flattenTheList(head->next);
//     head = merge(head, head->next);
//     return head;
// }
// void printResult(Node *head) {
//     Node *temp = head;
//     while (temp != nullptr) {
//         std::cout << temp->val << " ";
//         temp = temp->bottom;
//     }
//     std::cout << std::endl;
// }

// without priority queue and without recursion
Node* merge(Node* head1,Node* head2){
    // create a dummy node and apply the two point approach on the two heads
    Node* root=new Node(-1);
    Node* temp=root;
    while (head1!=nullptr && head2!=nullptr) {
        if (head1->val<head2->val) {
            temp->bottom=head1;
            head1=head1->bottom;
        }
        // else if (head2->val<head1->val) { // optimizing this part
        //     temp->bottom=head2;
        //     head2=head2->bottom;
        // }else {
        //     temp->bottom=head1;
        //     head1=head1->bottom;
        //     temp=temp->bottom;
        //     temp->bottom=head2;
        //     head2=head2->bottom;
        // }
        else {
            temp->bottom=head2;
            temp=temp->bottom;
            head2=head2->bottom;
        }
        temp=temp->bottom;
    }
    if (head1) {
        // head1 still exist
        temp->bottom=head1;
    }else {
        temp->bottom=head2;
    }
    return root->bottom;
}
Node* flattenTheList(Node* head){
    if (head==nullptr or head->next==nullptr) {
        return head;
    }
    // recur for the end of the list
    head->next=flattenTheList(head->next);
    head=merge(head,head->next);
    return head;
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    // first defining the top vector
    std::vector<int> top{5, 10, 19, 28};
    std::vector<std::vector<int>> bottom{
        {7, 8, 10}, {20}, {22, 50}, {35, 40, 45}};
    Node *head = createList(top);
    Node *temp = head;
    int i = 0;
    while (temp != nullptr && i < (int)bottom.size()) {
        Node *sublist = createBottomList(bottom[i]);
        temp->bottom = sublist;
        temp = temp->next;
        i++;
    }
    // printlist(head); // the bottom list is being created
    flattenTheList(head);
    printlist(head);
    return 0;
}
