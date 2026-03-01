#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *head = nullptr;
    int temp = 0;
    ListNode *reverse(ListNode *l1)
    {
        if (l1->next == nullptr)
        {
            head = l1;
            return l1;
        }
        temp++;
        ListNode *prev = reverse(l1->next);
        temp--;
        if (temp == 0)
        {
            prev->next = l1;
            l1->next = nullptr;
            return head;
        }
        else
        {
            ListNode *temp2 = l1;
            prev->next = l1;
            l1->next = nullptr;
            return l1;
        }
    }
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *list1 = l1;
        ListNode *list2 = l2;
        cout << "list1 reverse" << endl;
        ListNode *temp = list1;
        while (temp)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
        temp = list2;
        cout << "list2 reverse" << endl;
        while (temp)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;

        ListNode *final = nullptr;
        int carry = 0;
        while (list1 != nullptr || list2 != nullptr || carry != 0)
        {
            int sum = 0;
            if (list1 != nullptr)
            {
                sum += list1->val;
                list1 = list1->next;
            }
            if (list2 != nullptr)
            {
                sum += list2->val;
                list2 = list2->next;
            }
            sum += carry;
            if (final == nullptr)
            {
                final = new ListNode(sum % 10);
            }
            else
            {
                ListNode *temp = final;
                while (temp->next != nullptr)
                {
                    temp = temp->next;
                }
                temp->next = new ListNode(sum % 10);
            }
            carry = sum / 10;
        }
        return final;
    }
};

int main()
{
    ListNode *head = new ListNode(2);
    head->next = new ListNode(4);
    head->next->next = new ListNode(9);
    // head->next->next->next = new ListNode(8);
    ListNode *head11 = head;
    cout << "list1 :" << endl;
    while (head11)
    {
        cout << head11->val << " ";
        head11 = head11->next;
    }
    cout << endl;

    ListNode *head2 = new ListNode(5);
    head2->next = new ListNode(6);
    head2->next->next = new ListNode(4);
    head2->next->next->next = new ListNode(9);

    head11 = head2;

    cout << "list2 :" << endl;
    while (head11)
    {
        cout << head11->val << " ";
        head11 = head11->next;
    }
    cout << endl;
    Solution s;
    ListNode *result = s.addTwoNumbers(head, head2);
    while (result)
    {
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}