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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        auto w = head;
        while (w){
            n++;
            w = w -> next;
        }
        vector<ListNode*> res;
        int size = n / k;
        int residual = n % k;
        auto cur = head;
        auto prev = head;
        for (int i = 0; i < k; i++){
            int sz = size + (residual-- > 0);
            auto curhead = cur;
            while (sz--){
                prev = cur;
                cur = cur -> next;
            }

            if (prev){
                prev -> next = NULL;
            }
            res.push_back(curhead);

        }
        return res;
    }
};