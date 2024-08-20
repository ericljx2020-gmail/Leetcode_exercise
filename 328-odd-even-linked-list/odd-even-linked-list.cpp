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
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return head;
        auto dummy = new ListNode();
        auto p = dummy;
        auto o = head;
        while (o){
            p -> next = new ListNode(o -> val);
            p = p -> next;
            if (o -> next && o -> next -> next) o = o -> next -> next;
            else break;
        }
        auto e = head -> next;
        while (e) {
            p -> next = new ListNode(e -> val);
            p = p -> next;
            if (e -> next && e -> next -> next) e = e -> next -> next;
            else break;
        }
        return dummy -> next;
    }
};