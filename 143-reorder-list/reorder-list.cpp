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
    void reorderList(ListNode* head) {
        auto p = head;
        stack<ListNode*> stk;
        while (p){
            stk.push(p);
            p = p -> next;
        }
        p = head;
        auto t = head -> next;
        int sz = stk.size();
        while (sz > 1) {
            p -> next = stk.top();
            stk.top() -> next = t;
            stk.pop();
            p = t;
            t = t -> next;
            sz -= 2;
        }
        p -> next = NULL;
        // return head;
    }
};