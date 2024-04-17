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
        auto prev = dummy;
        auto temp = head;

        while (temp && temp -> next){
            if (temp -> val == temp -> next -> val){
                int data = temp -> val;
                while (temp && temp -> val == data){
                    temp = temp -> next;
                }
                prev -> next = temp;
            }else{
                prev = temp;
                temp = temp -> next;
            }
        }

        return dummy -> next;
    }
};