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

    bool helperDouble(ListNode* p) {
        if (!p) return false;
        bool a = helperDouble(p -> next);
        int cur = p -> val * 2;
        bool t = false;
        if (cur >= 10) t = true;
        p -> val = cur % 10 + a;
        return t;
    }

    ListNode* doubleIt(ListNode* head) {
        auto dummy = new ListNode(0);
        dummy -> next = head;
        bool tmp = helperDouble(head);
        ListNode* p;
        if (tmp) {
            p = new ListNode(1);
            p -> next = head;
            dummy -> next = p;   
        }
        return dummy -> next;
    }
};