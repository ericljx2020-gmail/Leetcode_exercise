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
    ListNode* mergeNodes(ListNode* head) {
        auto dummy = new ListNode();
        auto d = dummy;
        int sum = 0;
        auto p = head;
        while (p){
            if (p -> val == 0 && p != head){
                d -> next = new ListNode(sum);
                d = d -> next;
                sum = 0;
            }else{
                sum += p -> val;
            }
            p = p -> next;
        }
        return dummy -> next;
    }
};