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
        int n = lists.size();
        unordered_map<int, vector<ListNode*>> hash;
        int minv = INT_MAX;
        int maxv = INT_MIN;
        for (int i = 0; i < n; i++){
            auto p = lists[i];
            if (!p) continue;
            hash[p->val].push_back(p);
            minv = min(minv, p -> val);
            maxv = max(maxv, p -> val);
        }

        // for (auto c: hash){
        //     cout << c.first << "\n";
        //     for (auto a : c.second){
        //         cout << a -> val << ' ';
        //     }
        //     puts("");
        // }


        auto dum = new ListNode(0);
        auto ptr = dum;
        for (int i = minv; i <= 1e4; i++){
            for (int j = 0; j < hash[i].size(); j++){
                ptr -> next = hash[i][j];
                ptr = ptr -> next;
                if (ptr -> next) hash[ptr -> next -> val].push_back(ptr -> next);
            }
            hash[i].clear();
        }
        return dum -> next;
        return {};
    }
};