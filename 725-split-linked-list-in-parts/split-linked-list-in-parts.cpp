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
        vector<ListNode*> res;
        ListNode* pt = head;
        while (pt) {
            n++;
            pt = pt -> next;
        }
        ListNode* rt = head, *lt = head;
        for (int i = 1; i <= k; i++){
            int l = n / k;
            if (i <= n % k) l++;
            while (l-1 > 0){
                rt = rt -> next;
                l--;
            }
            if (rt){
                cout << rt -> val << endl;
                ListNode* tmp = rt;
                rt = rt -> next;
                tmp -> next = nullptr;
                res.push_back(lt);
                lt = rt;
            }else{
                res.push_back({});
            }
        }
        return res;
    }
};