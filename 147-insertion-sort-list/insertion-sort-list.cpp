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
    static bool cmp(ListNode* a, ListNode* b) {
        return a -> val < b -> val;
    } 

    ListNode* insertionSortList(ListNode* head) {
        auto p = head;
        vector<ListNode*> v;
        while(p) {
            v.push_back(p);
            p = p -> next;
        }

        sort(v.begin(), v.end(), cmp);
        auto Dummy = new ListNode(-1);
        p = Dummy;
        for (auto t : v) {
            p -> next = t;
            p = p -> next;
        }
        p -> next = NULL;
        return Dummy -> next;
    }
};