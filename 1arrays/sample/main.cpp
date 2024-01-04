// main.cpp

#include <iostream>
#include "LinkedListUtils.h"
using namespace std;

extern "C"
{

    ListNode *createList(int arr[], int size);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    ListNode *head = createList(arr, size);
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }

    // Use the linked list...

    return 0;
}
