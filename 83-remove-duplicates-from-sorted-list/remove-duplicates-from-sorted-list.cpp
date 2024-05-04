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
    ListNode* deleteDuplicates(ListNode* head) {
        auto front = head, back = head;
        while (back){
            int cur = front -> val;
            while (back && back -> val == cur){
                back = back -> next;
            }
            front -> next = back;
            front = back;
        }

        return head;
    }
};