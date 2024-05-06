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

    ListNode* swaphelper(ListNode* p) {
        if (!p || !p -> next) return p;
        auto t = p -> next;
        auto d = p -> next -> next;
        t -> next = p;
        p -> next = swaphelper(d);
        return t;
    }

    ListNode* swapPairs(ListNode* head) {
        auto dummy = new ListNode(0);
        dummy -> next = swaphelper(head);
        return dummy -> next;
    }
};