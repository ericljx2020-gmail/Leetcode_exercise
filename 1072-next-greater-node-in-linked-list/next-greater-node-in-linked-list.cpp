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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> v;
        while (head){
            v.push_back(head -> val);
            head = head -> next;
        }
        stack<int> stk;
        int n = v.size();
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++){
            while (stk.size() && v[i] > v[stk.top()]){
                ans[stk.top()] = v[i];
                stk.pop();
            }
            stk.push(i);
        }

        return ans;
    }
};