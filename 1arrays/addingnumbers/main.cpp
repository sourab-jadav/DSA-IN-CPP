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
    int getNumber(ListNode *l1)
    {
        int mul = 1;
        int temp = 0;
        while (l1 != nullptr)
        {
            temp += l1->val * mul;
            mul *= 10;
            l1 = l1->next;
        }
        return temp;
    }
    ListNode *getList(int n)
    {
        ListNode *head = nullptr;
        while (n != 0)
        {
            int r = n % 10;
            if (head == nullptr)
            {
                head = new ListNode(r);
            }
            else
            {
                ListNode *temp = head;
                while (temp->next != nullptr)
                {
                    temp = temp->next;
                }
                temp->next = new ListNode(r);
            }
            n = n / 10;
        }
        return head;
    }
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int op1 = getNumber(l1);
        int op2 = getNumber(l2);
        int result = op1 + op2;
        ListNode *res = getList(result);
        return res;
    }
};

int main()
{
    ListNode *head = new ListNode(2);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);

    ListNode *head2 = new ListNode(5);
    head2->next = new ListNode(6);
    head2->next->next = new ListNode(4);
    Solution s;
    ListNode *result = s.addTwoNumbers(head, head2);
    while (result != nullptr)
    {
        cout << result->val << " ";
        result = result->next;
    }

    return 0;
}