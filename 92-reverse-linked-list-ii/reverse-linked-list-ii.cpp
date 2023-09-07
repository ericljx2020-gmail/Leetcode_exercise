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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* tmp = head;
        vector<int> v;
        while (tmp){
            v.push_back(tmp -> val);
            tmp = tmp -> next;
        }

        while (left < right){
            swap(v[left-1], v[right-1]);
            left++;
            right--;
        }

        tmp = head;
        for (int i = 0; i < v.size(); i++){
            tmp -> val = v[i];
            tmp = tmp -> next;
        }
        return head;
    }
};