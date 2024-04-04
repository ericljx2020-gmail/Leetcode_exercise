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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return NULL;
        auto itr = head;
        int n = 1;
        while (itr -> next){
            itr = itr -> next;
            n++;
        }
        itr -> next = head;
        k = k % n;
        // cout << n;
        int idx = 1;
        while (idx++ < n-k){
            head = head -> next;
        }
        auto res = head -> next;
        head -> next = NULL;
        return res;
    }
};