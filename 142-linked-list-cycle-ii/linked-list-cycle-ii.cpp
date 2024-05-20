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
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*, bool> hash;
        auto p = head;
        while (p) {
            if (hash[p]) return p;
            hash[p] = 1;
            p = p -> next;
        }
        return NULL;
    }
};