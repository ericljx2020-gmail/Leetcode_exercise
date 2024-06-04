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
    ListNode* reverseList(ListNode* head) {
        vector<int> v;
        while (head){
            v.push_back(head -> val);
            head = head -> next;
        }
        ListNode* dummy = new ListNode(0);
        auto p = dummy;
        for (int i = v.size()-1; i >= 0; i--){
            p -> next = new ListNode(v[i]);
            p = p -> next;
        }
        return dummy -> next;
    }
};