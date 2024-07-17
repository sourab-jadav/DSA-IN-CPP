#include <iostream>
#include <type_traits>
#include <vector>
#include <string>
using namespace std;
struct node { 
    int data; 
    struct node* next; 
}; 

void insert(struct node** head, int value) 
{ 
    // Create dynamic node 
    struct node* node 
        = (struct node*)malloc(sizeof(struct node)); 
    if (node == NULL) { 
        // checking memory overflow 
        printf("Memory overflow\n"); 
    } 
    else { 
        node->data = value; 
        node->next = NULL; 
        if (*head == NULL) { 
            *head = node; 
        } 
        else { 
            struct node* temp = *head; 
  
            // finding last node 
            while (temp->next != NULL) { 
                temp = temp->next; 
            } 
  
            // adding node at last position 
            temp->next = node; 
        } 
    } 
} 

void display(struct node* head) 
{ 
    if (head == NULL) { 
        printf("Empty linked list"); 
        return; 
    } 
    struct node* temp = head; 
    printf("\n Linked List :"); 
    while (temp != NULL) { 
        printf("  %d", temp->data); 
        temp = temp->next; 
    } 
} 

// let's learn how we can partitiaon the linked list
node* getLastNode(node* head){
    if (head==nullptr) {
        return nullptr;
    }
    while (head->next!=nullptr) {
        head=head->next;
    }
    return head;
}
// node* partition(node* first,node* last){
//      // we maintain two pointers movabale and result
//     node* move=first; // this is pivot
//     node* result=first; // this is front
//     while (move!=nullptr && move!=last) { // we think about this condition later
//                             // if move->val is less than the result->val then only we swap 
//                             // result val and move val (when result is != move )
//         if (move->data<last->data) {
//             result=first;
//             // what i did here is 
//             // i swap it move value with the result value 
//             // and did result = result->next;
//         }
//         move=move->next;
//     }
//     int temp=last->data;
//     last->data=result->data;
//     result->data=temp;
//     return result; // here i am making mistake i am returning the position which is already placed on 
// }


node* partition(node* first,node* last){
     // we maintain two pointers movabale and result
    node* move=first; // this is pivot
    node* result=first; // this is front
    while (move!=nullptr && move!=last) { // we think about this condition later
                            // if move->val is less than the result->val then only we swap 
                            // result val and move val (when result is != move )
        if (move->data < last->data) {
            result=first;
            if (result!=move) { // avoid swapping the same element
                int temp=result->data;
                result->data=move->data;
                move->data=temp;
            }
            first=first->next;
        }
        move=move->next;
    }
    int temp=first->data;
    first->data=last->data;
    last->data=temp;
    return result; // here i am making mistake i am returning the position which is already placed on 
}

void quick_sort( node* first,  node* last) 
{ 
    if (first == last) { 
        return; 
    } 
     node* pivot = partition(first, last); 
  
    if (pivot != nullptr && pivot->next != nullptr) {  // i don't know what it does if i do 
                                                       // pivot->next->next
        quick_sort(pivot->next, last); 
    } 
    if (pivot != nullptr && first != pivot) { 
        quick_sort(first, pivot); 
    } 
} 

int main() {
    struct node* head = NULL; 
    // Create linked list 
    insert(&head, 41); 
    insert(&head, 5); 
    insert(&head, 7); 
    insert(&head, 22); 
    insert(&head, 28); 
    insert(&head, 63); 
    insert(&head, 4); 
    insert(&head, 8); 
    insert(&head, 2); 
    insert(&head, 11); 
    printf(" Before Sort "); 
    display(head); 
    // quick_sort(head, getLastNode(head));

    quick_sort(head, getLastNode(head));
    display(head); 

    node* temp=nullptr;
  
    return 0;
}


