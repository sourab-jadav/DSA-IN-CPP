#include <cstdio>
#include <stdlib.h>
using namespace std;
// creating node in c
typedef struct Node node ;

struct Node{
    int value;
    node* next;
};

void push(node** addr,int value){
    node * temp=(node*)malloc(sizeof(node));
    temp->value=value;
    temp->next=*addr;
    *addr=temp;
}

void print(node* head){
    while (head!=nullptr) {
        printf("%d ",head->value);
        head=head->next;
    }
}


int main() {
    node* head;
    push(&head, 10);
    push(&head, 20);
    push(&head,30);
    push(&head,40);
    push(&head,50);


    while (head!=nullptr) {
        printf("the value of the data is %d",head->value);
        printf("\n");
        printf("it's next address is %p",head->next);
        head=head->next;
        printf("\n");
    }
    return 0;
}
    // string str = "ynyo";
    // int n = str.length();
    // vector<char> s;
    // int result = 0;
    // for (int i = 0; i < n; i++) {
    //     if (find(s.begin(), s.end(), str[i]) == s.end()) {
    //         s.push_back(str[i]);
    //         result = max(result, (int)s.size());
    //     } else {
    //         auto it = find(s.begin(), s.end(), str[i]);
    //
    //         it++;
    //         s.erase(s.begin(), it);
    //         s.push_back(str[i]);
    //     }
    // }
    // cout << result;
    // return 0;

