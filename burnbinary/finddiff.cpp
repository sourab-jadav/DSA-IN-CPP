#include <bits/stdc++.h>
using namespace std;

// A linked List Node
struct Node
{
    int data;
    struct Node *next;
};

// A utility which creates Node.
Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}
Node *subtractLinkedList(Node *head1, Node *head2)
{
    int exponent = 0;
    int val1 = 10;
    Node *curr = head1;
    while (curr->next != NULL)
    {
        exponent++;
        curr = curr->next;
    }
    val1 = pow(10, exponent);
    curr = head1;
    int num1 = 0;
    while (curr != NULL)
    {
        num1 += curr->data * val1;
        val1 /= 10;
        curr = curr->next;
    }
    cout << "num1 value is " << num1 << endl;
    curr = head2;
    exponent = 0;
    int val2 = 0;
    while (curr->next != NULL)
    {
        exponent++;
        curr = curr->next;
    }
    val2 = pow(10, exponent);
    int num2 = 0;
    curr = head2;
    while (curr != NULL)
    {
        num2 += curr->data * val2;
        val2 /= 10;
        curr = curr->next;
    }
    int result = abs(num1 - num2);
    int temp = result;
    Node *head = NULL;
    Node *temp_node;
    int some = 0;
    while (temp != 0)
    {
        some = temp % 10;
        temp_node = newNode(some);
        if (head == NULL)
        {
            head = temp_node;
        }
        else
        {
            temp_node->next = head;
            head = temp_node;
        }
        temp = temp / 10;
    }
    return head;
}
void printList(Node *temp)
{
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL";
}
int main()
{
    Node *head1 = newNode(1);
    head1->next = newNode(0);
    head1->next->next = newNode(0);

    Node *head2 = newNode(1);

    Node *result = subtractLinkedList(head1, head2);

    printList(result);

    return 0;
}