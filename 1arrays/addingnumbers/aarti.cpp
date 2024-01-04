
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
    ListNode *addTwoNumbers(ListNode *first, ListNode *second)
    {
        int n1 = first->val;
        ListNode *p1 = first->next;

        while (p1)
        {
            n1 = n1 * 10 + p1->val;
            p1 = p1->next;
        }

        int n2 = second->val;
        ListNode *p2 = second->next;
        while (p2)
        {
            n2 = n2 * 10 + p2->val;
            p2 = p2->next;
        }
        cout << n1 << endl;
        cout << n2 << endl;
        n1 = reverse(n1);
        cout << n1 << endl;
        n2 = reverse(n2);
        cout << n2 << endl;
        int res = n1 + n2;

        cout << res << endl;

        return convertToLinkedList(res);
    }

    int reverse(int res)
    {
        int rev = 0;
        while (res)
        {
            int r = res % 10;
            rev += rev * 10 + r;
            res = res / 10;
        }
        return rev;
        // cout<<rev<<endl;
    }

    ListNode *convertToLinkedList(int r)
    {
        ListNode *head = NULL;
        ListNode *curr = NULL;
        if (r == 0)
        {
            return new ListNode(r);
        }

        while (r > 0)
        {
            int digit = r % 10;
            r = r / 10;

            ListNode *newNode = new ListNode(digit);

            if (head == nullptr)
            {
                head = newNode;
                curr = head;
            }
            else
            {
                curr->next = newNode;
                curr = curr->next;
            }
        }

        return head;
    }
};

int main()
{

    ListNode *head = new ListNode(2);
    head->next = new ListNode(4);
    head->next->next = new ListNode(9);

    ListNode *head2 = new ListNode(5);
    head2->next = new ListNode(6);
    head2->next->next = new ListNode(4);
    head2->next->next->next = new ListNode(9);
    Solution s;

    ListNode *result = s.addTwoNumbers(head, head2);
    return 0;
}