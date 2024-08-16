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
    ListNode* deleteMiddle(ListNode* head) {
        if (head && !head -> next) return nullptr;
        auto p2 = head;
        auto p1 = head;
        while (p2){
            if (!p2 -> next) {
                p1 -> next = p1 -> next -> next;
                break;
            }
            p2 = p2 -> next;
            if (!p2 -> next) {
                p1 -> next = p1 -> next -> next;
                break;
            }
            p2 = p2 -> next;
            if (!p2 -> next) {
                p1 -> next = p1 -> next -> next;
                break;
            }
            p1 = p1 -> next;
        }
        return head;
    }
};