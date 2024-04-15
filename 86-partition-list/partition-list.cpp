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
    ListNode* partition(ListNode* head, int x) {
        auto left = new ListNode(0), right = new ListNode(0);
        auto leftH = left, rightH = right;
        auto ptr = head;
        while (ptr) {
            if (ptr -> val < x) {
                left -> next = new ListNode(ptr -> val);
                left = left -> next;
                // cout << "left: " << ptr -> val << '\n';
            }else{
                right -> next = new ListNode(ptr -> val);
                right = right -> next;
                // cout << "right: " << ptr -> val << '\n';
            }
            ptr = ptr -> next;
        }
        
        left -> next = rightH -> next;
        return leftH -> next;
        
        
    }
};