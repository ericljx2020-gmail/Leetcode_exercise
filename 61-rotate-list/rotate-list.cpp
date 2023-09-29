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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;
        ListNode* left = head;
        ListNode* right = head;
        int cnt = 1;
        while (right -> next){
            cnt++;
            right = right -> next;
        }
        k %= cnt;
        k = cnt-k;
        while (k --){
            right -> next = new ListNode(left -> val);
            right = right -> next;
            left = left -> next;
        }
        return left;
    }
};