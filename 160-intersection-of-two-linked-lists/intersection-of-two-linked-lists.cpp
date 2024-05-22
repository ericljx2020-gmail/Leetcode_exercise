/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto a = headA, b = headB;
        unordered_map<ListNode*, bool> hash;
        while (a || b) {
            if (a){
                if (hash[a]) return a;
                hash[a] = 1;
                a = a -> next;
            }
            if (b) {
                if (hash[b]) return b;
                hash[b] = 1;
                b = b -> next;
            }
        }
        return NULL;
    }
};