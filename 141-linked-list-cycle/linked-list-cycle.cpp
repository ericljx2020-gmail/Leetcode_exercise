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
    bool hasCycle(ListNode *head) {
        auto *hh = head, *tt = head;
        while (hh){
            hh = hh -> next;
            for (int i = 0; i < 2; i++){
                if (tt) tt = tt -> next;
                else return false;
            }
            if (hh == tt) return true;
        }
        return false;
    }
};