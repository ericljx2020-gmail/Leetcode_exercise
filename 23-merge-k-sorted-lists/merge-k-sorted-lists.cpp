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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        unordered_map<int, vector<ListNode*>> hash;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto l : lists){
            if(l) {
                pq.push(l -> val);
                hash[l -> val].push_back(l);
            }
        }
        ListNode* dummy = new ListNode(0);
        auto p = dummy;
        while (pq.size()){
            auto t = pq.top();
            pq.pop();
            auto v = hash[t][hash[t].size()-1];     // the last linkedlist with head -> val == t;
            hash[t].pop_back();
            p -> next = v;
            p = p -> next;
            v = v -> next;
            if (v) {
                hash[v -> val].push_back(v);
                pq.push(v -> val);
            }
        }
        return dummy -> next;
    }
};