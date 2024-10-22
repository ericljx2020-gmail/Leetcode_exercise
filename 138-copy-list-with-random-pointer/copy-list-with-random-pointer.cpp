/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* dummy = new Node(0);

        auto p = head;
        auto q = dummy;
        unordered_map<Node*, Node*> hash;
        while (p) {
            q -> next = new Node(p -> val);
            hash[p] = q->next;
            q = q -> next;
            p = p -> next;
        }
        q = dummy -> next;
        p = head;
        while (q) {
            if (p -> random)q -> random = hash[p -> random];
            q = q -> next;
            p = p -> next;
        }

        return dummy -> next;
    }
};