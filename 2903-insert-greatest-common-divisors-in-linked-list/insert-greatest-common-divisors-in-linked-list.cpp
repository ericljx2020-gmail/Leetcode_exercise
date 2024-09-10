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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if (!head || !head -> next) return head;
        auto p1 = head, p2 = head -> next;
        while (p2){
            int GCD = __gcd(p1 -> val, p2 -> val);
            ListNode* pm = new ListNode(GCD);
            p1 -> next = pm;
            pm -> next = p2;
            p1 = p2;
            p2 = p2 -> next;
        }
        return head;
    }
};