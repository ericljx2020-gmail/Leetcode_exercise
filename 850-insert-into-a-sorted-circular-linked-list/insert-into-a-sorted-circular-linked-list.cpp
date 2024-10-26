/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (!head) {
            head = new Node(insertVal);
            head -> next = head;
            return head;
        }
        bool inserted = false;
        auto prev = head;
        auto next = head -> next;
        while (true){
            if ((prev -> val <= insertVal && insertVal <= next->val) || 
                (prev -> val > next -> val && insertVal < next -> val) ||
                (prev -> val > next -> val && insertVal > prev -> val)){
                    prev -> next = new Node(insertVal, next);
                    inserted = true;
                    break;
                }
            prev = prev -> next;
            next = next -> next;
            if (prev == head) break;
        }

        if (!inserted) {
            prev->next = new Node(insertVal, next);
        }

        return head;
    }

};