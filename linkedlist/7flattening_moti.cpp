#include <iostream>
 #include<bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;

class Node {
 public:
 	int data;
 	Node *next;
		Node *child;
 	Node() : data(0), next(nullptr), child(nullptr){};
 	Node(int x) : data(x), next(nullptr), child(nullptr) {}
 	Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
};


typedef pair<int, Node*> pi;

Node* flattenLinkedList(Node* head) 
{
	priority_queue<pi, vector<pi>, greater<pi>> minh;
    Node* dummy = new Node(-1);

    for(Node* cur = head; cur->next != NULL; cur = cur->next)
        minh.push({cur->data, cur});
        
    Node* temp = dummy;

    while(!minh.empty()){
        Node* node = minh.top().second;  
        
        temp->child = node;
        temp = temp->child;
        temp->next = NULL;
        
        minh.pop();
        if(node->child)
            minh.push({node->child->data, node->child});
    }
    return dummy->child;

}
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

