#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
// https://leetcode.com/problems/merge-k-sorted-lists/
// this solution is not working for the test case
// [[],[]]
// because the first list is empty
// and we are sorting the list based on the first value of the list
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *createList(std::vector<int> &vec) {
    ListNode *head = new ListNode(vec.at(0));
    for (int i = 1; i < (int)vec.size(); i++) {
        ListNode *temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = new ListNode(vec.at(i));
    }
    return head;
}

class Solution {
    public:
        ListNode *mergeKLists(vector<ListNode *> &li) {
            // you need to sort the vector of list node based on the first value of the
            // list node
            if (li.size() == 0) {
                return nullptr;
            }
            vector<ListNode *> nli;
            for (int i = 0; i < (int)li.size(); i++) {
                if (li[i] != nullptr) {
                    nli.push_back(li[i]);
                }
            }
            if (!nli.empty()) {
                sort(nli.begin(), nli.end(), [](ListNode *a, ListNode *b) { return a->val < b->val; });
                ListNode *main = nli[0];
                for (int i = 1; i < (int)li.size(); i++) {
                    ListNode *head1 = main;
                    ListNode *head2 = li[i];
                    while (head2 != nullptr) {
                        while (head1->next != nullptr && head1->next->val < head2->val) {
                            head1 = head1->next;
                        }
                        ListNode *temp1 = head1->next;
                        head1->next = head2;
                        head2 = head2->next;
                        if (head1->next != nullptr) {
                            head1->next->next = temp1;
                        }
                    }
                }
                return main;
            } else {
                return nullptr;
            }
        }
};

int main() {
    vector<int> l1 = {1, 4, 5};
    vector<int> l2 = {1, 3, 4};
    vector<int> l3 = {2, 6};
    ListNode *head1 = createList(l1);
    ListNode *head2 = createList(l2);
    ListNode *head3 = createList(l3);
    vector<ListNode *> lists;
    lists.push_back(head1);
    lists.push_back(head3);
    lists.push_back(head2);

    Solution s;
    // for (auto list : lists) {
    //     while (list != nullptr) {
    //         cout << list->val << " ";
    //         list = list->next;
    //     }
    //     cout << endl;
    // }

    ListNode *result = s.mergeKLists(lists);
    while (result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}
