/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(-1);
        dummy -> next = head;
        auto p = dummy;

        while (p && p -> next) {
            auto d = p;
            while (d -> next && d -> next -> val == val) {
                d = d -> next;
            }
            p->next = d -> next;
            p = p -> next;
        }
        return dummy -> next;
    }
};