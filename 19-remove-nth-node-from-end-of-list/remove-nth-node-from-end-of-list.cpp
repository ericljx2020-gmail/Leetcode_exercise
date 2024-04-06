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
    int idx = 0;
    ListNode* helper(ListNode* head, int n){
        if (head == NULL) {
            return NULL;
        }
        head -> next = helper(head -> next, n);
        idx++;
        if (idx == n) return head -> next;
        return head;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto dummy = new ListNode(0);
        dummy -> next = head;
        dummy = helper(dummy, n);
        return dummy -> next;
    }
};