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
        auto dummy = new ListNode(0);
        auto p = dummy;
        unordered_map<int, vector<ListNode*>> hash;
        priority_queue<int, vector<int>, greater<int>> heap;
        for (auto node : lists) {
            if (!node) continue;
            heap.push(node -> val);
            hash[node -> val].push_back(node);
        }

        while (heap.size()){
            auto t = heap.top();
            heap.pop();

            auto q = hash[t][hash[t].size()-1];
            hash[t].pop_back();
            p -> next = q;
            p = p -> next;
            q = q -> next;
            if (q) {
                hash[q->val].push_back(q);
                heap.push(q -> val);
            }
        }
        return dummy -> next;
    }
};