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
        auto dummy = new ListNode(0);
        dummy -> next = head;
        auto slow = dummy;
        auto fast = head;

        while (fast && fast -> next) {
            if (fast -> val == fast -> next -> val){
                int col = fast -> val;
                while (fast && fast -> val == col){
                    fast = fast -> next;
                }
                slow -> next = fast;
            }else{
                slow = fast;
                fast = fast -> next;
            }
        }
        return dummy -> next;
    }
};